
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
    string S, P, C;
    cin >> S >> P >> C;
    int d = int(pow(C.size(),1.5)+N)%int(C.size());
    const int len = C.size();
    map<char,int> smp, pmp;
    for( int i = 0; i < int(S.size()); ++i ) {
        smp[S[i]]=i;
        pmp[P[i]]=i;
    }
    V<int> spos(C.size(),0),ppos(C.size(),0);
    ppos[d]=smp[C[d]];
    for( int i=(d-1+len)%len; i!=d; i=(i-1+len)%len) {
        spos[(i+1)%len] = smp[P[ppos[(i+1)%len]]]; 
        ppos[i] = smp[C[i]]^spos[(i+1)%len];
    }
    for( auto &i : ppos ) {
        cout << P[i];
    }
    cout << '\n';
}

int main () {
#ifdef LOCAL
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
#else
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
    int N;
	while(cin >> N && N) solve(N);
}

