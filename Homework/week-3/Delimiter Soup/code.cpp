
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
    cin.ignore();
    string str;
    getline( cin, str );
    // [ -> 0, { -> 1, ( -> 2
    V<int> stk;

    for( int i = 0; i < N; ++i ) {
        if( str[i] == ' ' ) continue;
        if( str[i] == '[' ) 
            stk.PB( 0 );
        if( str[i] == ']' ) {
            if( stk.empty() || stk.back() != 0 ) {
                cout << ']' << ' ' << i << '\n';
                return;
            }
            stk.pop_back();
        }
        if( str[i] == '{' ) 
            stk.PB( 1 );
        if( str[i] == '}' ) {
            if( stk.empty() || stk.back() != 1 ) {
                cout << '}' << ' ' << i << '\n';
                return;
            }
            stk.pop_back();
        }
        if( str[i] == '(' ) 
            stk.PB( 2 );
        if( str[i] == ')' ) {
            if( stk.empty() || stk.back() != 2 ) {
                cout << ')' << ' ' << i << '\n';
                return;
            }
            stk.pop_back();
        }
    }
    cout << "ok so far" << '\n';


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

