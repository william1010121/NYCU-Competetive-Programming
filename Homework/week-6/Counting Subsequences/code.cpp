
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
    V<int> vc(N);
    for( auto &i : vc ) cin >> i;
    map<ll,int> mp;
    mp[0] = 1;
    ll ans = 0;
    ll cursum = 0;
    for( auto &i : vc ) {
        cursum += i;
        ans += mp[cursum-47];
        mp[cursum]++;
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

