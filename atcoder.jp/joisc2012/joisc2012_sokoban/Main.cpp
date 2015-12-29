#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
char f[1005][1005];
vector<int> g[1000010];
int root,K=0;
int chnum[1000010],low[1000010],ord[1000010],fin[1000010],upper[1000010];
int par[1000010],pv[1000010][4];
bool used[1000010];
bool vis[1000010][4];
void dfs(int v,int p){
	used[v]=true;
	par[v]=p;
	low[v]=ord[v]=K++;
	chnum[v]=1;
	for(int i=0;i<g[v].size();i++){
		int to = g[v][i];
		if(!used[to]){
			dfs(to,v);
			chnum[v]+=chnum[to];
			low[v]=min(low[v],low[to]);
		}else if(to!=p){
			low[v]=min(low[v],ord[to]);
		}
	}
	fin[v]=K++;
}
bool des(int u,int v){// u is v's descendant or (u==v)
	return (ord[v]<=ord[u]&&fin[u]<=fin[v]);
}
int down(int u,int v){// u's child which is v's ancestor
	int res = -1;
	for(int i=0;i<g[u].size();i++){
		if(par[g[u][i]]!=u)continue;
		if(des(v,g[u][i])){
			res = g[u][i];
			break;
		}
	}
	return res;
}
bool cut(int u,int a,int b){//if u is erased , are a & b connected ?
	if(!des(a,u)&&!des(b,u))return true;
	else if(des(a,u)&&!des(b,u)){
		return (low[down(u,a)]<ord[u]);
	}else if(!des(a,u)&&des(b,u)){
		return (low[down(u,b)]<ord[u]);
	}else{
		int ca = down(u,a),cb = down(u,b);
		if(ca==cb)return true;
		else if(low[ca]<ord[u]&&low[cb]<ord[u])return true;
		else return false;
	}
}
void debug(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",i*m+j);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",ord[i*m+j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",low[i*m+j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",chnum[i*m+j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",upper[i*m+j]);
		}
		printf("\n");
	}
	
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf(" %c",&f[i][j]);
			if(f[i][j]=='X')root = i*m+j;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int v = i*m+j;
			for(int k=0;k<4;k++){
				int ni=i+dx[k],nj=j+dy[k];
				if(ni<0||ni>=n||nj<0||nj>=m)pv[v][k]=-1;
				else if(f[ni][nj]=='#')pv[v][k]=-1;
				else pv[v][k]=ni*m+nj;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[i][j]=='#')continue;
			for(int k=0;k<4;k++){
				int ni = i+dx[k],nj = j+dy[k];
				if(ni<0||ni>=n||nj<0||nj>=m)continue;
				if(f[ni][nj]=='#')continue;
				g[i*m+j].pb(ni*m+nj);
			}
		}
	}
	dfs(root,-1);
	for(int i=0;i<n*m;i++){
		if(!used[i])continue;
		upper[i]=chnum[root]-2;
		for(int j=0;j<g[i].size();j++){
			if(par[i]==g[i][j])continue;
			if(par[g[i][j]]==i)upper[i]-=chnum[g[i][j]];
		}
	}
	//debug();
	queue<P> q;
	for(int i=0;i<4;i++){
		if(pv[root][i]!=-1)q.push(P(root,i));
	}
	ll ans = 0ll;
	while(!q.empty()){
		P a = q.front();q.pop();
		int v = a.fi,dir = a.sec;
		if(vis[v][dir])continue;
		//printf("%d %d\n",v,dir);
		for(int i=0;i<4;i++){
			if(pv[v][i]==-1)continue;
			if(cut(v,pv[v][dir],pv[v][i])){
				if(v!=root){
					//printf("v %d i %d\n",v,i);
					if(pv[v][i]==par[v]){
						ans += upper[v];
						//printf("+%d\n",upper[v]);
					}else if(par[pv[v][i]]==v){
						ans += chnum[pv[v][i]];
						//printf("+%d\n",chnum[pv[v][i]]);
					}
				}
				vis[v][i]=true;
				if(pv[pv[v][i]][i]!=-1){
					q.push(P(pv[v][i],i));
				}
			}
		}
		//printf("%lld\n",ans);		
	}
	printf("%lld\n",ans);
	return 0;
}