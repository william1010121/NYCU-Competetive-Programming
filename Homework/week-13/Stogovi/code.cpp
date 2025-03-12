

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

struct Tree {
    V<V<int>>&G;
    V<V<int>> fth;
    V<int> dep;
    V<int> tin,tout;
    int N,lgN;

    void dfs( int cur, int par ) {
        static int tm = 0;
        tin[cur] = ++tm;
        for( int i = 1; i < lgN; ++i ) {
            fth[i][cur] = fth[i-1][fth[i-1][cur]];
        }
        for( auto &i : G[cur] ) {
            if( i == par ) continue;
            fth[0][i] = cur;
            dep[i] = dep[cur]+1;
            dfs( i, cur );
        }
        tout[cur] = ++tm;
    }
    bool isfather( int a, int b ) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }
    int lca (int a, int b) {
        if( isfather(a,b) ) return a;
        if( isfather(b,a) ) return b;
        for( int i = lgN-1; i>=0; --i ) {
            if( !isfather(fth[i][a], b) )
                a = fth[i][a];
        }
        return fth[0][a];
    }
    int dis(int a, int b) {
        return dep[a] + dep[b] - 2*dep[lca(a,b)];
    }

    Tree(V<V<int>>&G, int N):G(G), N(N){
        lgN = int(log2(N))+3;
        fth.assign( lgN, V<int>(N+1,0));
        dep.assign( N+1, 0);
        tin.assign( N+1, 0); tout.assign(N+1,0);
        dfs( 0, -1 );
    };
};
void solve() {
    int N; cin >> N;
    V<V<int>> G(N+1);
    V<int> nd(N+1);
    V<int> par(N+1);
    V<int> val(N+1);
    int cnt = 0;

    V<pii> qry;
    for( int i = 1; i <= N; ++i ) {
        char c; cin >> c;
        if( c == 'a' ) {
            int v; cin >> v;
            G[nd[v]].PB( ++cnt );
            val[cnt] = i;
            nd[i] = cnt;
            par[nd[i]] = nd[v];
        }
        if( c == 'b' ) {
            int v; cin >> v;
            nd[i] = par[nd[v]];
            qry.PB(mkp(-1,val[nd[v]]));
        }
        if( c == 'c' ) {
            int a, b; cin >> a >> b;
            nd[i] = nd[a];
            qry.PB(mkp(a,b));
        }
    }
    Tree tree(G,N);
    for( auto &i : qry ) {
        if( i.F == -1 ) cout << i.S << '\n';
        else cout << tree.dep[tree.lca(nd[i.F],nd[i.S])] << '\n';
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


