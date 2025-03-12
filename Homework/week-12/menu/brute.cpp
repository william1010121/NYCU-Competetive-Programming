#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define pii pair<int, int>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define endl '\n'
#define io \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
const int INF = 1e8;
 
int curComp = 0;
vector<int> newG, sz;
vector<vector<int>> point;
 
struct CompEdge {
    int vComp, u, v;
};
struct SCC {
    int n, dft, nscc;
    vector<int> low, dfn, bln, instack, stk;
    vector<vector<int>> G;
    void dfs(int u) {
        low[u] = dfn[u] = ++dft;
        instack[u] = 1, stk.pb(u);
        for (int v : G[u])
            if (!dfn[v])
                dfs(v), low[u] = min(low[u], low[v]);
            else if (instack[v] && dfn[v] < dfn[u])
                low[u] = min(low[u], dfn[v]);
        if (low[u] == dfn[u]) {
            for (; stk.back() != u; stk.pop_back())
                bln[stk.back()] = nscc, instack[stk.back()] = 0;
            instack[u] = 0, bln[u] = nscc++, stk.pop_back();
        }
    }
    SCC(int _n) : n(_n), dft(), nscc(), low(n), dfn(n), bln(n), instack(n), G(n) {}
    void add_edge(int u, int v) {
        G[u].pb(v);
    }
    void solve() {
        for (int i = 0; i < n; i++) if (!dfn[i]) dfs(i);
    }
};
 
int n, m;
vector<vector<int>> adj;
vector<vector<CompEdge>> adjComp;
map<pii, int> dist;
 
void hehe() {
    adjComp.assign(curComp, vector<CompEdge>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (newG[i] != newG[adj[i][j]]) {
                adjComp[newG[i]].push_back({ newG[adj[i][j]], i, adj[i][j] });
            }
        }
    }
}
 
vector<int> vis; int vf = 0;
void dfs(int node, int start, int d) {
    if (vis[node] == vf) return;
    vis[node] = vf;
    dist[{start, node}] = max(dist[{start, node}], d);
    for (int i = 0; i < adj[node].size(); i++) {
        if (newG[adj[node][i]] == newG[node])
        dfs(adj[node][i], start, d + 1);
    }
    vis[node] = 0;
}
 
void hehehe() {
    vis.assign(n, 0);
    for (int i = 0; i < point.size(); i++) {
        for (int j = 0; j < point[i].size(); j++) {
            vf++;
            dfs(point[i][j], point[i][j], 0);
        }
    }
}
 
vector<int> mem(1e5 + 5, -1);
int get(int node) {
    int& ret = mem[node];
    if (ret != -1) return ret;
    ret = 0;
    for (auto& i : point[newG[node]])
    ret = max(ret, dist[{node, i}]);
 
    for (auto& i : adjComp[newG[node]]) {
        ret = max(ret, get(i.v) + dist[{node, i.u}] + 1);// 這很蝦爬
    }
    return ret;
}
 
void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
    }
    newG.assign(n, -1);
    sz.assign(n, 0);
    SCC scc(n);
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            scc.add_edge(i, j);
        }
    }
    scc.solve();
    curComp = scc.nscc;
    point.assign(curComp, vector<int>());
    for (int i = 0; i < n; i++) {
        point[scc.bln[i]].push_back(i);
        newG[i] = scc.bln[i];
    }
    hehe();
    hehehe();
 
    int r = 0;
    for (int i = 0; i < n; i++)
    r = max(r, get(i));
    cout << r + 1 << endl;
}
 
signed main() {
    io;
    int T=1;
    // cin >> T;
    while(T--) {
        solve();
    }
}

