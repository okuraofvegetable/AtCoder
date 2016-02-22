#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
int m;
ll M;
ll p,q;
int A[30];
int cnt[1<<24];
ll sum(ll x){
	if(x<0)return 0ll;
	ll rem = x%(M+1);
	ll c = x/(M+1);
	return cnt[M]*c+cnt[rem];
}
int main(){
	scanf("%d",&m);
	scanf("%lld",&p);
	scanf("%lld",&q);
	p--;q--;
	int bin = 0;
	for(int i=0;i<m;i++){
		scanf("%d",&A[i]);
		A[i]%=2;
		bin|=(A[i]<<i);
		cnt[i]=A[i]+((i==0)?0:cnt[i-1]);
		//printf("%d ",cnt[i]);
	}
	int init = bin;
	M = m;
	while(1){
		int u = (bin&1)^(1&(bin>>(m-1)));
		bin = (bin>>1)|(u<<(m-1));
		cnt[M]=u+cnt[M-1];
		//printf("%d ",cnt[M]);
		if(bin==init)break;
		M++;
	}
	M-=m;
	//printf("\n");
	printf("%lld\n",sum(q)-sum(p-1));
	return 0;
}