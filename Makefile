.PHONY: a k l d

CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion

a: acwing
	./acwing < input > output && cat output

acwing: acwing.cpp

k: kickstart
	./kickstart < input > output && cat output

kickstart: kickstart.cpp

l: leetcode
	./leetcode < input > output && cat output

leetcode: leetcode.cpp

d:
	diff output answer -y
