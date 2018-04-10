CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-sign-compare -O2 -g

all: %
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp
