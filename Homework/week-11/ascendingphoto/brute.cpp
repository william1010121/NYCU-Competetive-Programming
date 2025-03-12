#pragma GCC optimize("Ofast,no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
typedef long long loli;
typedef long long LL;
typedef unsigned long long uloli;
typedef pair<int, int> pii;
typedef pair<loli, loli> pll;
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<uloli> dis(1LL, LLONG_MAX);

vector<loli> z;
vector<loli> zz;
inline int id(loli x){return lower_bound(z.begin(), z.end(), x)-z.begin();}
const uloli p=48763;

vector<deque<int>> vec;
vector<deque<uloli>> h;
vector<uloli> b;
vector<uloli> ppw;

struct cmp{
    bool operator()(int x, int y){
        int n=min(vec[x].size(), vec[y].size());
        if ((h[x][n-1]-b[x]*ppw[n])==(h[y][n-1]-b[y]*ppw[n])){
            if (n&1) return vec[x].size()>vec[y].size();
            return vec[x].size()<vec[y].size();
        }
        int l=0, r=n;
        while(l<r){
            int m=l+r>>1;
            if ((h[x][m]-b[x]*ppw[m+1])==(h[y][m]-b[y]*ppw[m+1])) l=m+1;
            else r=m;
        }
        if (l&1) return vec[x][l]<vec[y][l];
        return vec[x][l]>vec[y][l];
    }
};

void _solve(){
    int n;
    cin >> n;
    vector<loli> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        z.push_back(a[i]);
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    int m=z.size();
    for(int i=0;i<m;i++) zz.push_back(rng());
    a.erase(unique(a.begin(), a.end()), a.end());
    n=a.size();
    for(int i=0;i<n;i++) a[i]=id(a[i]);
    ppw.push_back(1);
    for(int i=1;i<=n;i++) ppw.push_back(ppw.back()*p);
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n&&a[j-1]<=a[j]) j++;
        deque<int> vt(j-i);
        deque<uloli> tmp(j-i);
        for(int k=i;k<j;k++){
            vt[k-i]=a[k];
            tmp[k-i]=((k==i)?0:tmp[k-i-1])*p+zz[a[k]];
        }
        vec.push_back(vt);
        h.push_back(tmp);
        b.push_back(0);
        i=j-1;
    }
    priority_queue<int, vector<int>, cmp> pq;
    for(int i=0;i<b.size();i++) pq.push(i);
    loli ans=0;
    while(pq.size()>1){
        int t=pq.top();
        pq.pop();
        ans++;
        while(!vec[t].empty()&&vec[t][0]<=vec[pq.top()][0]){
            b[t]=h[t][0];
            vec[t].pop_front();
            h[t].pop_front();
        }
        if (!vec[t].empty()) pq.push(t);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _t=1;
    //cin >> _t;
    while(_t--) _solve();
}
