#include <bits/stdc++.h>

#ifdef XXGJ_DEBUG
#include "debug.h"
#else
#define dbg(...)
#endif

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    std::cin >> tests;

    std::function<void(int)> run_case = [](int test_case) {
        std::cout << "Case #" << test_case << ": " << '\n';
    };

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        std::cout << std::flush;
    }
}
