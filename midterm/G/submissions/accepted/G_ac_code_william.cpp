#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vc(N);
    for (auto &i : vc)
        cin >> i;
    if (K == 0) {
        for (int i = 0; i < 32; ++i) {
            int cnt =
                count_if(begin(vc), end(vc), [&](int a) { return a != 0; });
            if (cnt == 0) {
                cout << i << '\n';
                return 0;
            }
            for (auto &j : vc)
                j /= 2;
        }
    }
    long long ans = numeric_limits<long long>::max();
    for (int i = 0; i < 32; ++i) {
        long long cnt = 0;
        for (auto &j : vc)
            cnt += (j + K - 1) / K;
        ans = min(ans, cnt + i);

        for (auto &j : vc)
            j /= 2;
    }
    cout << ans << '\n';
}
