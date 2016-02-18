#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 100100;
struct UnionFind{
	int par[SIZE],rank[SIZE];
	void init(){
		for(int i=0;i<SIZE;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void unite(int a,int b){
		a = find(a);
		b = find(b);
		if(a==b)return;
		if(rank[a]<rank[b])par[a]=b;
		else{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
}uf;
int N,M;
ll gr_cnt[100100];
bool used[100100][2];
bool gr[100100];
vector<int> g[100100];
void dfs(int v,int f){
	if(used[v][f])return;
	used[v][f]=true;
	if(f){
		gr[v]=true;
		gr_cnt[uf.find(v)]++;
	}
	if(sz(g[v])>1||f==1){
		for(int i=0;i<g[v].size();i++){
			if(!used[g[v][i]][1])dfs(g[v][i],1);
		}
	}else{
		for(int i=0;i<g[v].size();i++){
			if(!used[g[v][i]][0])dfs(g[v][i],0);
		}
	}
}
int main(){
	scanf("%d %d",&N,&M);
	uf.init();
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[a].pb(b);
		uf.unite(a,b);
	}
	for(int i=0;i<N;i++){
		dfs(i,0);
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		//printf("%lld\n",gr_cnt[i]);
		if(!gr[i])ans += sz(g[i]);
		ans += (gr_cnt[i])*(gr_cnt[i]-1);
	}
	printf("%lld\n",ans);
	return 0;
}