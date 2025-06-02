#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
#define PB push_back
#define PH push
#define REP(i, N) for (int i = 0; i < N; ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef pair<int, int> pii;

template <typename T> using V = vector<T>;
void solve() {
    int N;
    ll Wlimit;
    if (!(cin >> N >> Wlimit))
        return;
    if (N == 0) {
        cout << 0 << "\n";
        return;
    }
    V<ll> H(N), wt(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    for (int i = 0; i < N; i++)
        cin >> wt[i];
    const ll INF = (ll)4e18;
    vector<vector<ll>> dp(N, vector<ll>(N + 1, INF));
    for (int i = 0; i < N; i++) {
        dp[i][1] = wt[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (H[j] < H[i]) {
                int maxL = i + 1;
                if (maxL > N)
                    maxL = N;
                for (int l = 2; l <= maxL; l++) {
                    if (dp[j][l - 1] + wt[i] < dp[i][l]) {
                        dp[i][l] = dp[j][l - 1] + wt[i];
                    }
                }
            }
        }
    }
    int answer = 0;
    for (int l = N; l >= 1; l--) {
        bool ok = false;
        for (int i = 0; i < N; i++) {
            if (dp[i][l] <= Wlimit) {
                ok = true;
                break;
            }
        }
        if (ok) {
            answer = l;
            break;
        }
    }
    cout << answer << "\n";
}

int main() {
    int T = 1;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    while (T--)
        solve();
}
