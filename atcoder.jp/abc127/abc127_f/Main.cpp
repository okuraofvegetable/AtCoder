#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
const int SIZE = 1<<18;
struct segtree{
	ll maximum[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k){
		maximum[k]+=lazy[k];
		if(k<SIZE-1)// k isn't leaf of SegmentTree
		{
			lazy[2*k+1]+=lazy[k];
			lazy[2*k+2]+=lazy[k];
		}
		lazy[k]=0ll;
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
			maximum[k] = max(maximum[k*2+1],maximum[k*2+2]);
			return;
		}
	}
	ll query(int a,int b,int k,int l,int r){
		lazy_evaluate(k);
		if(r<=a||b<=l)return -LLINF; // min,max henkouji chuui !!!!!!!
		if(a<=l&&r<=b){
			return maximum[k];
		}else{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			return max(lch,rch);
		}
	}
}seg;
#define MAX_N 200100
struct BIT{
	ll bit[MAX_N+1];
	void add(int i,ll x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		i++;
		ll res=0ll;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	ll sum(int l,int r){// [l,r]
		if(l==0)return sum(r);
		else return sum(r)-sum(l-1);
	}
};
BIT cnt,rui;
int Q;
int type[200100],a[200100],b[200100];
vector<int> zip;
int main(){
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> type[i];
		if(type[i]==1){
			cin >> a[i] >> b[i];
			zip.pb(a[i]);
		}
	}
	zip.pb(-INF);
	zip.pb(INF);
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<Q;i++){
		a[i] = lower_bound(all(zip),a[i])-zip.begin();
	}
	int N = zip.size();
	ll base = 0ll;
	for(int i=0;i<Q;i++){
		if(type[i]==1){
			base += b[i];
			seg.update(0,a[i],0,0,SIZE,-1ll);
			seg.update(a[i],SIZE,0,0,SIZE,1ll);
			cnt.add(a[i],1);
			rui.add(a[i],zip[a[i]]);
		}else{
			int l = 0,r = N-1;
			while(r-l>1){
				int mid = (l+r)/2;
				if(seg.query(0,mid+1,0,0,SIZE)<0ll)l=mid;
				else r=mid;
			}
			ll ans = zip[r]*cnt.sum(0,r-1)-rui.sum(0,r-1)+rui.sum(r+1,N)-zip[r]*cnt.sum(r+1,N);
			cout << zip[r] << ' ' << ans+base << endl;
		}
	}
	return 0;
}
