k:
	g++ -o kickstart kickstart.cpp -std=c++17 -O3 && ./kickstart < input > output

l:
	g++ -o leetcode leetcode.cpp -std=c++17 -O3 && ./leetcode < input > output

d:
	diff output answer -y
