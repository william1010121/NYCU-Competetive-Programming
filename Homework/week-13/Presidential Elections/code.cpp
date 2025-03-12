
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
    const int INF = 1e9+10;
    V<int> dp(2602,INF);
    dp[0] = 0;
    ll sum = 0;
    for( int i = 0; i < N; ++i ) {
        int s, a, b, c;
        cin >> s >> a  >> b >> c;
        sum += s;
        int conv = max(((a+b+c)/2)+1-a,0);
        //cout << s << ' ' << conv  << ' ' << c<< '\n';
        if( conv > c ) continue;
        for( int j = 2601; j>=s; --j )
            dp[j] = min( dp[j], dp[j-s]+conv );
    }
    int ans = *min_element(dp.begin()+((sum+2)/2), dp.end());
    if( ans == INF ) cout << "impossible\n";
    else cout << ans << '\n';
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

