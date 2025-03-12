
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
#define PB push_back
#define PH push
#define REP(i,N) for( int i = 0; i < N; ++i )
#define FOR(i,a,b) for( int i = (a); i <= (b); ++i )
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef pair<int,int> pii;

template<typename T>
using V = vector<T>;
const int mod = 9901;
void solve() {
    int N, K; cin >> N >> K;
    V<V<int>> Can(N,V<int>(N,1));
    for( int i = 0; i < K; ++i ) {
        int u, v; cin >> u >> v;
        --u, --v;
        Can[u][v] = Can[v][u] = 0;
    }
    int dp[N][1<<N];
    memset(dp,0,sizeof(dp));
    dp[0][1] = 1;
    const int FULL = (1<<N)-1;
    int ans = 0;
    for( int mask = 1; mask <= FULL; ++mask ) {
        for( int i = 0; i < N; ++i ) {
            if( !(mask>>i&1) ) continue;
            for( int j = 0; j < N; ++j ) {
                if( i == j || !(mask>>j&1) || !Can[i][j]) continue;
                dp[i][mask] = (dp[i][mask]+dp[j][mask^(1<<i)])%9901;
            }
           // cout << i << ' ' << bitset<5>(mask).to_string() << ' ' << dp[i][mask] << '\n';
            ans += ( mask == FULL && Can[0][i]? dp[i][mask] : 0 );
            ans %= mod;
        }
    }
    cout << (ans*4951)%mod << '\n';
}

int main () {
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	cin >> T;
    for( int i = 1; i <= T; ++i ) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

