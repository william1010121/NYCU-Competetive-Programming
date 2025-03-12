
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mkp make_pair
#define EB emplace_back
#define PH push
#define REP(i,N) for( int i = 0; i < N; ++i )
#define FOR(i,a,b) for( int i = (a); i <= (b); ++i )
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef pair<int,int> pii;

template<typename T>
using V = vector<T>;
void solve() {
    int N, M, K; 
    cin >> N >> M >> K;
    V<double> vc(N);
    for( auto &i : vc) cin >> i;
    deque<double> op;
    const double fac = pow(2,0.5)/2;
    for( int i =0 ; i < M; ++i )
        op.EB(({int a; cin >> a; a;}));
    for( int i = 0; i < K; ++i ) 
        op.EB(({int a; cin >> a; fac*a;}));
    sort( begin(op),end(op));
    sort( begin(vc), end(vc));

    int ans = 0;
    for( auto &i : vc ) {
        if( op.empty() || i <= op.front() ) continue;
        ans ++ ;
        op.pop_front();
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

