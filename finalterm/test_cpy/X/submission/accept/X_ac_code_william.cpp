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
    int n;
    cin >> n;
    V<int> colors(n);
    unordered_map<int, int> slope2color;
    slope2color.reserve(n * 2);
    int next_color = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        auto it = slope2color.find(a);
        if (it == slope2color.end()) {
            slope2color[a] = next_color;
            colors[i] = next_color;
            next_color++;
        } else {
            colors[i] = it->second;
        }
    }
    cout << next_color << '\n';
    for (int i = 0; i < n; i++) {
        cout << colors[i] << (i + 1 < n ? ' ' : '\n');
    }
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
