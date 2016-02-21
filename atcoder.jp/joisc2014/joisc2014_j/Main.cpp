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
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M;
vector<int> g[100100];
int par[100100],depth[100100];
bool used[100100];
int odd[100100],even[100100];
int odd_cnt=0,ans=0;
map<int,int> m;
void dfs(int v,int p,int d){
	//printf("%d %d %d\n",v,p,d);
	used[v]=true;
	depth[v]=d;
	par[v]=p;
	int c=0;
	for(int i=0;i<g[v].size();i++){
		int to = g[v][i];
		if(to==p&&c==0){
			c++;
			continue;
		}
		if(!used[to]){
			dfs(to,v,d+1);
		}else{
			if(depth[to]>depth[v])continue;
			int len = depth[v]-depth[to]+1;
			if(len%2==0){
				even[v]++;
				even[to]--;
			}else{
				//printf("%d %d\n",v,to);
				odd_cnt++;
				odd[v]++;
				odd[to]--;
			}
		}
	}
}
void culc(int v){
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		int to = g[v][i];
		if(!used[to]){
			culc(to);
			even[v]+=even[to];
			odd[v]+=odd[to];
		}
	}
}
int a[200100],b[200100];
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;b[i]--;
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	for(int i=0;i<N;i++)if(!used[i]){
		dfs(i,-1,0);
	}
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++)if(!used[i]){
		culc(i);
	}
	//printf("%d\n",odd_cnt);
	/*for(int i=0;i<N;i++){
		printf("%d %d\n",odd[i],even[i]);
	}*/
	if(odd_cnt==1)ans++;
	for(int i=0;i<M;i++){
		if(depth[a[i]]<depth[b[i]])swap(a[i],b[i]);
		if(depth[a[i]]-depth[b[i]]==1){
			if(even[a[i]]==0&&odd[a[i]]==odd_cnt)ans++;
		}
	}
	printf("%d\n",ans);
	return  0;
}