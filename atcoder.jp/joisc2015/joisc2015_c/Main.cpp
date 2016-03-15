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
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const int SIZE = 1<<17;
struct segtree{
	ll seg[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k){
		seg[k]+=lazy[k];
		if(k<SIZE-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int k,int l,int r,ll x){
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]+=x;
			lazy_evaluate(k);
		}else{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		lazy_evaluate(k);
		if(r<=a||b<=l)return -LLINF;
		else if(a<=l&&r<=b)return seg[k];
		else{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
			return max(lch,rch);
		}
	}
	void update(int a,int b,ll x){
		update(a,b,0,0,SIZE,x);
	}
	ll query(int a,int b){
		if(a>=b)return 0ll;
		return query(a,b,0,0,SIZE);
	}
}segL,segR;
int N;
int H[100100],B[100100],C[100100];
vector<int> zip;
ll dpL[100100],dpR[100100];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&H[i],&B[i],&C[i]);
		zip.pb(H[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	int M = zip.size();
	for(int i=0;i<N;i++){
		H[i]=lower_bound(all(zip),H[i])-zip.begin();
	}
	for(int i=0;i<N;i++){
		ll res = segL.query(0,H[i]+1)+B[i];
		ll des = segL.query(H[i],H[i]+1);
		if(res>des)segL.update(H[i],H[i]+1,res-des);
		segL.update(0,H[i],-C[i]);
		dpL[i]=segL.query(0,M);
		
	}
	for(int i=N-1;i>=0;i--){
		ll res = segR.query(0,H[i]+1)+B[i];
		ll des = segR.query(H[i],H[i]+1);
		if(res>des)segR.update(H[i],H[i]+1,res-des);
		segR.update(0,H[i],-C[i]);
		dpR[i]=segR.query(0,M);
	}
	ll ans = dpR[0];
	for(int i=0;i<N;i++)ans = max(ans,dpL[i]+dpR[i+1]);
	printf("%lld\n",ans);
	return 0;
}