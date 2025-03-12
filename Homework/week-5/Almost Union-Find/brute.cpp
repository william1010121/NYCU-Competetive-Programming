
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
void solve(int N, int M) {

    V<int> fth(N+M+100,0);
    V<int> peo(N+1);
    V<int> sz(N+M+100,1);
    V<ll> sum(N+M+100,0);
    iota(begin(peo),end(peo),0);
    iota(begin(fth),end(fth),0);
    iota(begin(sum),end(sum),0);
    int cnt = N+1;

    function<int(int)> find = [&]( int a ) {
        return a == fth[a] ? a : fth[a] = find( fth[a] ) ;
    };
    auto join = [&](int a, int b) {
        int fa = find(a), fb = find(b);
        if( fa == fb ) return false;
        fth[fa] = fb;
        sz[fb] += sz[fa];
        sum[fb]  += sum[fa];
        return true;
    };


    for( int i=  0; i < M; ++i ) {
        int mth; cin >> mth;
        if( mth == 1 ) {
            int p, q; cin >> p >> q;
            join( peo[p], peo[q] );
        }
        else if( mth == 2 ) {
            int p, q; cin >> p >> q;
            sz[find(peo[p])]--;
            sum[find(peo[p])] -= p;

            peo[p] = cnt++;
            sum[peo[p]] = p;

            join( peo[p], peo[q] );
        }
        else if( mth == 3 ) {
            int p; cin >> p;
            cout << sz[find(peo[p])]  << ' ' << sum[find(peo[p])]<< '\n';
        }
    }
}

int main () {
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "brute.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
    int N, M;
	while(cin >> N >> M) solve( N, M);
}

