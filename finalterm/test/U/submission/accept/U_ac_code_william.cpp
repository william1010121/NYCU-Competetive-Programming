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
    cin >> N;
    V<ll> A(N);
    REP(i, N) { cin >> A[i]; }
    if (N % 2 == 0) {
        ll sum0 = 0, sum1 = 0;
        REP(i, N) {
            if (i % 2 == 0)
                sum0 += A[i];
            else
                sum1 += A[i];
        }
        cout << max(sum0, sum1);
        return;
    }
    int m = N / 2; // floor(N/2)
    // Build D[t] = A[(2*t) % N]
    V<ll> D(N);
    REP(t, N) { D[t] = A[(2 * t) % N]; }
    V<ll> D2(2 * N);
    REP(i, 2 * N) { D2[i] = D[i % N]; }
    V<ll> P(2 * N + 1, 0);
    REP(i, 2 * N) { P[i + 1] = P[i] + D2[i]; }
    ll ans = LLONG_MIN;
    REP(i, N) {
        ll cur = P[i + m] - P[i];
        ans = max(ans, cur);
    }
    cout << ans;
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
    return 0;
}
