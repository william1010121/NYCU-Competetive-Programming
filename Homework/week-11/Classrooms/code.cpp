
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
    int N, K; cin >> N >> K;
    //priority_queue<int,V<int>,greater<int>> pq;
    multiset<int> S;
    for( int i = 0; i < K; ++i ) S.insert( 0 );
    V<pii> vc(N);
    for( auto &i : vc ) cin >> i.F >> i.S;
    sort( begin(vc),end(vc), [&]( auto a, auto b ) {
            return a.S < b.S || ( a.S == b.S && a.F < b.F );
            });
    int ans = 0;
    for( auto &[st,ed] : vc ) {
        auto f = S.lower_bound( st );
        if( f == S.begin() ) continue;
        f = prev( f );
        S.erase( f );
        S.insert( ed );
        ans ++;
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

