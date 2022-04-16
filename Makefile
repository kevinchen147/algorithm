.PHONY: a k l d

a: acwing
	./acwing < input > output && cat output

acwing: acwing.cpp
	g++ -o acwing acwing.cpp -std=c++17 -O3

k: kickstart
	./kickstart < input > output && cat output

kickstart: kickstart.cpp
	g++ -o kickstart kickstart.cpp -std=c++17 -O3

l: leetcode
	./leetcode < input > output && cat output

leetcode: leetcode.cpp
	g++ -o leetcode leetcode.cpp -std=c++17 -O3

d:
	diff output answer -y
