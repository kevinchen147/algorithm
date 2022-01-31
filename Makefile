cpp:
	g++ -o kickstart kickstart.cpp -std=c++17 -O3 && ./kickstart < input.txt

py:
	cat input.txt | python3 kickstart.py
