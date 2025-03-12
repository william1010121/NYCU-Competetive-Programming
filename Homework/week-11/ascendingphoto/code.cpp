
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
    V<int> vc(N);
    for( auto &i : vc) cin >> i;
    N = unique(begin(vc),end(vc))-vc.begin();
    V<int> tmp = vc;
    sort(begin(tmp),end(tmp));
    tmp.resize(unique(begin(tmp),end(tmp))-begin(tmp));
    V<V<int>> pos(N+1);
    for( int i = 0; i < N; ++i ) {
        vc[i] = lower_bound(begin(tmp),end(tmp),vc[i])-begin(tmp);
        pos[vc[i]].PB( i );
    }
    pii Fmx={0,N}, Smx = {0,N};
    for( int i = 0; i < (int)tmp.size(); ++i ) {
        pii fmx=Fmx, smx = Smx;
        for( int j = 0; j < (int)pos[i].size(); ++j ) {
            int p = pos[i][j];
            if( p == N-1 || vc[p]+1 != vc[p+1] ) continue;
            pii s = ( p == Fmx.S ? Smx : Fmx );
            s.F++; s.S=p+1;
            if( pos[i+1].size() == 1 ) s.S = N;
            if( s > fmx ) smx = fmx, fmx = s;
            else if( s > smx ) smx = s;
        }
        Fmx = fmx; Smx = smx;
    }
    cout << N-Fmx.F-1 << '\n';;
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

