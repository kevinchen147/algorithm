a:
	g++ -o acwing acwing.cpp -std=c++17 -O3 && ./acwing < input > output && cat output

k:
	g++ -o kickstart kickstart.cpp -std=c++17 -O3 && ./kickstart < input > output && cat output

l:
	g++ -o leetcode leetcode.cpp -std=c++17 -O3 && ./leetcode < input > output && cat output

d:
	diff output answer -y
