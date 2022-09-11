#include <bits/stdc++.h>
using namespace std;

#ifdef KEVIN_DEBUG
#include "debug.h"
#else
#define dbg(...)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;

    function<void(int)> run_case = [](int test_case) {
        cout << "Case #" << test_case << ": " << '\n';
    };

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}