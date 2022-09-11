#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i += 1) {
        cin >> A[i];
    }

    atcoder::segtree<int, op, e> seg(A);
    for (int i = 0; i < Q; i += 1) {
        int T;
        cin >> T;
        if (T == 1) {
            int X, V;
            cin >> X >> V;
            seg.set(X - 1, V);
        } else if (T == 2) {
            int L, R;
            cin >> L >> R;
            cout << seg.prod(L - 1, R) << endl;
        } else {
            int X, V;
            cin >> X >> V;
            auto f = [&](int x) { return x < V; };
            cout << seg.max_right<decltype(f)>(X - 1, f) + 1 << endl;
        }
    }
    return 0;
}