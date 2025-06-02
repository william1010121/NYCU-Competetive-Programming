#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll k;
    cin >> N >> M;
    cin >> k;

    vector<ll> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(N + 1), radj(N + 1);
    adj.reserve(N + 1);
    radj.reserve(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    vector<int> order;
    order.reserve(N);

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            stack<pair<int, int>> st;
            st.push({i, 0});
            while (!st.empty()) {
                auto [u, state] = st.top();
                st.pop();
                if (state == 0) {
                    if (visited[u])
                        continue;
                    visited[u] = true;
                    st.push({u, 1});
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            st.push({v, 0});
                        }
                    }
                } else {
                    order.push_back(u);
                }
            }
        }
    }

    vector<int> comp_id(N + 1, 0);
    int comp_cnt = 0;
    for (int idx = int(order.size()) - 1; idx >= 0; idx--) {
        int u = order[idx];
        if (comp_id[u] == 0) {
            ++comp_cnt;
            stack<int> st;
            st.push(u);
            comp_id[u] = comp_cnt;
            while (!st.empty()) {
                int x = st.top();
                st.pop();
                for (int w : radj[x]) {
                    if (comp_id[w] == 0) {
                        comp_id[w] = comp_cnt;
                        st.push(w);
                    }
                }
            }
        }
    }

    vector<int> comp_size(comp_cnt + 1, 0);
    for (int i = 1; i <= N; i++) {
        comp_size[comp_id[i]]++;
    }

    vector<ll> weight(comp_cnt + 1, 0);
    for (int c = 1; c <= comp_cnt; c++) {
        if (comp_size[c] > 1) {
            weight[c] = k;
        }
    }
    for (int i = 1; i <= N; i++) {
        int c = comp_id[i];
        if (comp_size[c] == 1) {
            weight[c] = a[i];
        }
    }

    vector<vector<int>> children(comp_cnt + 1);
    children.reserve(comp_cnt + 1);
    vector<int> indegree(comp_cnt + 1, 0);
    for (int u = 1; u <= N; u++) {
        for (int v : adj[u]) {
            int cu = comp_id[u];
            int cv = comp_id[v];
            if (cu != cv) {
                children[cu].push_back(cv);
                indegree[cv]++;
            }
        }
    }

    vector<ll> dp0(comp_cnt + 1, 0), dp1(comp_cnt + 1, 0);
    vector<bool> seen(comp_cnt + 1, false);

    vector<int> roots;
    roots.reserve(comp_cnt);
    for (int c = 1; c <= comp_cnt; c++) {
        if (indegree[c] == 0) {
            roots.push_back(c);
        }
    }

    for (int root : roots) {
        if (seen[root])
            continue;
        stack<pair<int, bool>> st;
        st.push({root, false});
        while (!st.empty()) {
            auto [u, done_flag] = st.top();
            st.pop();
            if (done_flag) {
                ll pick_u = weight[u]; // if we pick u
                ll skip_u = 0;         // if we skip u
                for (int v : children[u]) {
                    skip_u += max(dp0[v], dp1[v]);
                    pick_u += dp0[v];
                }
                dp0[u] = skip_u;
                dp1[u] = pick_u;
                seen[u] = true;
            } else {
                st.push({u, true});
                for (int v : children[u]) {
                    if (!seen[v]) {
                        st.push({v, false});
                    }
                }
            }
        }
    }

    ll answer = 0;
    for (int r : roots) {
        answer += max(dp0[r], dp1[r]);
    }

    cout << answer << "\n";
    return 0;
}
