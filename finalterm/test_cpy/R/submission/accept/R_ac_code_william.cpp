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
    ll C;
    cin >> N >> C;
    vector<ll> w(N), v(N);
    REP(i, N) { cin >> w[i] >> v[i]; }
    int mid = N / 2;
    int n1 = mid;
    int n2 = N - mid;
    vector<pair<ll, ll>> A;
    A.reserve(1 << n1);
    REP(mask, 1 << n1) {
        ll sum_w = 0, sum_v = 0;
        REP(i, n1) {
            if (mask & (1 << i)) {
                sum_w += w[i];
                sum_v += v[i];
            }
        }
        if (sum_w <= C) {
            A.emplace_back(sum_w, sum_v);
        }
    }
    sort(A.begin(), A.end());
    vector<pair<ll, ll>> A2;
    A2.reserve(A.size());
    ll max_v = -1;
    for (auto &p : A) {
        if (p.S > max_v) {
            A2.emplace_back(p);
            max_v = p.S;
        }
    }
    ll answer = 0;
    REP(mask, 1 << n2) {
        ll sum_w2 = 0, sum_v2 = 0;
        REP(i, n2) {
            if (mask & (1 << i)) {
                sum_w2 += w[mid + i];
                sum_v2 += v[mid + i];
            }
        }
        if (sum_w2 > C)
            continue;
        ll rem = C - sum_w2;
        ll bestA = 0;
        int l = 0, h = (int)A2.size() - 1;
        while (l <= h) {
            int m = (l + h) >> 1;
            if (A2[m].F <= rem) {
                bestA = A2[m].S;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        answer = max(answer, sum_v2 + bestA);
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
