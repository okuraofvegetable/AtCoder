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
struct UnionFind{
	int par[10010];
	void init(){
		for(int i=0;i<10010;i++)par[i]=i;
	}
	int find(int x){
		if(x==par[x])return x;
		else return find(par[x]);
	}
	void unite(int a,int b){
		a = find(a);
		b = find(b);
		if(a==b)return;
		par[a]=b;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
}uf;
int N,M,cnt;
int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	uf.init();
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		if(!uf.same(a,b)){
			uf.unite(a,b);
			cnt++;
		}
	}
	printf("%d\n",N-1-cnt);
	return 0;
}