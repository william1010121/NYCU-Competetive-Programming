
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
    int N; cin >> N;
    V<int> cost(N+1);
    for( int i = 1; i <= N; ++i ) cin >> cost[i];
    V<int> dp(30001,0);
    V<int> use(30001,0);
    dp[0] = 1;

    for( int i = 1; i <= N; ++i ) {
        for( int j = cost[i]; j <= 30000; ++j ) {
            dp[j] = clamp(dp[j]+dp[j-cost[i]],0,2);
            if( dp[j-cost[i]] )
            use[j] = i;
        }
    }

    int K; cin >> K;
    for( int i =0; i < K; ++i ) {
        int s; cin >> s;
        if( dp[s] == 0 ) {
            cout << "Impossible\n";
        }
        if( dp[s] > 1 ) {
            cout << "Ambiguous\n";
        }
        if( dp[s] == 1 ) {
            V<int> ans;
            while( use[s] ) {
                ans.PB( use[s] );
                s-=cost[use[s]];
            }
            reverse(begin(ans),end(ans));
            for( auto &i : ans ) cout << i << ' ';
            cout << '\n';
        }
    }
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

