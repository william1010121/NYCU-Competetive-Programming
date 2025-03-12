
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
    V<V<int>> vc(N+2,V<int>(M+2,int(1e9)));
    V<V<int>> val(N+2,V<int>(M+2,0));
    V<pii> ord;
    ord.reserve( N*M );
    int cnt = 0;
    for( int i = 1; i <= N; ++i ) {
        for( int j = 1; j <= M; ++j ) {
            cin >> vc[i][j];
            ord.PB( mkp(i,j) );
            val[i][j] = ++cnt;
        }
    }

    sort( begin(ord),end(ord), [&]( auto a, auto b ) {
        return vc[a.F][a.S] < vc[b.F][b.S];
            } );

    V<int> fth(N*M+10,0);
    V<int> st(N*M+10,0);
    V<int> ed(N*M+10,0);
    iota(begin(fth),end(fth),0);
    function<int(int)> find = [&]( int a ) {
        return ( a == fth[a] ? a : fth[a] = find(fth[a]) );
    };
    auto join = [&]( int a, int b ) {
        int fa = find(a), fb = find(b);
        if( fa == fb ) return st[fa] & ed[fa];
        fth[fa] = fb;
        st[fb] |= st[fa];
        ed[fb] |= ed[fa];
        return st[fb] & ed[fb];
    };
    for( int i = 1; i <= N; ++i ) st[val[i][1]]= true, ed[val[i][M]] = true;

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    for( auto &[x,y]: ord ) {
        for( int k = 0; k < 4; ++k ) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if( vc[nx][ny] > vc[x][y] ) continue;
            if( join(val[x][y],val[nx][ny]) ) {
                cout << vc[x][y] << '\n';
                return;
            }
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

