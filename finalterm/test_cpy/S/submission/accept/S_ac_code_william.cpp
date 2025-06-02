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

const ll MOD = 1'000'000'007LL;
const ll INV2 = (MOD + 1) / 2;

struct Point {
    ll x, y;
    bool operator<(const Point &o) const {
        return x == o.x ? y < o.y : x < o.x;
    }
};

ll cross(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

struct BIT {
    int n;
    V<ll> cnt, sumX, sumY;
    void init(int _n) {
        n = _n;
        cnt.assign(n + 2, 0);
        sumX.assign(n + 2, 0);
        sumY.assign(n + 2, 0);
    }
    void add(int idx, ll dc, ll dx, ll dy) {
        for (; idx <= n; idx += idx & -idx) {
            cnt[idx] += dc;
            sumX[idx] = (sumX[idx] + dx) % MOD;
            sumY[idx] = (sumY[idx] + dy) % MOD;
        }
    }
    tuple<ll, ll, ll> query(int idx) const {
        ll c = 0, sx = 0, sy = 0;
        for (; idx > 0; idx -= idx & -idx) {
            c += cnt[idx];
            sx = (sx + sumX[idx]) % MOD;
            sy = (sy + sumY[idx]) % MOD;
        }
        return {c, sx, sy};
    }
};

ll mul(ll a, ll b) { return (ll)((__int128)a * b % MOD); }

void solve() {
    int N;
    cin >> N;
    V<Point> pts(N);
    REP(i, N) cin >> pts[i].x >> pts[i].y;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end(),
                     [](Point a, Point b) { return a.x == b.x && a.y == b.y; }),
              pts.end());

    V<Point> upper;
    for (auto &p : pts) {
        while (SZ(upper) >= 2 &&
               cross(upper[SZ(upper) - 2], upper.back(), p) > 0)
            upper.pop_back();
        upper.PB(p);
    }
    int K = SZ(upper);

    V<ll> ys;
    for (auto &p : upper)
        ys.PB(p.y);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    auto getYid = [&](ll y) {
        return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
    };
    int Mny = SZ(ys);

    V<ll> cntL(K), sumLX(K), sumLY(K);
    BIT bit;
    bit.init(Mny);
    REP(j, K) {
        int yid = getYid(upper[j].y);
        auto [c, sx, sy] = bit.query(yid - 1);
        cntL[j] = c;
        sumLX[j] = sx;
        sumLY[j] = sy;
        ll xmod = ((upper[j].x % MOD) + MOD) % MOD;
        ll ymod = ((upper[j].y % MOD) + MOD) % MOD;
        bit.add(yid, 1, xmod, ymod);
    }

    V<ll> cntR(K), sumRX(K), sumRY(K);
    bit.init(Mny);
    for (int j = K - 1; j >= 0; --j) {
        int yid = getYid(upper[j].y);
        auto [c, sx, sy] = bit.query(yid - 1);
        cntR[j] = c;
        sumRX[j] = sx;
        sumRY[j] = sy;
        ll xmod = ((upper[j].x % MOD) + MOD) % MOD;
        ll ymod = ((upper[j].y % MOD) + MOD) % MOD;
        bit.add(yid, 1, xmod, ymod);
    }

    ll total = 0;
    REP(j, K) {
        if (cntL[j] == 0 || cntR[j] == 0)
            continue;
        ll xj = ((upper[j].x % MOD) + MOD) % MOD;
        ll yj = ((upper[j].y % MOD) + MOD) % MOD;
        ll cL = cntL[j] % MOD, cR = cntR[j] % MOD;
        ll SLX = sumLX[j], SLY = sumLY[j];
        ll SRX = sumRX[j], SRY = sumRY[j];
        ll part1 = mul(xj, (mul(cL, SRY) - mul(cR, SLY) + MOD) % MOD);
        ll part2 = mul(yj, (MOD - mul(cL, SRX) + mul(cR, SLX)) % MOD);
        ll part3 = (MOD - mul(SLX, SRY) + mul(SRX, SLY)) % MOD;
        ll expr = (part1 + part2 + part3) % MOD;
        ll area2 = (MOD - expr) % MOD;
        ll area = mul(area2, INV2);
        total = (total + area) % MOD;
    }

    cout << K << '\n';
    for (auto &p : upper)
        cout << p.x << ' ' << p.y << '\n';
    cout << total << '\n';
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
