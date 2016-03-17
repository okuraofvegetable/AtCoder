#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 1<<17;
struct segtree{
	ll seg[SIZE*2];
	void update(int k,ll x){
		k += SIZE-1;
		seg[k]=x;
		while(k){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return 0;
		else if(a<=l&&r<=b)return seg[k];
		else{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			return max(lch,rch);
		}
	}
	ll query(int a,int b){
		return query(a,b,0,0,SIZE);
	}
	ll all(){
		return query(0,SIZE);
	}
}seg;
int N;
ll A[100100];
int main(){
	scanf("%d",&N);
	ll sum = 0ll;
	for(int i=1;i<=N;i++){
		scanf("%lld",&A[i]);
		sum += A[i]*2ll;
	}
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		ll ret = seg.query(0,x)+A[x];
		seg.update(x,ret);
	}
	printf("%lld\n",sum-seg.all()*2ll);
	return 0;
}