CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -DXXGJ_DEBUG -I ./ac-library

.PHONY: lc
lc: leetcode
	./leetcode < input | tee output

.PHONY: lc+
lc+:
	cd ./ac-library && ./expander.py -c ../leetcode.cpp | xclip -sel c

.PHONY: ac
ac: atcoder
	./atcoder < input | tee output

.PHONY: ac+
ac+:
	cd ./ac-library && ./expander.py -c ../atcoder.cpp | xclip -sel c

.PHONY: ks
ks: kickstart
	./kickstart < input | tee output

.PHONY: ks+
ks+:
	cd ./ac-library && ./expander.py -c ../kickstart.cpp | xclip -sel c

.PHONY: diff
diff:
	nvim -d output answer
