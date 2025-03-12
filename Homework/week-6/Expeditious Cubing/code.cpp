
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
    auto read = [&]() {
        int a, b;
        char c;
        cin >> a >> c >> b;
        return a*100 + b;
    };
    int ar[4];
    for( auto &i : ar ) i =read();
    int tar = 3*read();
    sort(ar,ar+4);
    if( tar < ar[0] + ar[1] + ar[2] ) {
        cout << "impossible" << '\n';
        return;
    }
    if( tar >= ar[1] + ar[2] + ar[3] ) {
        cout << "infinite" << '\n';
        return;
    }
    int ans = tar - ar[1] - ar[2];
    cout << ans/100 << '.' << (ans%100/10) << ans%10 << '\n';

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

