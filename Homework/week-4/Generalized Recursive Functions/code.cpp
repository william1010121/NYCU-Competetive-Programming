
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
   string fstline; 
   string secline;
   getline(cin,fstline);
   getline(cin,secline);
   stringstream s1(fstline),s2(secline);
   V<pii> vec, qry;
   auto trans = [&]( stringstream &ss, V<pii> &v ) {
       int a, b; 
       while( ss >> a >> b ) {
           v.PB( mkp(a,b) );
       }
   };

   trans(s1,vec); trans(s2,qry);
   auto [c,d] = vec.back(); vec.pop_back();


   map<pii,ll> mp; 
   auto f = [&]( auto&&f, int x, int y ) -> ll {
       if( x <= 0 || y <= 0 ) return d;
       if( mp.contains(mkp(x,y)) ) return mp[mkp(x,y)];
       ll ans = 0;
       for( auto [a,b] : vec ) {
            ans += f(f, x-a,y-b);
       }
       ans += c;
       mp[ mkp(x,y) ] = ans;
       return ans;
   };


   for( auto &[x,y] : qry ) {
        cout << f(f,x,y) << '\n';;
   }
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
	cin >> T;
    cin.ignore();
	while( T-- ) solve();
}

