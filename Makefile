#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple Use of MakeFile
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <FILE>.o Builds <FILE>.o object file
#	<FILE>.i Builds <FILE>.i Preprocesssor file
#	<FILE>.asm Builds <FILE>.asm Assembly file
#	<FILE>.d Builds <FILE>.d Dependency file
#	build -Builds and links all source files
#	all -Builds and links all source files
#	CLEAN -Removes all generated Files
#	Compile-all -Builds and without links all source files
#
# Platform Overrides:
#	PLATFORM (HOST,MSP432)
#	CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      	ARCH - ARM Architecture (arm, thumb)
#      	SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Architectures Specific Flags & VARIABLES
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
TARGET = c1m2

#---------------------------------------------------------------------------------
#The If Here To choose which gcc(TOOlChain) to use depend on the Platform

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = -Werror -std=c99 -DHOST
else
	CC = arm-none-eabi-gcc
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall  -DMSP432
endif
#---------------------------------------------------------------------------------
#CHOOSE THE FILES That will be PASS TO THE COMPILER

ifeq ($(PLATFORM),HOST)
	OBJS = $(SRCS_HOST)
else
	OBJS = $(SRCS_mps432p401r)
endif
#-----------------------------------------------------------------------------------

#Generate Preprocessor File output of C-program
%.i: %.c
	$(CC) -E $< $(CFLAGS) -o $@

#Generate Assemble File output of C-program
%.asm: %.c
	$(CC) -S $< $(CFLAGS) -o $@

#Generate Object File output of C-program
%.o: %.c                                                              
	$(CC) -c $< $(CFLAGS) -o $@

#Generate Dependency File output of C-program
%.d: %.c
	$(CC) -MM $< $(CFLAGS) -o $@

#-----------------------------------------------------------------------------------

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: compile-all
compile-all: $(OBJS:.c=.o)

#CHOOSE THE FLAGS DEPENDS ON WHICH PLATFORM IS USED
ifeq ($(PLATFORM),HOST)
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS)  -o $@
else
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS)  -o $@  
endif

#-----------------------------------------------------------------------------------
#CLEAN IS USED TO REMOVE ALL THE GENERATED FILES
.PHONY: CLEAN
CLEAN:
	rm -f  $(TARGET).out $(TARGET).map *.asm *.i *.o *.d
#-----------------------------------------------------------------------------------
