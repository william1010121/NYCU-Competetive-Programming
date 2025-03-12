
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
    int B, N, E;
    int sB, sN, sE;
    cin >> B >> N >> E;
    cin >> sB >> sN >> sE;
    V<int> vc((B+N+E)/2);
    for(auto &i : vc ) cin >> i;
    sort( begin(vc), end(vc), greater<int>());

    auto Ok = [&](int lbd) {
        int cnt[3] = { B, N, E };
        for( auto &i : vc ) {
            if( i*(sB+sB) >= lbd && cnt[0] >= 2 ) {
                cnt[0] -= 2;
                continue;
            }
            if( i*(sB+sN) >= lbd && cnt[0] && cnt[1] ) {
                cnt[0] --; cnt[1] --;
                continue;
            }
            if( sB+sE > sN+sN ) {
                if( i*(sN+sN) >= lbd && cnt[1] >= 2 ) {
                    cnt[1]-=2;
                    continue;
                }
                if( i*(sB+sE) >= lbd && cnt[0] && cnt[2] ) {
                    cnt[0] -- ; cnt[2] --;
                    continue;
                }
            }
            else {
                if( i*(sB+sE) >= lbd && cnt[0] && cnt[2] ) {
                    cnt[0] -- ; cnt[2] --;
                    continue;
                }
                if( i*(sN+sN) >= lbd && cnt[1] >= 2 ) {
                    cnt[1]-=2;
                    continue;
                }
            }
            if( i*(sN+sE) >= lbd && cnt[1] && cnt[2] ) {
                cnt[1]--; cnt[2] --;
                continue;
            }
            if( i*(sE+sE) >= lbd && cnt[2] >= 2 ) {
                cnt[2] -= 2;
                continue;
            }
            return false;
        }
        return true;
    };
    int l = 0, r = 1e9;
    while( r-l > 1 ) {
        int m = (l+r)>>1;
        ( Ok(m) ? l : r ) = m;
    }
    cout << l << '\n';
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

