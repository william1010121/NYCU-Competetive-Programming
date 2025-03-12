
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
    int AI, BI; cin >> AI >> BI;
    V<pii> ans;
    auto check = [&]( int A, int C ) {
        ll B = C/A;
        int dab[10];
        int dc[10];
        int tpA=A, tpB=B;
        memset(dab,0,sizeof(dab)); memset(dc,0,sizeof(dc));
        while( A ) dab[A%10]++,A/=10;
        while( B ) dab[B%10]++,B/=10;
        while( C ) dc[C%10]++, C/=10;
        for( int i= 0;i < 10; ++i ) if(dab[i] != dc[i] ) return;
        ans.PB( mkp(tpA,tpB) );
    };
    for( int a = AI; a <= BI; ++a ) {
        for( int c = a; c <= BI; c += a ) {
            if( c/a < a ) continue;
            check(a,c);
        }
    }
    cout << ans.size() << " digit-preserving pair(s)" << '\n';
    for( auto [x,y] : ans ) {
        cout << "x = " << x << ", y = " << y  << ", xy = " << x*y << '\n';
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

