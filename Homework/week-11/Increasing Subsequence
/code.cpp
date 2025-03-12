
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
void solve(int N) {
    V<int> vc(N+1);
    for( int i = 1; i <= N; ++i ) {
        cin >> vc[i];
    }
    reverse( begin(vc)+1,end(vc));
    V<int> dp(N+1,1);
    V<int> from(N+1,0);
    dp[0] = 0;


    int mx_pos = 0;
    for( int i = 2; i <= N; ++i ) {
        for( int j = 1; j < i; ++j  ) {
            if( vc[j] > vc[i] ) {
                if( dp[j] + 1 == dp[i] ) {
                    from[i] = ( from[i] &&  vc[j] < vc[from[i]] ? j  : from[i] ); 
                }
                if( dp[j] + 1 > dp[i] ) {
                    dp[i] = dp[j] + 1;
                    from[i]  = j;
                }
            }
        }
        mx_pos = ( dp[mx_pos] < dp[i]  || (dp[mx_pos] == dp[i] && vc[i] <= vc[mx_pos]) ? i : mx_pos );
    }

    V<int> ans;
    while( mx_pos != 0 ) {
        ans.PB( vc[mx_pos] );
        mx_pos = from[mx_pos];
    }
    cout << ans.size() << ' ' ;
    for( auto &i : ans )
        cout << i << ' ';
    cout << '\n';
}

int main () {
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	while(cin>> T && T) solve(T);
}

