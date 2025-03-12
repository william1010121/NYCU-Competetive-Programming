
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
    int K; cin >> K;
    if( K <= 25 ) {
        cout << 'a' << char('a'+K) << '\n';
        return;
    }
    if( K > 25 && K <= 50 ) {
        int n = (K+1)/2;
        cout <<'a'<< char('a'+n) << char('a'+n-(K-n)) << '\n';
        return;
    }
    V<int> vc;
    vc.PB( 0 );
    while( K > 25 ) {
        vc.PB( vc.back() == 0 ? 25 : 0 );
        K-=25;
    }
    if( K ) vc.PB( vc.back() == 0 ? K : 25-K );
    if( end(vc)[-2] == 25 ) {
        while( vc.back() >= 2 ) vc[1]--, vc.back()-=2;
    }
    else {
        while( vc.back() <= 23 ) vc[1]--, vc.back()+=2;
    }
    for( auto &i : vc ) {
        cout << char('a'+i);
    }
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

