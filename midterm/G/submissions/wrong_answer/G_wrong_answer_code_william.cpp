#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vc(N);
    for (auto &i : vc)
        cin >> i;
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < 32; ++i) {
        int cnt = 0;
        for (auto &j : vc)
            cnt += (j + K - 1) / K;
        ans = min(ans, cnt + i);

        for (auto &j : vc)
            j /= 2;
    }
    cout << ans << '\n';
}
