
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
    V<array<int,3>> E;
    for( int i = 1; i <= N; ++i ) {
        for( int j = 1; j <= N; ++j ) {
            int w; cin >> w;
            if( i < j )
                E.PB(array<int,3>{w,i,j});
        }
    }
    sort( begin(E),end(E) );
    V<int> fth(N+1,0);
    iota(begin(fth),end(fth),0);

    function<int(int)> find = [&]( int a ) {
        return a==fth[a] ? a : fth[a]=find(fth[a]);
    };
    auto join = [&]( int a, int b ) {
        int fa = find(a), fb = find(b);
        if( fa == fb ) return false;
        fth[fa] = fb;
        return true;
    };
    V<pii> ans;
    for( auto &[w,u,v]: E ) {
        if( join(u,v) )
            ans.PB( mkp(u,v) );
    }
    for( auto &i : ans ) {
        cout << i.F << ' ' << i.S << '\n';
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

