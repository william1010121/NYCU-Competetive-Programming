
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
int main() {
    int N; cin >> N;
    V<V<int>> G(N+1);
    V<pii> E;
    V<int> vis(N+1,0);
    for( int i = 1; i < N; ++i ) {
        int u, v; cin >> u >> v;
        G[u].PB( v );
        G[v].PB( u );
        E.PB(mkp(u,v));
    }
    auto pre_do = [&](auto&&_, int cur, int par,V<int>&dep) -> int {
        dep[cur] = 0;
        for( auto &i : G[cur] ) {
            if( vis[i] || i == par ) continue; 
            _(_,i,cur,dep);
            dep[cur] = max( dep[cur], dep[i]+1 );
        }
        return dep[cur];
    };
    auto find_depth = [&](auto&&_,int cur,int par, int depth) -> pii { //[dep,pos]
        pii ans = {depth,cur}; 
        for( auto &i : G[cur] ) {
            if( vis[i] || i == par ) continue;
            ans = max( ans, _(_,i,cur,depth+1));
        }
        return ans;
    };
    auto find_mid = [&](auto&&_,int cur, int par, int updep,V<int>&dep) -> pii {  // [ pos, del]
        int mxdep = 0, othdep = updep;
        int go = -1;
        for( auto &i : G[cur] ) {
            if( i == par || vis[i] ) continue;
            if( dep[i] + 1 > mxdep ) go = i, othdep=max(mxdep,othdep);
            auto& use = ( dep[i]+1 > mxdep ? mxdep : othdep );
            use = max( use, dep[i]+1 );
        }
        if( mxdep - 1 < othdep + 1 ) return mkp(cur,mxdep);
        assert( go != -1 );
        return _(_,go,cur,othdep+1,dep);
    };
    auto get_delim = [&]( int cur, int notgo) {
        vis[notgo] = true;
        auto [_,f] = find_depth( find_depth, cur, -1, 0 );
        auto [dis,s] = find_depth( find_depth, f, -1, 0 );
        vis[notgo] = false;
        return dis;
    };
    int len=get_delim(1,0);
    V<pii> ans;
    for( auto &[x,y] : E ) {
        int lenx = get_delim(x,y), leny = get_delim(y,x);
        V<int> depx(N+1),depy(N+1);
        vis[x] = vis[y] = true;
        pre_do(pre_do,x,-1,depx); pre_do(pre_do,y,-1,depy);
        vis[x] = vis[y] = false;
        pii midx = find_mid(find_mid,x,y,0,depx), midy=find_mid(find_mid,y,x,0,depy);
        if( len > max( { lenx, leny, midx.S+midy.S+1 } ) ) {
            len = max( { lenx, leny, midx.S+midy.S+1 } );
            ans = { {x,y}, {midx.F,midy.F} };
        }
    }
    cout << len << '\n';
    cout << ans[0].F << ' ' << ans[0].S << '\n';
    cout << ans[1].F << ' ' << ans[1].S << '\n';
}
