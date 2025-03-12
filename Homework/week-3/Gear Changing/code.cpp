
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
typedef pair<ll,ll> pii;

template<typename T>
using V = vector<T>;
void solve() {
    int N, M, P;
    cin >> N >> M >> P;
    V<ll> va(N), vb(M);
    V<pii> vc;
    for( auto &i : va ) cin >> i;
    for( auto &i : vb ) cin >> i;
    for( auto &i : va ) for( auto &j : vb )
        vc.PB(mkp(i,j));

    sort(vc.begin(),vc.end(),[&](auto a, auto b ) {
            return a.F * b.S > b.F * a.S;
            });
    for( int i = 1; i < vc.size(); ++i ) {
        auto [a1,a2] = vc[i-1];
        auto [b1,b2] = vc[i];
        // (a1/a2) > (b1/b2)*(100+p
        // a2/a1*(1+P*0.01) > b2/b1
        // a2*b1*(100+P) > b1*a1

        if( 100*a1*b2 > b1*a2*(100+P) ) {
            cout << "Time to change gears!" << '\n';
            return;
        }
    }
    cout << "Ride on!" << '\n';

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

