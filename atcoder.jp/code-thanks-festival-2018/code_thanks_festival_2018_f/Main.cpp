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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M,K;
int p[305];
vector<int> g[305];
int root;
int depth[305];
int child[305];
int edge[305];
bool used[305];
void dfs(int v,int p,int d){
	child[v]=1;
	depth[v]=d;
	for(int i=0;i<g[v].size();i++){
		if(p==g[v][i])continue;
		dfs(g[v][i],v,d+1);
		child[v]+=child[g[v][i]];
	}
}
void check(int v,int p){
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==p)continue;
		check(g[v][i],v);
	}
}
void print(int* a){
	for(int i=0;i<N;i++)printf("%d ",a[i]);
	printf("\n");
}
void debug(){
	printf("depth: ");
	print(depth);
	printf("child: ");
	print(child);
	printf("edge : ");
	print(edge);
}
vector<int> vec;
void dfs_check(int v,int p,int sel){
	if(v==sel)return;
	vec.pb(depth[v]);
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==p||g[v][i]==sel||used[g[v][i]])continue;
		dfs_check(g[v][i],v,sel);
	}
}
int main(){
	cin >> N >> M >> K;
	for(int i=0;i<N;i++){
		cin >> p[i];
		p[i]--;
		if(p[i]!=-1)g[p[i]].pb(i);
		else root = i;
	}
	dfs(root,-1,0);
	int size = N;
	int rK = K;
	vector<int> ans;
	//debug();
	for(int i=0;i<M;i++){
		int res = -1;
		int nK,rc,ns,ne;
		for(int j=0;j<N;j++){
			if(used[j])continue;
			if(rK<depth[j]+1)continue;
			nK = rK-depth[j]-1;
			rc = M-i-1;
			vec.clear();
			dfs_check(root,-1,j);
			ns = vec.size();
			if(ns<rc)continue;
			sort(all(vec),greater<int>());
			ne=0;
			int mi = 0;
			for(int i=0;i<rc;i++)ne+=vec[i];
			for(int i=0;i<rc;i++)mi+=vec[ns-1-i];
			//if(i==M-1)printf("j: %d nK: %d rc: %d ns: %d ne: %d\n",j,nK,rc,ns,ne);
			if(((rc>0)&&(nK-rc>=mi&&nK-rc<=ne))||((rc==0)&&(nK==0))){
				res = j;
				//printf("nK: %d rc: %d ns: %d ne: %d\n",nK,rc,ns,ne);
				break;
			}
		}
		//cout << size << ' ' << e << ' ' << rK << endl;
		//cout << res+1 << endl;
		if(res==-1){
			printf("-1\n");
			return 0;
		}
		size = ns;
		rK = nK;
		check(res,p[res]);
		int v = p[res];
		while(v!=-1){
			child[v]-=child[res];
			edge[v]-=edge[res];
			v = p[v];
		}
		ans.pb(res);
		//debug();
	}
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]+1);
		if(i+1<ans.size())printf(" ");
		else printf("\n");
	}
	return 0;
}