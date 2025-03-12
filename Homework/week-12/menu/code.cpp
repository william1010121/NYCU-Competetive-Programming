
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

int GenDis(V<V<int>> G,const V<V<int>>&SCC,const V<int>&id) {
    V<int> vis(G.size(),0);
    V<int> dis(G.size(),0);

    V<int> dp(G.size(),1);
    V<int> dptmp(G.size(),1);

    for( auto& grp: SCC ) {
        int len = grp.size();
        int ID = id[grp[0]];

        for(auto &nd: grp ) {
            for( auto & to: G[nd] ) {
                if( id[to] == id[nd] ) continue;
                dp[nd] = max( dp[nd], dp[to] + 1 );
            }
        }

        for( auto &nd: grp)  {
            G[nd].erase(
                    remove_if(begin(G[nd]),end(G[nd]),[&](auto a){return id[a]!=ID;}), 
                    end(G[nd]));
        }

        for( int i = 0; i < len; ++i ) {
            int curnd = grp[i];
            queue<int> qq;
            qq.PH(curnd);
            auto dfs = [&](auto&&_,int cur, int dis) -> void{
                vis[ cur ] = true;
                dptmp[curnd] = max( dptmp[curnd], dp[cur] + dis );
                for( auto &i : G[cur] ) {
                    if( vis[i] ) continue;
                    _(_,i,dis+1);
                }
                vis[ cur ] = false;
            };
            dfs(dfs, curnd,0);
        }
        for( auto &nd : grp )
            dp[nd] = max( dp[nd], dptmp[nd]);
    }
    return *max_element(begin(dp),end(dp));
}

void solve() {
    int N, M; cin >> N >> M;
    V<V<int>> G(N+1);
    for( int i = 1; i <= M; ++i ) {
        int a, b; cin >> a >> b;
        G[a].PB( b );
    }

    V<int> low(N+1,0),dfn(N+1,0),id(N+1,-1),stk,instk(N+1,0);
    V<V<int>> SCC;

    auto taryan = [&](auto&&_, int cur, int par ) -> void {
        static int tm = 0;
        low[cur] = dfn[cur] =  ++tm;
        stk.PB(cur); instk[cur] = true;
        for( auto &i : G[cur] ) {
            if( !dfn[i] ) {
                _(_,i,cur);
                low[cur] = min(low[cur],low[i]);
            } else if( instk[i] ){
                low[cur] = min( low[cur], dfn[i] ); 
            };
        }
        if( low[cur] == dfn[cur] ) {
            int ID = SCC.size();
            SCC.PB({});
            int a = stk.back();
            do {
                a = stk.back(); 
                stk.pop_back();
                instk[a] = false;
                SCC.back().PB(a);
                id[a] = ID;
            } while( a != cur );
        }
    };

    for( int i = 1; i <= N; ++i ) {
        if( !dfn[i] )
        taryan( taryan, i, -1 );

    }
    cout << GenDis(G,SCC,id) << '\n';
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

