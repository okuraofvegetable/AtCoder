#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
struct UnionFind{
	int par[1010],rank[1010];
	UnionFind(){
		for(int i=0;i<1010;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		if(x==par[x])return x;
		else return par[x]=find(par[x]);
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
int N;
int C[1010][1010];
bool con[1010][1010];
int type[1010];
int f1 = 0,f2 = 0;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&type[i]);
		if(type[i]==1)f1++;
		if(type[i]==2)f2++;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&C[i][j]);
		}	
	}
	int cnt = 0,cost = 0;
	if(f1){
		for(int i=0;i<N;i++){
			if(type[i]!=1)continue;
			for(int j=0;j<N;j++){
				if(i==j)continue;
				if(!con[i][j]){
					con[i][j]=con[j][i]=true;
					cost+=C[i][j];
					cnt++;
				}
			}
		}
		printf("%d %d\n",cnt,cost);
	}else if(f2){
		cost = INF;
		for(int i=0;i<N;i++){
			int res = 0,idx = -1;;
			for(int j=0;j<N;j++){
				res += C[i][j];
				if(i!=j&&type[j]==2)idx=j;
			}
			if(type[i]==2){
				int rd = f2-1;
				if(rd==1){
					for(int j=0;j<N;j++){
						if(type[j]==2)continue;
						if(C[i][j]>C[idx][j]){
							res -= C[i][j];
							res += C[idx][j];
						}
					}
				}
			}
			cost = min(cost,res);
		}
		printf("%d %d\n",N-1,cost);
	}else{
		vector<T> es;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				es.pb(T(C[i][j],P(i,j)));
			}
		}
		sort(all(es));
		for(int i=0;i<es.size();i++){
			T e = es[i];
			if(!uf.same(e.sec.fi,e.sec.sec)){
				uf.unite(e.sec.fi,e.sec.sec);
				cost += e.fi;
			}
		}
		printf("%d %d\n",N-1,cost);
	}
	return 0;
}