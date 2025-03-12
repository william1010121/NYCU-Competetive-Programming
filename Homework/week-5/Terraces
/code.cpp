
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
    swap( N, M);
    const int INF = 2e9;
    V<V<int>> vc(N+2, V<int>(M+2,INF));
    V<V<int>> vis(N+2,V<int>(M+2,0));
    V<pii> ord;
    for( int i = 1; i <= N; ++i ) {
        for( int j = 1; j <= M; ++j  ) {
            ord.PB( mkp(i,j) );
            cin >> vc[i][j];
        }
    }
    int cnt = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    sort( begin(ord), end(ord), [&]( auto &a, auto &b ) {
            return vc[a.F][a.S] < vc[b.F][b.S];
            });

    int sz = 0;
    auto check = [&]( auto&&check, int x, int y ) ->   bool {
        ++sz;
        bool ok = true;
        vis[ x ][ y ] = true;
        for( int k = 0; k < 4; ++k ) {
:q
:q
            int nx = x + dx[k];
            int ny = y + dy[k];
            if( vc[nx][ny] == vc[x][y] )  {
                if( !vis[nx][ny] )
                    ok &= check( check, nx, ny );
            }
            else if( vis[nx][ny] )
                ok = false;
        }
        return ok;
    };

    for( auto &[x,y]: ord ) {
        if( vis[x][y] ) continue;
        sz = 0;
        if( check(check,x,y) )
            cnt += sz;
    }


    cout << cnt << '\n';
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

