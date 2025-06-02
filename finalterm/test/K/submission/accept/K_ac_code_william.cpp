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

void solve() {
    int n;
    ll k;
    if (!(cin >> n >> k))
        return;
    V<ll> a(n + 1);
    FOR(i, 1, n) cin >> a[i];

    V<int> deg(n + 1, 0);
    REP(i, n - 1) {
        int u, v;
        cin >> u >> v;
        ++deg[u];
        ++deg[v];
    }

    ll sumLeaf = 0;
    int leafCnt = 0;
    ll minLeaf = LLONG_MAX;
    ll minInternal = LLONG_MAX;

    FOR(i, 1, n) {
        if (n == 1 || deg[i] == 1) {
            ++leafCnt;
            sumLeaf += a[i];
            minLeaf = min(minLeaf, a[i]);
        } else {
            minInternal = min(minInternal, a[i]);
        }
    }

    ll ans;
    if (leafCnt % 2 == 0) {
        ans = sumLeaf;
    } else {
        ll optionA = (k - 1) * minLeaf;
        ll optionB = minInternal;
        ans = sumLeaf + min(optionA, optionB);
    }
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
