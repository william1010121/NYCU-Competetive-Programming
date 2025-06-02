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

const ll MOD = 1'000'000'007LL;

pair<ll, ll> fib(ll n) {
    if (n == 0)
        return {0, 1};
    auto p = fib(n >> 1);
    ll a = p.F;                                                       // F(k)
    ll b = p.S;                                                       // F(k+1)
    ll c = ((__int128)a * ((2 * b % MOD - a + MOD) % MOD)) % MOD;     // F(2k)
    ll d = (((__int128)a * a) % MOD + ((__int128)b * b) % MOD) % MOD; // F(2k+1)
    if (n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}

void solve() {
    long long N;
    if (!(cin >> N))
        return;

    // Answer is F(N+2) - 1  (sum_{i=1}^{N} F(i))
    ll FN2 = fib(N + 2).F;
    ll ans = (FN2 - 1 + MOD) % MOD;
    cout << ans << '\n';
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
