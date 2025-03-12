
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


constexpr int mxN = 1e5+3;
struct BIT {
    ll bit[mxN];
    void update( int pos, int k ) { for(;pos<mxN;pos+=(pos&-pos)) bit[pos]+=k; };
    ll queryUpper(int l) {
        ll ans = 0;
        int r = mxN-1;
        for(;r;r-=(r&-r))ans+=bit[r];
        for(;l;l-=(l&-l))ans-=bit[l];
        return ans;
    }

    BIT(){memset(bit,0,sizeof(bit));};
};


void solve() {
    int N; cin >> N;
    BIT cnt, sum;
    ll ans = 0;
    for( int i = 0; i < N; ++i ) {
        int a; cin >> a;
        ans += sum.queryUpper(a);
        sum.update( a, cnt.queryUpper(a) );
        cnt.update( a, 1 );
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

