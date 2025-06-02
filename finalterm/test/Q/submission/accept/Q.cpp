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
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    REP(i, n) cin >> x[i];
    REP(i, n) cin >> r[i];
    int maxR = 0;
    REP(i, n) if (r[i] > maxR) maxR = r[i];

    vector<vector<pii>> intervals_by_y(maxR + 1);

    REP(i, n) {
        int xi = x[i];
        int ri = r[i];
        ll rll = (ll)ri;
        for (int y = 0; y <= ri; y++) {
            ll yll = (ll)y;
            ll d = rll * rll - yll * yll; // ≥ 0
            int dx = (int)floor(sqrt((double)d));
            // Correct potential floating‐point error:
            while ((ll)(dx + 1) * (dx + 1) <= d)
                dx++;
            while ((ll)dx * dx > d)
                dx--;
            int left = xi - dx;
            int right = xi + dx;
            intervals_by_y[y].emplace_back(left, right);
        }
    }

    ll total = 0;
    // For each y ≥ 0, merge the intervals and count how many integer x are
    // covered. At y=0, count once; for y>0, each covered x contributes two
    // points (±y).
    for (int y = 0; y <= maxR; y++) {
        auto &Vint = intervals_by_y[y];
        if (Vint.empty())
            continue;
        sort(Vint.begin(), Vint.end());
        ll cnt_y = 0;
        int curL = Vint[0].first, curR = Vint[0].second;
        for (int j = 1; j < (int)Vint.size(); j++) {
            int l = Vint[j].first, rgt = Vint[j].second;
            if (l > curR + 1) {
                cnt_y += (ll)curR - curL + 1;
                curL = l;
                curR = rgt;
            } else {
                if (rgt > curR)
                    curR = rgt;
            }
        }
        cnt_y += (ll)curR - curL + 1;
        if (y == 0)
            total += cnt_y;
        else
            total += 2 * cnt_y;
    }

    cout << total << "\n";
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
