#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
const int SIZE = 114;
struct UnionFind{
	int par[SIZE],rank[SIZE];
	void init(int n){
		for(int i=0;i<n;i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x] < rank[y])par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y])rank[x]++;
		}	
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
}uf;
int N;
ll str[500100];
int G[105][105],rG[105][105];
vector<ll> cost[105][105];
int idx[105][105];
int deg[105];
int used[105];
bool flag = false;
void rdfs(int v){
	used[v]=1;
	for(int i=0;i<100;i++){
		if(rG[v][i]==0)continue;
		flag = false;
		if(used[i])continue;
		rdfs(i);
	}
}
vector<ll> ans;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%lld",&str[i]);
	uf.init(100);
	for(int i=0;i<N;i++){
		int u = (int)(str[i]/100000000ll);
		int v = (int)(str[i]%100ll);
		G[u][v]++;
		cost[u][v].pb(str[i]);
		rG[v][u]++;
		deg[u]++;
		deg[v]--;
		uf.unite(u,v);
		used[u]|=1;
		used[v]|=2;
	}
	int c = (int)(str[0]%100ll);
	for(int i=1;i<=100;i++){
		if(used[i]==0)continue;
		if(!uf.same(c,i)){
			printf("impossible\n");
			return 0;
		}
	}
	int s = -1,t = -1; 
	for(int i=0;i<100;i++){
		if(deg[i]>1||deg[i]<-1){
			printf("impossible\n");
			return 0;
		}else if(deg[i]==1){
			if(s!=-1){
				printf("impossible\n");
				return 0;
			}else{
				s = i;
			}
		}else if(deg[i]==-1){
			if(t!=-1){
				printf("impossible\n");
				return 0;
			}else{
				t = i;
			}
		}
	}
	if(!((s==-1&&t==-1)||(s!=-1&&t!=-1))){
		printf("impossible\n");
		return 0;
	}
	if(s==-1){
		for(int i=0;i<100;i++)if(used[i]&1){
			s=i;
			break;
		}
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			sort(all(cost[i][j]));
			idx[i][j]=0;
		}
	}
	memset(used,0,sizeof(used));
	flag = true;
	rdfs(s);
	int now = s;
	for(int i=0;i<N;i++){
		int to = -1;
		ll val = -1ll;
		for(int i=0;i<100;i++){
			if(G[now][i]==0)continue;
			if(!flag&&!used[i])continue;
			if(to==-1||val>cost[now][i][idx[now][i]]){
				to = i;
				val = cost[now][i][idx[now][i]];
			}
		}
		G[now][to]--;
		rG[to][now]--;
		idx[now][to]++;
		printf("%010lld\n",val);
		if(G[now][to]==0){
			memset(used,0,sizeof(used));
			flag = true;
			rdfs(to);
		}
		now = to;
	}
	return 0;
}