#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> vc(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> vc[i];
    }
    while (Q--) {
        int md;
        cin >> md;
        if (md == 1) {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= r; ++i) {
                vc[i] = floor(sqrt(vc[i]));
            }
        } else {
            int pos;
            cin >> pos;
            cout << vc[pos] << '\n';
        }
    }
}
