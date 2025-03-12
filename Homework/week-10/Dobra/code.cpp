
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
    string S; cin >> S;
    const int len = S.size();
    S = '+' + S;
    // no l
    //    type1 count 1 2
    // 0
    //   type2 count 3 4
    V<pii> Type1 {
        {0,1}, {1,2}, {3,1},{4,1}
    }, Type2 {
        {0,3}, {3,4}, {1,3}, {2,3}
    };
    auto type = [&]( char c ) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ? 1 : 2;
    };

    ll dp[2][5][len+1];
    memset( dp, 0, sizeof(dp)) ;
    dp[0][0][0] = 1;
    for( int i = 1; i <= len; ++i ){
        if( S[i] == '_' ) {
            for( auto [src,dst] : Type1 ) {
                dp[1][dst][i] += 5*dp[1][src][i-1];
                dp[0][dst][i] += 5*dp[0][src][i-1];

            }
            for( auto [src,dst] : Type2 ) {
                dp[1][dst][i] += 21*dp[1][src][i-1] + dp[0][src][i-1];
                dp[0][dst][i] += 20*dp[0][src][i-1];
            }
            continue;
        }
        if( S[i] == 'L' ) {
            for( auto [src, dst] : Type2 )
                dp[1][dst][i] += dp[0][src][i-1] + dp[1][src][i-1];
            continue;
        }
        if( type(S[i]) == 1 ) {
            for( auto [src,dst] : Type1 ) {
                dp[0][dst][i] += dp[0][src][i-1];
                dp[1][dst][i] += dp[1][src][i-1];
            }
        }
        else {
            for( auto [src,dst] : Type2 ) {
                dp[0][dst][i] += dp[0][src][i-1];
                dp[1][dst][i] += dp[1][src][i-1];
            }
        }
    }

    ll ans = 0;
    for( auto &j : dp[1] )
        ans += j[len];
    cout << ans << '\n';
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

