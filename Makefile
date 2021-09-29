CC=gcc
CXX=g++
RM=rm -f
#CPPFLAGS=-g $(shell  --cflags)
#LDFLAGS=-g $(shell  --ldflags)
#LDLIBS=$(shell  --libs)
CXXFLAGS=-I"/usr/lib/jvm/java-8-openjdk-amd64/include" -I"/usr/lib/jvm/java-8-openjdk-amd64/include/linux"
LDFLAGS=-ljvm

LDLIBS= -L"/usr/bin/java" -L"/usr/lib/jvm/java-8-openjdk-amd64/bin/java" -L"/usr/lib/jvm/java-8-openjdk-amd64/jre/bin"

SRCS=native.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

#all: native 

#native: native.cpp
#$(CXX) $(LDFLAGS) -o native $(OBJS) $(LDLIBS)
#	$(CXX) $(CPPFLAGS) $(LDLIBS) -o native native.cpp -ljvm

#native.o: native.cpp 

#all: native.cpp
	#g++ $(CXXFLAGS) -c -o native.o native.cpp
	#g++ $(LDLIBS) native.o -ljvm





all:native.cpp
	g++ -I"/usr/lib/jvm/java-11-openjdk-amd64/include" -I"/usr/lib/jvm/java-11-openjdk-amd64/include/linux" -o native -L"/usr/lib" -L"/lib" -L"/usr/lib/jvm/java-11-openjdk-amd64/lib" -L"/usr/lib/jvm/java-11-openjdk-amd64/lib/server" native.cpp -ljvm

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) native 
