CC=gcc
CXX=g++
RM=rm -f
#CPPFLAGS=-g $(shell  --cflags)
#LDFLAGS=-g $(shell  --ldflags)
#LDLIBS=$(shell  --libs)
CPPFLAGS=-fPIC -I/usr/lib/jvm/java-11-openjdk-amd64/include -I/usr/lib/jvm/java-11-openjdk-amd64/include/linux
LDFLAGS=-ljvm
LDLIBS=-L/usr/bin/java

SRCS=native.cpp
OBJS=$(subst .ccp,.o,$(SRCS))

all: native 

native: $(OBJS)
#$(CXX) $(LDFLAGS) -o native $(OBJS) $(LDLIBS)
	$(CXX) $(CPPFLAGS) $(LDLIBS) -o native $(OBJS) $(LDFLAGS)

native.o: native.cpp 

#support.o: support.hh support.cc

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) native 
