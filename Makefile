CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -DXXGJ_DEBUG -I ./ac-library

.PHONY: lc
lc: leetcode
	./leetcode < input > output && cat output

leetcode: leetcode.cpp

.PHONY: lc+
lc+:
	cd ./ac-library && ./expander.py -c ../leetcode.cpp > ./combined.out && code ./combined.out

.PHONY: ac
ac: atcoder
	./atcoder < input > output && cat output

atcoder: atcoder.cpp

.PHONY: ac+
ac+:
	cd ./ac-library && ./expander.py -c ../atcoder.cpp > ./combined.out && code ./combined.out

.PHONY: ks
ks: kickstart
	./kickstart < input > output && cat output

kickstart: kickstart.cpp

.PHONY: ks+
ks+:
	cd ./ac-library && ./expander.py -c ../kickstart.cpp > ./combined.out && code ./combined.out

.PHONY: diff
diff:
	diff output answer -y
