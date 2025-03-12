
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
    V<pii> pos(N+1);
    V<string> name(N+1);
    V<int> clr(N+1);
    map<string,int> type;
    for( int i = 1; i <= N; ++i ) {
        cin >> pos[i].F >> pos[i].S >> name[i];
        if( !type.contains(name[i]) ) type[name[i]] = type.size();
        clr[i] = type[name[i]];
    }
    auto dis = [&]( int p1, int p2 ) {
        return abs(pos[p1].F-pos[p2].F)+abs(pos[p1].S-pos[p2].S);
    };
    pos[0] = mkp(0,0);

    int dp[N+1][1<<(type.size())];
    const int MASK = (1<<(type.size()))-1;
    for( auto &i : dp ) for( auto &j : i ) j = 100000;
    dp[0][0] = 0;
    for( int mask = 1; mask <= MASK; ++mask) {
        for( int i = 1; i <= N; ++i ) {
            if( !(mask>>clr[i]&1) ) continue;
            for( int j = 0; j <= N; ++j ) {
                if( i == j ) continue;
                if( j!=0 && !(mask>>clr[j]&1) ) continue;
                dp[i][mask] = min( dp[i][mask], dp[j][mask^(1<<clr[i])]+dis(i,j) );
//                cout << i << ' ' << bitset<3>(mask).to_string() << ' ' << dp[i][mask] << '\n';
            }
        }
    }
    int ans = int(1e9);
    for( int i = 1; i <= N; ++i ) {
        ans = min( ans, dp[i][MASK] + dis(0,i) );
    }
    cout << ans << '\n';
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

