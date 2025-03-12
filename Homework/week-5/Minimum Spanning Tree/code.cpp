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
void solve(int N, int M) {
    V<array<int,3>> E;
    for( int i = 0; i < M; ++i ) {
        int u,v,w; cin >> u >> v >> w;
        if( u > v ) swap( u,v );
        E.PB(array<int,3>{w,u,v});
    }
    sort( begin(E), end(E) );

    V<int> fth(N+1,0);
    iota(begin(fth),end(fth),0);
    function<int(int)> find = [&](int a) {
        return a == fth[a] ? a : fth[a] = find(fth[a]);
    };
    auto join = [&](int a, int b) {
        int fa = find(a), fb = find(b);
        if( fa == fb ) return false;
        fth[fa] = fb;
        return true;
    };
    ll ansVal= 0;
    V<pii> ans;
    for( auto &[w,u,v] : E ) {
        if( join(u,v) ){
            ansVal += w;
            ans.PB( mkp(u,v) );
        }
    }
    sort( begin(ans), end(ans) );
    if( ans.size() != N-1 ) {
        cout << "Impossible\n";
        return;
    }
    cout << ansVal << '\n';
    for( auto &i : ans ) {
        cout << i.F << ' ' << i.S << '\n';
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
    int N, M;
	while(cin >> N >> M && !( N ==0 && M ==0 )) solve(N,M);
}

