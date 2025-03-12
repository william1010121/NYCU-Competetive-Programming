
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
const int maxn  = 1<<21;
using cplx = complex<double>;
const cplx I = cplx(0,1);
const double pi = acos(-1);
cplx omega[maxn+1];

void prefft() {
    for( int i = 0; i <= maxn; ++i )
        omega[i] = exp( i *2 * pi / maxn * I );
}
void bin(vector<cplx> &a, int n ) {
    int lg;
    for( lg = 0; (1<<lg) < n; ++lg ); --lg;
    vector<cplx> tmp(n);
    for( int i = 0; i < n ;++i ) {
        int to = 0 ;
        for( int j = 0; (1<<j) < n; ++j ) 
            to |= (((i>>j) & 1) << (lg - j ));
        tmp[to] = a[i];
    }
    for( int i = 0; i < n; ++i )  a[i] = tmp[i];
}

void fft( vector<cplx> &a, int n ) {
    bin(a,n);
    for (int step = 2; step <= n; step <<= 1 ) {
        int to = step >> 1;
        for( int i = 0; i < n; i+=step ) {
            for( int k = 0; k < to; ++k ) {
                cplx x = a[i+to+k]*omega[maxn / step * k];
                a[i+to+k] = a[i+k]-x;
                a[i+k] += x;
            }
        }
    }
}

void ifft( vector<cplx> &a, int n )  {
    fft( a, n );
    reverse( a.begin() + 1, a.end() );
    for( int i = 0; i < n; ++i ) a[i] /= n;
}


vector<int> multiply(const vector<int>&a, const vector<int>&b, bool trim = false ) {
    int d = 1;
    while( d < max(a.size(),b.size())) d<<=1; d<<=1;
    vector<cplx> pa(d), pb(d);
    for( int i = 0; i < a.size(); ++i ) pa[i] = cplx(a[i],0);
    for( int i = 0; i < b.size(); ++i ) pb[i] = cplx(b[i],0);
    fft(pa,d); fft(pb,d);
    for( int i = 0; i < d; ++i ) pa[i] *= pb[i];
    ifft( pa,d );
    vector< int > r(d);
    for( int i = 0; i < d; ++i ) r[i] = round(pa[i].real());
    if( trim ) 
        while( r.size() && r.back() == 0 ) r.pop_back();
    return r;
}

void solve() {
    string S; cin >> S;
    vector<int> va(S.size(),0),vb(S.size(),0);
    transform(S.begin(),S.end(), va.begin(), [&]( auto c ) { return c == 'A'; });
    transform(S.begin(),S.end(), vb.begin(), [&]( auto c ) { return c == 'B'; });
    reverse( begin(vb), end(vb) );
    prefft();
    V<int> ans = multiply( va, vb );
    for( int  i = S.size(); i < 2*S.size()-1; ++i )
        cout << ans[i] << '\n';

    cout << '\n';
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

