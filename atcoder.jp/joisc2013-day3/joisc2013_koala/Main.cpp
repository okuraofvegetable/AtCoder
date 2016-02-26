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
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 1<<17;
struct segtree{
	ll seg[SIZE*2];
	segtree(){
		for(int i=0;i<SIZE*2;i++)seg[i]=-LLINF;
	}
	void update(int k,ll x){
		k += SIZE-1;
		if(seg[k]>=x)return;
		seg[k]=x;
		while(k>0){
			k = (k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return -LLINF;
		else if(a<=l&&r<=b)return seg[k];
		else{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			return max(lch,rch);
		}
	}
	ll query(int a,int b){
		if(a>=b)return -LLINF;
		return query(a,b,0,0,SIZE);
	}
};
segtree seg;
ll K,M,D,A,N;
ll T[100100],B[100100];
ll p[100100],q[100100];
ll dp[100100];
vector<ll> zip;
int main(){
	scanf("%lld %lld %lld %lld %lld",&K,&M,&D,&A,&N);
	for(int i=1;i<=N;i++)scanf("%lld %lld",&T[i],&B[i]);
	T[0]=K;B[0]=0;
	T[N+1]=M;B[N+1]=0;
	N+=2;
	for(int i=0;i<N;i++){
		p[i]=T[i]/D;
		q[i]=T[i]%D;
		zip.pb(q[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<N;i++){
		q[i]=lower_bound(all(zip),q[i])-zip.begin();
	}
	dp[0]=0ll;
	seg.update(q[0],p[0]*A);
	for(int i=1;i<N;i++){
		ll ca = seg.query(q[i],SIZE)-A*p[i]+B[i];
		ll cb = seg.query(0,q[i])-A*p[i]-A+B[i];
		dp[i]=max(ca,cb);
		seg.update(q[i],dp[i]+p[i]*A);
	}
	printf("%lld\n",dp[N-1]);
	return 0;
}