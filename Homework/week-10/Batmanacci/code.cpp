
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
    ll N, K; cin >> N >> K;
    V<ll> vc(2,1);
    if( N&1 ) N=91;
    else N=90;
    for( int i = 2; i < N; ++i )
        vc.PB(vc.end()[-1]+vc.end()[-2]);
    int cur_pos = vc.size()-1;
    while( cur_pos >= 2 ) {
        ll a = vc[cur_pos-2];
        if( K>a )
            K-=a,cur_pos-=1;
        else 
            cur_pos-=2;
    }
    cout << "NA"[cur_pos] << '\n';;
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

