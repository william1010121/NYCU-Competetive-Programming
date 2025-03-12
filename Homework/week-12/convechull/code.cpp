
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

pii operator + ( pii a, pii b ) {
    return mkp( a.F + b.F, a.S + b.S );
}
pii operator - ( pii a, pii b ) {
    return mkp( a.F - b.F, a.S - b.S );
}
int operator ^ ( pii a, pii b ) {
    return a.F * b.S - a.S * b.F;
}


void solve(int N) {
    V<pii> vc(N);
    for( auto &i: vc ) cin >> i.F >> i.S;
    sort( begin(vc), end(vc) );
    N = unique(vc.begin(),vc.end())-vc.begin();
    vc.resize(N);

    V<pii> convex;
    if( vc.size() == 1 ) {
        cout << 1 << '\n';
        cout << vc[0].F << ' ' << vc[0].S << '\n';
        return;
    }
    for( int _ = 0; _ < 2; ++ _ ) {
        int base = convex.size();

        for( int i = 0; i < N; ++i )  {
            while( convex.size() >= base+2 && ((end(convex)[-1]-end(convex)[-2])^(vc[i]-end(convex)[-2])) >= 0)
                convex.pop_back();
            convex.PB( vc[i] );
        }
        convex.pop_back();
        reverse(begin(vc), end(vc) );
    }
    reverse( convex.begin(), convex.end() );
    cout << convex.size() << '\n';
    for( auto &[x,y] : convex ) 
        cout << x << ' ' << y << '\n';
}

int main () {
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
    int N;
	while( cin >> N && N ) solve( N);
}

