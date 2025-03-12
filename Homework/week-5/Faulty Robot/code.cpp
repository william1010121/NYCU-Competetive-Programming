
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
    int N, M; cin >> N >> M;
    V<V<int>> force(N+1),bridge(N+1);
    for( int i = 0; i < M; ++i ) {
        int a, b; cin >> a >> b;
        if( a < 0 ) {
            force[-a].PB(b);
        }
        else bridge[a].PB(b);
    }
    V<V<int>> vis(2,V<int>(N+2,0));
    V<int> canstay(N+1,0);

    auto dfs = [&]( auto &&dfs, int use, int cur ) -> void {
        vis[ use ][ cur ] = true;
        canstay[cur] |= force[cur].empty();
        if( !use ) {
            for( auto &i : bridge[cur] ) {
                if( !vis[use+1][i] )
                    dfs( dfs, use+1, i );
            }
        }
        for( auto &i : force[cur] ) {
            if( !vis[use][i] )
                dfs( dfs, use, i );
        }
    };
    dfs( dfs, 0, 1 );
    cout << accumulate(begin(canstay),end(canstay),0) << '\n';
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

