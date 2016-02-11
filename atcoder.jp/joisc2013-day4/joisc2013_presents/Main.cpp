#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
const int SZ = 100100;
int N;
int A[SZ];
ll B[SZ],C[SZ],D[SZ];
bool used[SZ];
vector<int> G[SZ],rG[SZ];
vector<int> vs;
vector<int> app[SZ];
void add_edge(int from,int to){
	G[from].pb(to);
	rG[to].pb(from);	
}
void dfs(int v){
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]])dfs(G[v][i]);
	}
	vs.pb(v);
}
void rdfs(int v,int k){
	used[v]=true;
	app[k].pb(v);
	for(int i=0;i<rG[v].size();i++){
		if(!used[rG[v][i]])rdfs(rG[v][i],k);
	}
}
int scc(){
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++)if(!used[i])dfs(i);
	reverse(all(vs));
	memset(used,false,sizeof(used));
	int k = 0;
	for(int i=0;i<vs.size();i++){
		if(!used[vs[i]])rdfs(vs[i],k++);
	}
	return k;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %lld %lld %lld",&A[i],&B[i],&C[i],&D[i]);
		A[i]--;
		add_edge(i,A[i]);
	}
	int m = scc();
	/*for(int i=0;i<m;i++){
		for(int j=0;j<app[i].size();j++){
			printf("%d ",app[i][j]);
		}
		printf("\n");
	}*/
	ll ans = 0ll;
	for(int i=0;i<m;i++){
		if(sz(app[i])==1){
			int f = app[i][0];
			int to = A[f];
			ans += B[f]*max(C[to],D[to]);
			//printf("%d %d %lld\n",f,to,B[f]*max(C[to],D[to]));
		}else{
			vector<ll> vec;
			for(int j=0;j<sz(app[i]);j++){
				int f = app[i][j];
				int to = A[f];
				ans += B[f]*C[to];
				//printf("%d %d %lld\n",f,to,B[f]*C[to]);
				vec.pb((D[to]-C[to])*B[f]);
			}
			sort(all(vec),greater<ll>());
			for(int j=1;j<vec.size();j++)vec[j]+=vec[j-1];
			ll add = 0ll;
			for(int j=1;j<vec.size();j+=2)add = max(add,vec[j]);
			ans += add;
			//printf("add %lld\n",add);
		}
	}
	printf("%lld\n",ans);
	return 0;
}