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
int N,M;
int x[500],y[500];
int col[50],cnt[20];
const int SIZE = 25;
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
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d",&x[i],&y[i]);
		x[i]--;y[i]--;
	}
	int ans = 0;
	for(int i=0;i<(1<<N);i++){
		//printf("%d:\n",i);
		uf.init(20);
		for(int j=0;j<N;j++){
			if((i>>j)&1)col[j]=1;
			else col[j]=0;
			cnt[j]=0;
		}
		for(int j=0;j<M;j++){
			if(col[x[j]]!=col[y[j]]){
				cnt[x[j]]++;
				cnt[y[j]]++;
				uf.unite(x[j],y[j]);
			}	
		}
		bool flag = true;
		for(int j=1;j<N;j++){
			if(!uf.same(0,j)){
				flag =false;
				break;
			}
		}
		if(!flag)continue;
		for(int j=0;j<N;j++){
			//printf("%d ",cnt[j]);
			if(cnt[j]==0){
				flag=false;
				break;
			}
		}
		if(flag){
			//printf("%d\n",i);
			ans++;
		}
	}
	printf("%d\n",ans/2);
	return 0;
}