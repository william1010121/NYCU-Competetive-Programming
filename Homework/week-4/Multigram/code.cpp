
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
    string str; cin >> str;
    str = '3' + str;
    V<V<int>> pre(26,V<int>(str.size(),0));
    for( int i = 1; i < (int)str.size(); ++i) {
        pre[str[i]-'a'][i] ++;
        for( int j = 0; j<26; ++j ) {
            pre[j][i] += pre[j][i-1];
        }
    }

    auto check = [&]( int l1, int r1, int l2,int r2 ) { // [l,r]
        for( int j = 0; j < 26; ++j ) {
            if( pre[j][r1]-pre[j][l1-1] != pre[j][r2]-pre[j][l2-1] ) return false;
        }
        return true;
    };

    const int strlen = str.size()-1;
    for( int len=1; len<strlen; len ++ ) {
        if( strlen % len ) continue;
        bool ok = true;
        for( int st = len+1; st<=strlen; st+=len) {
           ok &= check(1,len,st,st+len-1); 
        }
        if( ok ) {
            cout << string(str.begin()+1,str.begin()+1+len) << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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

