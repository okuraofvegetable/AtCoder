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
const int B = 320;
string s;
int N;
int a[100100];
int c[320][100002];
const int SIZE = 1<<17;
struct segtree{
	int seg[SIZE*2];
	void update(int k,int x){
		k += SIZE-1;
		seg[k]=x;
		while(k>0){
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){ //[a,b)
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b)return seg[k];
		else{
			int mid = (l+r)/2;
			int lch = query(a,b,k*2+1,l,mid);
			int rch = query(a,b,k*2+2,mid,r);
			return min(lch,rch);
		}
	}
	int query(int a,int b){
		assert(a<b);
		return query(a,b,0,0,SIZE);
	}
}seg;
int cnt(int l,int r,int x){ //[l,r]
	int res = 0;
	if(l/B==r/B){
		for(int i=l;i<=r;i++){
			if(a[i]==x)res++;
		}
		return res;
	}
	while(l%B!=0){
		if(a[l]==x)res++;
		l++;
	}
	while(r%B<B-1){
		if(a[r]==x)res++;
		r--;
	}
	for(int i=l/B;i<=r/B;i++)res+=c[i][x];
	return res;
}
bool check(int l,int r){ //[l,r]
	r++;
	//cout << l << ' ' << r << endl;
	//cout << seg.query(l,r) << endl;
	return seg.query(l,r)>=a[l];
}
int main(){
	cin >> s;
	N = s.size();
	for(int i=0;i<N;i++){
		a[i+1]=a[i]+((s[i]=='(')?1:-1);
		c[(i+1)/B][a[i+1]]++;
		seg.update(i+1,a[i+1]);
		//cout << a[i+1] << ' ';
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		int l = i, r = N+1;
		while(r-l>1){
			int mid = (l+r)/2;
			if(check(i,mid))l = mid;
			else r = mid;
		}
		if(l>i)ans += cnt(i+1,l,a[i]);
		//cout << i << ' ' << l << ' ' << cnt(i+1,l,a[i]) << endl;
	}
	cout << ans << endl;
	return 0;
}