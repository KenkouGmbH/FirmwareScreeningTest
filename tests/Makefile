#  ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-
# Project: screeningTestExample
# File: MakeFile - for unit tests
# Author: Kyle Krueger
# Date: 1.06.18
#  ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~~-~

PROJ_NAME  := tests
PROJ_DIR      := ../
TESTS_DIR     := $(PROJ_DIR)/tests
UNITY_ROOT    := $(TESTS_DIR)/Unity
OUT_DIR       := $(TESTS_DIR)/out
CC = gcc

TARGET_BASE := $(OUT_DIR)/tests

# Detect the OS
ifeq ($(OSTYPE),cygwin)
	CLEANUP =  rm -f $(OUT_DIR)/*.out $(OUT_DIR)/$(PROJ_NAME)_Runner.c
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
elseifeq ($(OSTYPE), msys)
	CLEANUP =  rm -f $(OUT_DIR)/*.out $(OUT_DIR)/$(PROJ_NAME)_Runner.c
	MKDIR = mkdir -p
	TARGET_EXTENSION=.exe
elseifeq ($(OSTYPE),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP =  rm -f $(OUT_DIR)/*.out $(OUT_DIR)/$(PROJ_NAME)_Runner.c
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

TARGETS := $(TARGET_BASE)$(TARGET_EXTENSION)

CFLAGS +=
CFLAGS +=  -I. 
CFLAGS +=  --pedantic 
CFLAGS +=  -Wall 

SRC_FILES += \
  $(PROJ_DIR)/src/kenkou_triple_tap.c \
  $(TESTS_DIR)/src/tests.c \
  $(OUT_DIR)/$(PROJ_NAME)_Runner.c \
  $(UNITY_ROOT)/src/unity.c \

INCLUDE += -I$(UNITY_ROOT)/src -I$(PROJ_DIR)/include -I$(TESTS_DIR)/include
SYMBOLS=-DTEST

all: clean default

default:
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $(TESTS_DIR)/src/$(PROJ_NAME).c $(OUT_DIR)/$(PROJ_NAME)_Runner.c

	$(CC) $(CFLAGS) $(INCLUDE) $(SYMBOLS) $(SRC_FILES) -o $(TARGETS)

	./$(TARGETS)

debug:
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb $(TESTS_DIR)/src/$(PROJ_NAME).c $(OUT_DIR)/$(PROJ_NAME)_Runner.c

	$(CC) $(CFLAGS) -g $(INCLUDE) $(SYMBOLS) $(SRC_FILES) -o $(TARGETS)

	gdb $(TARGETS)

clean:
	$(CLEANUP)


