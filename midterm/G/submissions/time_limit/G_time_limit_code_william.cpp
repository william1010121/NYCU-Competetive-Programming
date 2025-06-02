#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vc(N);
    for (auto &i : vc)
        cin >> i;
    if (K == 0) {
        int cnt = 0;
        while (vc.back() != 0) {
            vc.back() /= 2;
            cnt++;
        }
        cout << cnt << '\n';
        return 0;
    }

    sort(begin(vc), end(vc));
    long long ans = numeric_limits<long long>::max();
    {
        long long cnt = 0;
        for (auto &i : vc) {
            cnt += (i + K - 1) / K;
        }
        ans = min(ans, cnt);
    }
    for (int i = 0; i < N; ++i) {
        auto tmp = vc;
        long long cnt = 0;
        while (tmp[i] != 0) {
            ++cnt;
            for (auto &j : tmp)
                j /= 2;
            long long tmpcnt = cnt;
            for (auto &j : tmp)
                tmpcnt += (j + K - 1) / K;
            ans = min(tmpcnt, ans);
        }
    }
    cout << ans << '\n';
}
