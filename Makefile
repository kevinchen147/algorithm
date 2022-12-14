CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -DXXGJ_DEBUG -I ./ac-library

.PHONY: ac
ac: atcoder
	./atcoder < input > output && cat output

atcoder: atcoder.cpp

.PHONY: ks
ks: kickstart
	./kickstart < input > output && cat output

kickstart: kickstart.cpp

.PHONY: diff
diff:
	diff output answer -y

.PHONY: ks+
ks+:
	cd ./ac-library && ./expander.py -c ../kickstart.cpp > ./combined.out && code ./combined.out

.PHONY: ac+
ac+:
	cd ./ac-library && ./expander.py -c ../atcoder.cpp > ./combined.out && code ./combined.out