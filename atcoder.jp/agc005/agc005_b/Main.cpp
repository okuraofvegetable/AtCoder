#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
const int SIZE = 1<<20;
struct RMQ{
	int seg[SIZE*2];
	void update(int k,int x){
		k += SIZE-1;
		seg[k]=x;
		while(k){
			k = (k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b)return seg[k];
		else return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
	int query(int a,int b){
		return query(a,b,0,0,SIZE);
	}
}seg;

int N;
int a[200100];
int search_R(int i){
	int l = i,r = N;
	while(r-l>1){
		int mid = (l+r)/2;
		if(seg.query(i,mid+1)<a[i])r=mid;
		else l=mid;
	}
	return l;
}
int search_L(int i){
	int l = -1,r = i;
	while(r-l>1){
		int mid = (l+r)/2;
		if(seg.query(mid,i+1)<a[i])l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
		seg.update(i,a[i]);
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		int L = search_L(i);
		int R = search_R(i);
		ans += (ll)(i-L+1)*(ll)(R-i+1)*(ll)a[i];
	}
	cout << ans << endl;
	return 0;
}