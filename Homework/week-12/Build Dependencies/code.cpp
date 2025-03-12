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
    cin.ignore();
    V<V<int>> G(N+1);
    V<V<string>> makefile(N+1);
    map<string,int> pos;
    V<string> filename(N+1);
    V<int> incnt(N+1,0);
    for( int i = 1; i <= N; ++i ) {
        string st;
        getline( cin, st );
        string name = st.substr(0,st.find(':'));
        pos[name] = i;
        filename[i] = name;
        int start = 0, ed = st.find(':')+1;
        while( (start=st.find_first_not_of(' ', ed)) != string::npos ) {
            ed = st.find(' ', start);
            makefile[i].PB(st.substr(start,ed-start));
        }
    }
    string file; cin >> file;
    for( int i = 1; i <= N; ++i ) {
        for( auto &j : makefile[i] ) {
            G[pos[j]].PB( i );
            incnt[i] ++;
        }
    }
    V<int> vis(N+1,0);
    queue<int> qq;
    for( int i = 1; i <= N; ++i ) 
        if( incnt[i] == 0 ) qq.PH( i );
    vis[pos[file]]=true;
    while( !qq.empty() ) {
        auto a = qq.front(); qq.pop();
        if( vis[a] ) 
            cout << filename[a] << '\n';
        for( auto &i : G[a] ) {
            incnt[i]--;
            if( incnt[i] == 0 )
                qq.PH(i);
            if( vis[a] )
                vis[i] = true;
        }
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

