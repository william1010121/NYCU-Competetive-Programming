
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
    map< char, bool > mp;
    for( int i = 0; i < N; ++i ) {
        char c; cin >> c;
        if( c == 'T') mp[ 'A' + i ] = true;
        else mp['A' + i ] = false;
    }
    cin.ignore();
    V<int> stk;
    string str;
    getline(cin, str);
    stringstream ss(str);
    char ch;
    while( ss >> ch ) {
        if( isalpha(ch) ) {
            stk.PB( mp[ch] );
            continue;
        }
        if( ch == '*' ) {
            int a = stk.back(); stk.pop_back();
            int b = stk.back(); stk.pop_back();
            stk.PB( a&b );
        }
        if( ch == '+' ) {
            int a = stk.back(); stk.pop_back();
            int b = stk.back(); stk.pop_back();
            stk.PB( a|b );
        }
        if( ch == '-' ) {
            int a = stk.back(); stk.pop_back();
            stk.PB( !a );
        }
    }
    cout << ( stk.back() ? 'T' : 'F' ) << '\n';
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

