#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M;
int a[100100],b[100100];
vector<int> g[100100];
map<P,int> m;
bool used[100100];
int c[100100];
int par[100100];
int depth[100100];
bool isroot[100100];
void add_edge(int a,int b){
	g[a].pb(b);
	g[b].pb(a);
}
void dfs(int v,int p,int d){
	//printf("%d %d %d\n",v,p,d);
	used[v] = true;
	par[v] = p;
	depth[v] = d;
 	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(u==p)continue;
		if(used[u]){
			if(depth[u]<depth[v]){
				c[u]--;
				c[v]++;
			}
		}else{
			dfs(u,v,d+1);
		}
	}
}
void dfs2(int v){
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(depth[u]!=depth[v]+1)continue;
		dfs2(u);
		c[v] += c[u];
	}
}
void debug(){
	for(int i=0;i<N;i++){
		printf("c[%d]=%d\n",i,c[i]);
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;b[i]--;
		if(a[i]>b[i])swap(a[i],b[i]);
		m[P(a[i],b[i])]++;
	}
	for(map<P,int>::iterator it=m.begin();it!=m.end();it++){
		if((it->sec)%2==1){
			add_edge((it->fi).fi,(it->fi).sec);
		}
	}
	for(int i=0;i<N;i++){
		if(!used[i]){
			isroot[i]=true;
			dfs(i,-1,0);
		}
	}
	for(int i=0;i<N;i++){
		if(isroot[i])dfs2(i);
	}
	//for(int i=0;i<N;i++)cout << par[i] << endl;
	for(int i=0;i<N;i++){
		//cout << c[i] << endl;
		if(isroot[i])continue;
		if(c[i]%2==0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}