#
# Makefile framework for CptS223
#
# Hacked up by Aaron Crandall, 2017
#

# Variables
GPP     = g++
CFLAGS  = -g -std=c++11 #-static
RM      = rm -f
BINNAME = Robotic-SaLSA
LIBS	= -lboost_system -lboost_thread -lcreate
INCLUDE = include/
# Shell gives make a full user environment
# Adding this to PATH will find the newer g++ compiler on the EECS servers.
SHELL := /bin/bash
PATH := /opt/rh/devtoolset-3/root/usr/bin/:$(PATH)



salsa-debug:
	$(GPP) $(CFLAGS) -I$(INCLUDE) -o salsa-debug main.cpp $(LIBS)

salsa:
	$(GPP) $(CFLAGS) -I$(INCLUDE) -o salsa main.cpp $(LIBS)

salsa-pi:
	arm-linux-gnueabihf-g++ $(CFLAGS) -I$(INCLUDE)  -Wall -c -o salsa-pi main.cpp $(LIBS) -static

# Default is what happenes when you call make with no options
#  In this case, it requires that 'all' is completed
default: all

# All is the normal default for most Makefiles
#  In this case, it requires that build is completed
all: build

# build depends upon *.cpp, then runs the command:
#  g++ -g -std=c++11 -o bigFiveList
build: main.cpp
	$(GPP) $(CFLAGS) -I$(INCLUDE) -o $(BINNAME) main.cpp $(LIBS)

run: build
	./$(BINNAME)


# If you call "make clean" it will remove the built program
#  rm -f HelloWorld
clean veryclean:
	$(RM) $(BINNAME)
