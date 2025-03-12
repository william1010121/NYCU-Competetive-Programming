
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
    int N, T; cin >> N >> T;
    V<pii> vc(N);
    for( auto &i : vc) cin >> i.F >> i.S;
    sort (begin(vc), end(vc), [&](auto a, auto b) { 
            return a.S < b.S || (a.S == b.S && a.F > b.F );
            });
    ll ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for( auto &i : vc ) {
        if( pq.size() == i.S+1 ) {
            ans += i.F;
            pq.push( i.F );
            ans -= pq.top();
            pq.pop();
        }
        else {
            ans += i.F;
            pq.push(i.F);
        }
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

