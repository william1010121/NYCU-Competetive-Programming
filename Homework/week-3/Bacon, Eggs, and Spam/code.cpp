
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
    map<string,V<string>> mp;
    cin.ignore();
    for( int i = 0; i < N; ++i ) {
        string s;
        stringstream ss;
        getline(cin,s);
        ss << s;
        string name, proj;
        ss >> name;
        while( ss >> proj ) mp[proj].PB( name);
    }
    for( auto &i : mp ) {
        cout << i.F << ' ';
        sort(begin(i.S),end(i.S));
        for( auto &j : i.S ) cout << j << ' ';
        cout << '\n';
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
    int N; 
    while( cin >> N && N ) solve(N);
}

