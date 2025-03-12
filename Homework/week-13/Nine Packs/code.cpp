
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
void solve() {
    const int INF = 1e9;
    auto getDp = [&]( int SZ ) -> V<int> {
        V<int> dp(100001,INF);
        dp[0] = 0;
        for( int i = 0 ; i < SZ; ++i ) {
            int v; cin >> v;
            for( int j = 100000; j >= v; --j ) {
                dp[j] = min( dp[j], dp[j-v]+1 );
            }
        }
        return dp;
    };
    V<int> dp1 = ({int H; cin >> H; getDp(H);});
    V<int> dp2 = ({int B; cin >> B; getDp(B);});
    int ans = INF;
    for( int i = 1; i <= 100000; ++i ) {
        if( dp1[i] && dp2[i] ) {
            ans = min( ans, dp1[i] + dp2[i] );
        }
    }
    if( ans == INF ) cout << "impossible\n";
    else cout << ans << '\n';
}

int main () {
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	cin >> T;
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	while( T-- ) solve();
}

