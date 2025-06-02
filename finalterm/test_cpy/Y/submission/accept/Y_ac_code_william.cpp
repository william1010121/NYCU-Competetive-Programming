#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
#define PB push_back
#define PH push
#define REP(i, N) for (int i = 0; i < (N); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef pair<int, int> pii;

template <typename T> using V = vector<T>;

const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    V<ll> a(n);
    ll total = 0;
    REP(i, n) {
        cin >> a[i];
        total += a[i];
    }
    if (total % k != 0) {
        cout << 0 << "\n";
        return;
    }
    ll T = total / k;
    V<ll> targets(k + 1, 0);
    FOR(j, 1, k) { targets[j] = targets[j - 1] + T; }
    V<int> sum_dp(k + 1, 0);
    sum_dp[0] = 1; // dp[0][0] = 1, prefix of length 0 has sum 0.

    ll prefix = 0;
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        prefix += a[i - 1];
        static int dp_curr[101];
        for (int j = 1; j <= k; ++j) {
            dp_curr[j] = 0;
        }
        for (int j = k; j >= 1; --j) {
            if (prefix == targets[j]) {
                // We can end the j-th segment here if prefix == j * T
                dp_curr[j] = sum_dp[j - 1];
            }
        }
        if (i == n) {
            answer = dp_curr[k];
        }
        for (int j = 1; j <= k; ++j) {
            if (prefix == targets[j]) {
                sum_dp[j] = (sum_dp[j] + dp_curr[j]) % MOD;
            }
        }
    }

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
