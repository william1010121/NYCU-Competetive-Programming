
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
    int N, K; cin >> N >> K;
    V<int> bit(N+1,0);
    V<int> vc(N+1,0);
    const int mxN = N+1;
    auto update = [&]( int pos , int k ) {
        for( ; pos < mxN; pos += (pos&-pos))
            bit[pos] += k;
    };
    auto query = [&]( int l, int r) {
        int ans = 0;
        --l;
        for( ;r;r-=(r&-r)) ans += bit[r];
        for( ;l;l-=(l&-l)) ans-=bit[l];
        return ans;
    };

    for( int i = 0; i < K; ++i ) {
        char c;
        cin >> c;
        if( c == 'F' ) {
            int pos; cin >> pos;
            update( pos, (vc[pos] ? -1 : 1 ));
            vc[pos]^=1;
        }
        else if( c == 'C' ) {
            int l, r; cin >> l >>r;
            cout << query(l,r) << '\n';
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

