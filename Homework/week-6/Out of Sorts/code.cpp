
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
    ll N, M, A, C, X;
    cin >> N >> M >> A >> C >> X;
    V<ll> vc(N+1);
    vc[0] = X;
    for( int i = 1;i <= N; ++i ) {
        vc[i] = (vc[i-1]*A)%M + C;
        vc[i] %= M;
    }

    V<bool> ok(N+1,1);
    auto DAC = [&]( auto &&dac, int l, int r ) {
        if( r<=l ) return;
        int m = (l+r)>>1;
        for( int i = l; i<m; ++i ) 
            if( vc[i] > vc[m] ) ok[i] = false;
        for( int i = m+1; i<=r; ++i )
            if( vc[i] < vc[m] ) ok[i] = false;
        dac(dac,l,m-1);
        dac(dac,m+1,r);
    };

    DAC(DAC,1,N);
    cout << accumulate(begin(ok)+1,end(ok),0) << '\n';
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

