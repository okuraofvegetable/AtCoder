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
int N,M[2],Q;
int T[2][200100],C[2][200100],D[2][200100];
ll X[2][100100],Y[2][100100];
ll h[2][100100];
int K;
ll now;
const int SIZE = 200100;
struct UnionFind{
	int par[SIZE],rank[SIZE],L[SIZE],R[SIZE];
	void init(){
		for(int i=0;i<SIZE;i++){
			par[i] = i;
			rank[i] = 0;
			if(i<N)L[i]=R[i]=i;
			else L[i]=R[i]=-1;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void merge(int a,int b){
		if(L[b]==-1)return;
		if(L[a]==-1){
			L[a]=L[b];
			R[a]=R[b];
			return;
		}
		if(R[a]<L[b]){
			h[K][R[a]]=now;
		}else{
			h[K][R[b]]=now;
		}
		L[a]=min(L[a],L[b]);
		R[a]=max(R[a],R[b]);
		return;
	}
	void unite(int a,int b){
		a = find(a);
		b = find(b);
		if(a==b)return;
		if(rank[a]<rank[b]){
			merge(b,a);
			par[a]=b;
		}
		else{
			par[b]=a;
			merge(a,b);
			if(rank[a]==rank[b])rank[a]++;
		}
		return;
	}
}uf;
vector<int> g[2][200100];
// 0...N-1 村 N...N+M[i]-1 
vector<int> hub;
bool comp(int a,int b){
	return Y[K][a]<Y[K][b];
}
vector<int> id[100100];
ll ans[100100];
int main(){
	scanf("%d %d %d %d",&N,&M[0],&M[1],&Q);
	for(int i=0;i<2;i++){
		for(int j=0;j<M[i];j++)scanf("%lld %lld",&X[i][j],&Y[i][j]);
		for(int j=0;j<N+M[i]-1;j++){
			scanf("%d %d %d",&T[i][j],&C[i][j],&D[i][j]);
			C[i][j]--;D[i][j]--;
			if(T[i][j]==1){
				g[i][N+D[i][j]].pb(C[i][j]);
			}else{
				if(i==0){
					if(Y[i][C[i][j]]<Y[i][D[i][j]]){
						g[i][N+D[i][j]].pb(N+C[i][j]);
					}else{
						g[i][N+C[i][j]].pb(N+D[i][j]);
					}
				}else{
					if(Y[i][C[i][j]]>Y[i][D[i][j]]){
						g[i][N+D[i][j]].pb(N+C[i][j]);
					}else{
						g[i][N+C[i][j]].pb(N+D[i][j]);
					}
				}
			}
		}
	}
	for(K=0;K<2;K++){
		uf.init();
		hub.clear();
		for(int i=0;i<M[K];i++)hub.pb(i);
		sort(all(hub),comp);
		if(K==1)reverse(all(hub));
		for(int i=0;i<M[K];i++){
			now = Y[K][hub[i]];
			int u = N+hub[i];
			for(int j=0;j<g[K][u].size();j++){
				int to = g[K][u][j];
				uf.unite(u,to);
			}
		}
	}
	/*for(int i=0;i<2;i++){
		for(int j=0;j<N-1;j++){
			printf("%lld ",h[i][j]);
		}
		printf("\n");
	}*/
	vector<ll> zip;
	for(int i=0;i<N-1;i++)zip.pb(h[0][i]);
	zip.pb(0);
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	int S = (int)zip.size();
	for(int i=0;i<N-1;i++){
		int k = lower_bound(all(zip),h[0][i])-zip.begin();
		id[k].pb(i);
	}
	ll cur = 0ll;
	for(int i=S-1;i>=0;i--){
		ans[i]=cur;
		for(int j=0;j<id[i].size();j++){
			cur = min(cur,h[1][id[i][j]]);
		}
	}
	/*for(int i=0;i<S;i++){
		printf("%lld%c",ans[i],(i==S-1)?'\n':' ');
	}*/
	for(int i=0;i<Q;i++){
		ll A;
		scanf("%lld",&A);
		int k = upper_bound(all(zip),A)-zip.begin();
		printf("%lld\n",ans[--k]);
	}
	return 0;
}
