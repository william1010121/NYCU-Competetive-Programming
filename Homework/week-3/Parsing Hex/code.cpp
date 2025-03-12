
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
    string s;
    set<char> allow = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b','c','d','e','f',
        'A','B','C','D','E','F'
    };
    while( getline( cin, s ) ) {
        auto to_ll = [&](string base) -> ll {
            ll value = 0;
            for( auto &i : base ) {
                value *= 16;
                if( isdigit(i) )
                    value += i-'0';
                else 
                    value += tolower(i)-'a'+10;
            }
            return value;
        };
        auto read = [&](string st, auto &i) {
            string base;
            while( i<(int)s.size() &&  allow.count(s[i]) ) base += s[i++];
            cout << st << base << ' ';
            cout << to_ll(base) << '\n';
        };
        for( int i = 0; i < (int)s.size()-1; ++i ) {
            if( s[i] == '0' && tolower(s[i+1]) == 'x' ) {
                i+=2;
                read(string{s[i-2],s[i-1]}, i);
                i-=2;
            }
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

