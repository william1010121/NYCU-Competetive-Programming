#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> vc(N + 1);
    map<int, int> mp;
    for (int i = 1; i <= N; ++i) {
        cin >> vc[i];
        mp[i] = vc[i];
    }
    while (Q--) {
        int md;
        cin >> md;
        if (md == 1) {
            int l, r;
            cin >> l >> r;
            auto fd = mp.lower_bound(l);
            while (fd != mp.end() && fd->first <= r) {
                fd->second = floor(sqrt(fd->second));
                vc[fd->first] = fd->second;
                auto rm = fd;
                fd++;
                if (rm->second <= 1)
                    mp.erase(rm);
            }
        } else {
            int pos;
            cin >> pos;
            cout << vc[pos] << '\n';
        }
    }
}
