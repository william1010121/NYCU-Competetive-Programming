
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
    V<int> vc(N+2,0);
    const int INF = 2e9;
    for( int i = 1; i <= N; ++i ) cin >> vc[i];
    auto getAns = [&]() {
        V<pii> dp; // (height, min)
        int ans = 0;
        for( int i = 1; i <= N; ++i ) {
            int curmn = INF;
            while( !dp.empty() && dp.back().F < vc[i] ) {
                auto [height,mn] = dp.back(); dp.pop_back();
                curmn = min( {curmn, mn, height} );
            }
            if( !dp.empty() )
            ans = max( ans, vc[i]-curmn );
            dp.PB(mkp(vc[i],curmn));
        }
        return ans;
    };

    int ans = 0;
    ans = max( ans, getAns() );
    reverse( begin(vc),end(vc) );
    ans = max( ans, getAns() );
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

