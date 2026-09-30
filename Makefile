ARM7_SELECTED = ARM7_MP3_DSWIFI
USE_NITROFS  = YES
NITRODATA   := nitrofiles
TEXT1        := NewProject
TEXT2        := 
TEXT3        := 
TARGET       := $(shell basename $(CURDIR))
BUILD        := build
SOURCES      := source data gfx/bin
INCLUDES     := include build data gfx
RELEASEPATH  := 
MAKEFILE_VER := ver2
include C:\devkitPro\PAlib\lib\PA_Makefile
