
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
const int mxN = 1e5;

template<typename T>
using V = vector<T>;
void solve() {
    V<int> father(mxN);
    iota(begin(father),end(father),0);
    function<int(int)> find = [&]( int a ) {
        return a == father[a] ? a : father[a] = find(father[a]) ;   
    };
    auto join = [&]( int a, int b ) {
        int fa = find(a), fb=find(b);
        if( fa == fb ) return 0;
        father[fa] = fb;
        return 1;
    };



    int N, M; cin >> N >> M;
    V<V<int>> vc(N+2, V<int>(M+2,1));
    V<V<int>> G(N+2,V<int>(M+2,0));
    int cnt = 1;
    for( int i = 1; i <= N; ++i ) {
        for( int j = 1; j <= M; ++j ) {
            char c; cin >> c;
            cnt += ( c == '#' );
            vc[i][j] = cnt;
            G[i][j] = ( c == '#' ? 1 : 0 );
        }
    }

    int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
    int dy[8] = { -1, 1, 0, 0 , 1, -1, 1, -1};
    for( int i = 1; i <= N; ++i ) {
        for( int j = 1; j <= M; ++j ) {
            if( !G[i][j] ) continue;; 
            for( int k = 0; k < 8; ++k ) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if( !G[nx][ny] ) continue;
                cnt -= join( vc[i][j], vc[nx][ny] );
            }
        }
    }

    cout << cnt-1  << '\n';
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

