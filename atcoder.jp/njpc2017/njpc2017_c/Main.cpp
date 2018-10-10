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
const int SIZE = 1<<17;
struct segtree{
	ll seg[SIZE*2];
	void init(){
		for(int i=0;i<SIZE*2;i++)seg[i]=LLINF;
	}
	void update(int k,ll x){
		k += SIZE-1;
		seg[k] = x;
		while(k){
			k/=2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return LLINF;
		else if(a<=l&&r<=b)return seg[k];
		else{
			int mid = (l+r)/2;
			ll lch = query(a,b,k*2+1,l,mid);
			ll rch = query(a,b,k*2+2,mid,r);
			return min(lch,rch);
		}
	}
	ll query(int a,int b){
		if(a>=b)return LLINF;
		return query(a,b,0,0,SIZE);
	}
}seg;
int N;
ll L;
ll x[100100];
ll dp[100100];
int main(){
	seg.init();
	scanf("%d %lld",&N,&L);
	x[0]=-2;
	for(int i=1;i<=N;i++){
		scanf("%lld",&x[i]);
		x[i]*=2ll;
	}
	x[N+1]=LLINF;
	L*=2ll;
	/*for(int i=0;i<=N;i++){
		printf("%lld ",x[i]);
	}
	printf("\n");*/
	seg.update(0,0);
	for(int i=1;i<=N;i++){
		int l = upper_bound(x,x+i,x[i]-L)-x;
		int r = i;
		//cout << l << ' ' << r << endl;
		ll ret = seg.query(l,r);
		//cout << ret << endl;
		if(l>0){
			ret = min(ret,max(seg.query(l-1,l),x[i]-L+1ll));
		}
		if(ret!=LLINF)ret+=2ll*L;
		//printf("%d : %lld\n",i,ret);
		if(ret<x[i+1])seg.update(i,ret);
	}
	if(seg.query(N,N+1)!=LLINF)printf("YES\n");
	else printf("NO\n");
	return 0;
}