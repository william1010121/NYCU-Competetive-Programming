
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
    V<V<int>> &G;
    int N;
    V<int> dep, tin, tout, val;

    void dfs( int cur, int par ) {
        static int tm = 0;
        tin[cur] = ++tm;
        val[cur] = 1;
        for( auto &i : G[cur] ) {
            if( i==par ) continue;
            dep[i] = dep[cur] + 1;
            dfs( i, cur );
            val[cur] += val[i];
        }
        tout[cur] = ++tm;
    }

    int isfather( int a, int b ) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }

    int cnt(V<int>&vc ) {
        sort( begin(vc),end(vc), [&]( auto &a, auto &b ) {
                return dep[a] < dep[b];
                });
        V<int> newv;
        int ans = 0;
        for( auto &i : vc ) {
            bool ok = true;
            for( auto &j : newv )
                ok &= !isfather(j,i);
            ans += ( ok ? val[i] : 0 );
            if( ok ) newv.PB(i);
        }
        return ans;
    }

    Tree( V<V<int>>&G, int N) : G(G), N(N) {
        dep.assign( N+1, 0 );
        tin.assign( N+1, 0 );
        tout.assign( N+1, 0 );
        val.assign( N+1, 0 );
        dfs( 0, -1 );
    };
};

void solve() {
    int N; cin >> N;
    V<V<int>> G(N+1);
    for( int i = 1; i <= N; ++i ) {
        int a; cin >> a;
        G[a].PB(i);
    }
    Tree tree(G,N);
    int Q; cin >> Q;
    for( int i = 1; i <= Q; ++i ) {
        int M; cin >> M;
        V<int> vc(M);
        for( auto &i : vc) cin >> i;
        cout << tree.cnt(vc) << '\n';
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

