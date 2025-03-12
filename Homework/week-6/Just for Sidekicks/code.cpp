
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
constexpr int mxN = 2e5+3;
struct BIT {
    int bit[mxN];
    void update( int pos, int k ) {
        for( ; pos < mxN; pos+=(pos&-pos))
            bit[pos] +=k;
    }
    int query(int l, int r) {
        int ans = 0;
        for(;r;r-=(r&-r))ans+=bit[r];
        for(;l;l-=(l&-l))ans-=bit[l];
        return ans;

    };
    BIT(){memset(bit,0,sizeof(bit));};
};


void solve() {
    int N, Q; cin >> N >> Q;
    BIT sum[6];
    V<int> value(6);
    for( auto &i : value ) cin >> i;
    string st;
    cin >> st;
    V<int> type(N+1);
    for( int i = 1; i <= N; ++i ) {
        sum[st[i-1]-'1'].update( i, 1 );
        type[i] = st[i-1]-'1';
    }

    for( int i = 0; i < Q; ++i ) {
        int method; cin >> method;
        if( method == 1 ) {
            int pos, typ;
            cin >> pos >> typ;
            --typ;

            sum[type[pos]].update( pos, -1 );
            type[pos] = typ;
            sum[type[pos]].update( pos, 1 );
        }
        else if( method == 2 ) {
            int p, v; cin >> p >> v;
            --p;
            value[p] = v;
        }
        else {
            int l, r;
            cin >> l >> r;
            --l;
            ll ans = 0;
           for( int i = 0; i < 6; ++i ) {
            ans += 1LL*value[i]*sum[i].query(l,r);
           }
           cout << ans << '\n';
        }
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

