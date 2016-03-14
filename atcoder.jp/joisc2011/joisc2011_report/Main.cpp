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
const int SIZE = 114514;
struct BIT{
	int bit[4*SIZE+100];
	void add(int i,int x){
		i++;
		while(i<=4*SIZE){
			bit[i]+=x;
			i += i&-i;
		}
	}
	int sum(int i){
		i++;
		int res = 0;
		while(i){
			res += bit[i];
			i -= i&-i;
		}
		return res;
	}
	int sum(int a,int b){
		if(a==0)return sum(b);
		else return sum(b)-sum(a-1);
	}
}bit;
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
int N,idx=0;
int to[100100];
int cmp[100100];
bool used[100100];
vector<int> root;
vector<int> g[100100];
vector<int> vs;
int beg[100100],end[100100]; //[ beg,end ]
void press(int v,int k){
	used[v]=true;
	cmp[v]=k;
	if(!used[to[v]])press(to[v],k);
}
void build_tree(){
	for(int i=0;i<N;i++){
		int par = cmp[to[i]];
		int ch = cmp[i];
		if(par==ch)continue;
		g[par].pb(ch);
	}
}
void dfs(int v){
	vs.pb(v);
	beg[v]=idx++;
	for(int i=0;i<g[v].size();i++){
		dfs(g[v][i]);
		vs.pb(v);
		idx++;
	}
	end[v]=idx-1;
}
int main(){
	scanf("%d",&N);
	uf.init(N);
	for(int i=0;i<N;i++){
		scanf("%d",&to[i]);
		to[i]--;
		cmp[i]=i;
		if(uf.same(i,to[i])){
			root.pb(i);
		}else{
			uf.unite(i,to[i]);
		}
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<root.size();i++)press(root[i],root[i]);
	for(int i=0;i<N;i++){
		to[i]=cmp[to[i]];
		//printf("%d %d\n",i,to[i]);
	}
	build_tree();
	memset(used,false,sizeof(used));
	for(int i=0;i<root.size();i++)dfs(root[i]);
	/*for(int i=0;i<vs.size();i++){
		printf("%d ",vs[i]);
	}
	printf("\n");
	for(int i=0;i<N;i++){
		printf("%d %d\n",beg[i],end[i]);
	}*/
	for(int i=0;i<N;i++){
		int c = cmp[i];
		printf("%d\n",bit.sum(beg[c],end[c]));
		bit.add(beg[c],1);
	}
	return 0;
}