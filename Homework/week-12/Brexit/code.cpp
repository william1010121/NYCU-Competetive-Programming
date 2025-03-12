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
    int N, M;
    int X, L;
    cin >> N >> M >> X >> L;
    V<V<int>> G(N+1);
    V<int> cnt(N+1,0);
    for( int i=0; i < M; ++i ) {
        int u, v; cin >> u >> v;
        G[u].PB( v );
        G[v].PB( u );
    }

    queue< int > qq;
    V<int> vis(N+1,0);
    qq.PH( L );
    vis[L] = true;
    while( !qq.empty() ) {
        auto a = qq.front(); qq.pop();
        for( auto &i : G[a] ) {
            if( vis[i] ) continue;
            cnt[i] ++;
            if( size(G[i]) <= 2*cnt[i] ) {
                vis[i] = true;
                qq.PH( i );
            }
        }
    }
    cout << (vis[X] ? "leave" : "stay" ) << '\n';
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

