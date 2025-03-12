
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
    V<V<int>> vc(N,V<int>(N,0));
    for( auto &i : vc) for( auto &j : i ) cin >> j;
    if( N == 1 ) {
        cout << 1 << '\n';
        return;
    }
    V<int> val(N,0);
    for( int i = 0; i < N; ++i ) {
        for( int j = 0; j < N; ++j ) {
            if( i == j ) continue;
            val[i] |= vc[i][j];
            val[i] |= vc[j][i];
        }
    }
    for( auto &i : val ) cout << i << ' ';
    cout << '\n';
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

