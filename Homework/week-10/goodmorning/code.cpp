
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
V<int> number;
void init() {
    auto dfs = [&]( auto&&dfs, int layer, int pos, int val, int curnumber ) -> void {
        if( val != -1 ) {
            curnumber = curnumber*10 + val;
            if( curnumber < 220 )
                number.PB( curnumber );
        }
        if( curnumber > 220 ) return;
        if( layer == 0 ) {
            dfs(dfs,1,1,1,curnumber);
            dfs(dfs,1,2,2,curnumber);
            dfs(dfs,1,3,3,curnumber);
            dfs(dfs,1,pos,-1,curnumber);
        }
        if( layer == 1 ) {
            if( pos <= 1 )
                dfs(dfs,1,1,1,curnumber),dfs(dfs,2,1,4,curnumber);
            if( pos <= 2 )
                dfs(dfs,1,2,2,curnumber),dfs(dfs,2,2,5,curnumber);
            if( pos <= 3 )
                dfs(dfs,1,3,3,curnumber),dfs(dfs,2,3,6,curnumber);
            dfs(dfs,2,pos,-1,curnumber);
        }
        if( layer == 2 ) {
            if( pos <= 1 )
                dfs(dfs,2,1,4,curnumber),dfs(dfs,3,1,7,curnumber);
            if( pos <= 2 )
                dfs(dfs,2,2,5,curnumber),dfs(dfs,3,2,8,curnumber);
            if( pos <= 3 )
                dfs(dfs,2,3,6,curnumber),dfs(dfs,3,3,9,curnumber);
            dfs(dfs,3,pos,-1,curnumber);
        }
        if( layer == 3 ) {
            if( pos <= 1 )
                dfs(dfs,3,1,7,curnumber);
            if( pos <= 2 )
                dfs(dfs,3,2,8,curnumber),dfs(dfs,4,2,0,curnumber);
            if( pos <= 3 )
                dfs(dfs,3,3,9,curnumber);
            dfs(dfs,4,pos,-1,curnumber);
        }
        if( layer == 4 ) {
            if(val==0&&curnumber&&pos<=2) dfs(dfs,4,2,0,curnumber);
        }
    };
    dfs(dfs,0,0,-1,0);
}
void solve() {
    int K; cin >> K;
    int ans = 1e9;
    for( auto &i : number ) {
        if( abs(i-K) < abs(ans-K)) {
            ans = i;
        }
    }
    cout << ans << '\n';

    // 1 2 3
    // 4 5 6
    // 7 8 9
    // 0
}

int main () {
    init();
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	cin >> T;
	while( T-- ) solve();
}

