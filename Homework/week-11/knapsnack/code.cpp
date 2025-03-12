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
void solve(int C, int N) {
    V<pii> vc(N);
    for( auto &[val,weight] : vc) cin >> val >> weight;
    V<V<int>> dp(2,V<int>(C+1,0));
    V<V<pii>> from(N+1,V<pii>(C+1,mkp(-1,-1)));

    for( int i = 0;i < N; ++i ) {
        dp[i&1] = dp[~i&1];
        if( i > 0 ) from[i] = from[i-1];
        for( int j = vc[i].S; j <= C; ++j ) {
            if( dp[~i&1][j-vc[i].S]+vc[i].F > dp[i&1][j] ) {
                from[i][j] = mkp(i-1,j-vc[i].S);
                dp[i&1][j] = dp[~i&1][j-vc[i].S]+vc[i].F;
            }
        } 
    }
    pii start = mkp( N-1, max_element(begin(dp[~N&1]),end(dp[~N&1]))-begin(dp[~N&1]));
    V<int> ans;
    while(start.F != -1 && start.S != -1) {
        start = from[start.F][start.S];
        if( start == mkp(-1,-1) ) break;
        ans.PB( start.F + 1 );
    }
    cout << ans.size() << '\n';
    for( auto &i : ans ) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main () {
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
    int C, N;
	while( cin >> C >> N) solve(C, N);
}

