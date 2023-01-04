#include <bits/stdc++.h>

/**
 * Return primes <= n
 */
std::vector<int> get_primes(int n) {
    std::vector<bool> is_prime(n + 1, true);
    std::vector<int> primes;
    for (int i = 2; i <= n; i += 1) {
        if (is_prime[i]) primes.emplace_back(i);
        for (int& prime : primes) {
            if (1LL * prime * i > n) break;
            is_prime[prime * i] = false;
            if (i % prime == 0) break;
        }
    }
    return primes;
}
