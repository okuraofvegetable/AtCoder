#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef pair<ll,P> T;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
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
ll n;
int m,q;
int a[100100];
int c[1400100];
void dfs(int x,int M){
	c[x]=0;
	if(x%7!=0){
		if(a[(x-1)%m]==0&&c[x-1]==-1)dfs(x-1,M);
	}
	if(x%7!=6){
		if(a[(x+1)%m]==0&&c[x+1]==-1)dfs(x+1,M);
	}
	if(x-7>=0){
		if(a[(x-7)%m]==0&&c[x-7]==-1)dfs(x-7,M);
	}
	if(x+7<M){
		if(a[(x+7)%m]==0&&c[x+7]==-1)dfs(x+7,M);
	}
}
ll cnt(int M){
	ll res=0ll;
	for(int i=0;i<M;i++)c[i]=-1;
	for(int i=0;i<M;i++){
		if(a[i%m])continue;
		if(c[i]==-1){
			dfs(i,M);
			res++;
		}
	}
	return res;
}
int main(){
	scanf("%lld %d %d",&n,&m,&q);
	for(int i=0;i<q;i++){
		int tmp;
		scanf("%d",&tmp);
		a[tmp]=1;
	}
	int M = m;
	if(m%7!=0)M*=7;
	ll l = 7ll*n/M;
	ll A = cnt(M);
	ll B = cnt(2*M);
	cout << A+(B-A)*(l-1ll) << endl;

	return 0;
}