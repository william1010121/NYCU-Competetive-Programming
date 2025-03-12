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
    V<V<int>> G(N+1);
    for( int i = 0; i < M; ++i ) {
        int a, b; cin >> a >> b;
        G[a].PB( b );
        G[b].PB( a );
    }

    V<int> vis(N+1,0);
    auto dfs = [&]( auto &&dfs, int cur ) -> void {
        vis[ cur ] = true;
        for( auto &i : G[cur] ) {
            if( vis[ i]  ) continue;
            dfs( dfs, i );
        }
    };

    dfs( dfs, 1 );
    int cnt = 0;
    for( int i = 2; i <= N; ++i  ){
        if( !vis[i] && ++cnt ) 
            cout << i << '\n';
    }
    if( cnt == 0 ) {
        cout << "Connected\n";
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

