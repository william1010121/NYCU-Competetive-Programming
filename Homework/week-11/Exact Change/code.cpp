
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
    int tar; cin >> tar;
    int N; cin >> N;
    V<int> vc(N);
    for( auto &i : vc) cin >> i;
    const int INF = 1e9;
    V<V<int>> dp(2,V<int>(20001,INF));
    dp[1][0] = 0;
    for( int i = 0; i < N; ++i ) {
        dp[i&1] = dp[~i&1];
        for( int j = vc[i]; j <= 20000; ++j ) {
            dp[i&1][j] = min( dp[i&1][j], dp[~i&1][j-vc[i]]+1 );
        }
    }
    for( int i = tar; i <= 20000; ++i ) {
        if( dp[~N&1][i] != INF) {
            cout << i << ' ' << dp[~N&1][i] << '\n';
            return;
        }
    }
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
	while( T-- ) solve();
}

