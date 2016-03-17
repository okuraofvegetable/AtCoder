#include <bits/stdc++.h>
using namespace std;
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
const int SIZE = 1010;
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
};
UnionFind uf[10010];
int N,M,K;
struct train{
	int A,B,C,id;
	train(){}
	train(int A,int B,int C,int D):A(A),B(B),C(C),id(D){}
	bool operator < (const train& a) const{
		return C > a.C;
	}
};
vector<train> vec;
int to[300100];
int main(){
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int A,B,C;
		scanf("%d %d %d",&A,&B,&C);
		vec.pb(train(A,B,C,i));
	}
	sort(all(vec));
	for(int i=1;i<=K;i++)uf[i].init(N+5);
	for(int i=0;i<M;i++){
		train t = vec[i];
		int l=0,r=K+1;
		while(r-l>1){
			int mid = (l+r)/2;
			if(!uf[mid].same(t.A,t.B))r=mid;
			else l = mid;
		}
		if(r<K+1){
			to[t.id]=r;
			uf[r].unite(t.A,t.B);
		}
	}
	for(int i=0;i<M;i++)printf("%d\n",to[i]);
	return 0;
}