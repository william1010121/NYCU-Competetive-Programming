
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
typedef pair<ll,ll> pii;

pii operator + ( pii a, pii b ) {
    return mkp(a.F+b.F,a.S+b.S);
}

pii operator - ( pii a, pii b ) {
    return mkp(a.F-b.F, a.S-b.S);
}

ll operator * ( pii a, pii b ) {
    return a.F*b.F+a.S*b.S;
}
ll operator ^ ( pii a, pii b ) {
    return a.F*b.S-a.S*b.F;
}
template<typename T>
class MyVec: public std::vector<T> {
public:
    using std::vector<T>::vector;
    T& operator[](size_t index ) {
        return std::vector<T>::operator[](index%this->size());
    }
};


template<typename T>
using V = vector<T>;
template<typename T>
using PV = MyVec<T>;


void solve( ){
    int N; cin >> N;
    V<pii> vc(N);

    for( auto &i : vc )
        cin >> i.F >> i.S;

    auto Convex = [&]( V<pii> v ) {
        PV<pii> conv;
        sort( begin(v),end(v) );
        v.resize(unique(begin(v),end(v))-begin(v));
        int sz = size(v);
        int base = 0;
        for( int _ = 0; _ < 2; ++_ ) {
            for( int i = 0; i < sz; ++i ) {
                while( (int)conv.size() >= base + 2 && 
                        ((end(conv)[-1]-end(conv)[-2])^(v[i]-end(conv)[-2]))>=0 )
                    conv.pop_back();
                conv.PB( v[i] );
            }
            conv.pop_back();
            base = conv.size();
            reverse( begin(v),end(v) );
        }
        return conv;
    };
    PV<pii> conv = Convex( vc );
    if( size(conv) <= 2 ) {
        cout << 0 << '\n';
        return;
    }

    auto area = [&]( pii a, pii b, pii c ) {
        return abs((b-a)^(c-a));
    };
    auto MaxTriangle = [&](PV<pii>& con) {
        ll ans = 0;
        const int sz = size(con);
        for( int i = 0; i < sz; ++i ) {
            int k = i+1;
            for(int j = i+1; j < sz; ++j) {
                while( area(conv[i],conv[j],conv[k]) <= area(conv[i],conv[j],conv[k+1]) )
                    ++k;
                ans = max(ans,area(conv[i],conv[j],conv[k]));
            }
        }
        return ans;
    };
    ll ans = MaxTriangle(conv);
    cout << ans/2 << '.' << (ans&1 ? 5 : 0 ) << '\n';
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

