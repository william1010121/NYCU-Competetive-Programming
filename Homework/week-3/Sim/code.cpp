
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
   string str;
   getline(cin,str);
   list<char> lst;
   auto it = lst.begin();
   for( auto &i : str ) {
        if( i == '<' ) {
            if( it==lst.begin() ) continue;
            lst.erase( prev(it) );
            continue;
        }
        if( i == '[' ) {
            it = lst.begin();
            continue;
        }
        if( i == ']' ) {
            it = lst.end();
            continue;
        }
        lst.insert( it, i );
   }
   cout << string(begin(lst),end(lst)) << '\n';
}

int main () {
int T = 1;
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	cin >> T;
    cin.ignore();
	while( T-- ) solve();
}

