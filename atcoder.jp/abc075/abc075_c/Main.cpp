#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
int V,E;
vector<int> g[100100];
int dep[100100],low[100100],ord[100100];
int cnt = 0;
void dfs(int v,int p,int d){
    dep[v] = d;
    ord[v] = cnt++;
    low[v] = ord[v];
    for(int i=0;i<g[v].size();i++){
        if(g[v][i]==p)continue;
        int ch = g[v][i];
        if(ord[ch]==-1){
            dfs(ch,v,d+1);
            low[v] = min(low[v],low[ch]);
        }else{
            low[v] = min(low[v],ord[ch]);
        }
    }
}
int main(){
    scanf("%d %d",&V,&E);
    vector<P> es(E);
    for(int i=0;i<E;i++){
        int s,t;
        scanf("%d %d",&s,&t);
        s--;t--;
        g[s].pb(t);
        g[t].pb(s);
        if(s>t)swap(s,t);
        es[i]=P(s,t);
    }
    memset(ord,-1,sizeof(ord));
    dfs(0,-1,0);
    vector<P> ans;
    for(int i=0;i<E;i++){
        int s = es[i].fi,t = es[i].sec;
        if(dep[s]>dep[t])swap(s,t);
        if(ord[s]<low[t])ans.pb(es[i]);  
    }
    sort(all(ans));
    cout << ans.size() << endl;
   // for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].fi,ans[i].sec);
    return 0;
}