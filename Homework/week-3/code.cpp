
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
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for( int i = 0; i < N; ++i ) {
        int a; cin >> a;
        pq.push( a );
    }
    ll ans  =0;
    while( pq.size() > 1 ) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += a+b;
        pq.push( a+b);
    }
    cout << ans << '\n';
}

int main () {
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

