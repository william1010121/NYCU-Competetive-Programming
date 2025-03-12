
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
constexpr int mxN = 5e6+3;
ll bit[mxN];
void update( int pos , int k ) {
    for(;pos<mxN; pos+=(pos&-pos))
        bit[pos] += k;
}
ll query(int pos) {
    ll ans =0;
    for( ; pos; pos-=(pos&-pos))
        ans += bit[pos];
    return ans;
}
void solve() {
    int N, Q; cin >> N >> Q;
    for( int i = 0; i < Q; ++i ) {
        char c; cin >> c;
        if( c == '+' ) {
            int a, b; cin >> a >> b;
            ++a;
            update( a, b );
        }
        else {
            int a; cin >> a;
            cout << query( a ) << '\n';
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

