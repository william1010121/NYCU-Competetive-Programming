
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
#define EB emplace_back
#define EP emplace
#define REP(i,N) for( int i = 0; i < N; ++i )
#define FOR(i,a,b) for( int i = (a); i <= (b); ++i )
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef pair<int,int> pii;

template<typename T>
using V = vector<T>;
void solve() {
    int N, M, T; cin >> N >> M >> T;
    V<V<pii>> G(N+1);
    for( int i = 0; i < M; ++i ) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].EB(w,v);
        G[v].EB(w,u);
    }
    int st, ed; cin >> st >> ed;

    auto bfs = [&](int K) -> V<int> {
        V<int> penalty(N+1);
        V<int> vis(N+1,0);
        priority_queue<pii,V<pii>,greater<pii>> pq;
        for( int i = 0; i < K; ++i ) {
            int a; cin >> a;
            pq.EP(0,a);
        }
        while(!pq.empty() ) {
            auto [dis,u] = pq.top(); pq.pop();
            if( vis[u] ) continue;
            vis[u] = true;
            penalty[u] = dis;
            for( auto &[w,v] : G[u] ) {
                if( vis[v] ) continue;
                pq.EP(dis+w,v);
            }
        }
        return penalty;
    };

    V<int> penalty = ({int k; cin >> k; bfs(k);});

    auto shortestPath = [&](int K) -> int {
        priority_queue<pii,V<pii>,greater<pii>> pq;
        V<int> vis(N+1,0);
        int ans = 2e9;
        pq.EP(0,st);
        while(!pq.empty() ) {
            auto [dis,u] = pq.top(); pq.pop();
            if( vis[ u ] ) continue;
            if( u == ed ) {
                ans = dis;
                break;
            }
            vis[u] = true;
            for( auto &[w,v] : G[u] ) {
                if( vis[v] || penalty[v]<K ) continue;
                pq.EP(dis+w,v);
            }
        }

        return ans;
    };
    int l = 0, r= penalty[st]+1;
    while( r-l > 1 ) {
        int m = (l+r)>>1;
        ( shortestPath(m) <= T ? l : r ) = m;
    }
    cout << l << '\n';
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

