CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -DKEVIN_DEBUG -I ./ac-library

.PHONY: ac
ac: atcoder
	./atcoder < input > output && cat output

atcoder: atcoder.cpp

.PHONY: kscpp
kscpp: kickstart
	./kickstart < input > output && cat output

kickstart: kickstart.cpp

.PHONY: kspy
kspy: kickstart.py
	python3 ./kickstart.py < input  > output && cat output

.PHONY: diff
diff:
	diff output answer -y

.PHONY: ks+
ks+:
	./ac-library/expander.py -c ./kickstart.cpp > ./combined.out && code ./combined.out

.PHONY: lc+
lc+:
	./ac-library/expander.py -c ./leetcode.cpp > ./combined.out && code ./combined.out