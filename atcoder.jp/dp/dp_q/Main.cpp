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
	ll seg[SIZE*2];
	void init(){
		for(int i=0;i<SIZE*2;i++)seg[i]=0;
	}
	void update(int k,ll x){
		k += SIZE-1;
		seg[k]=x;
		while(k){
			k = (k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return -LLINF;
		else if(a<=l&&r<=b)return seg[k];
		else return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
	ll query(int a,int b){
		if(a>=b)return 0ll;
		return query(a,b,0,0,SIZE);
	}
}seg;
int N;
int h[200100];
ll a[200100];
ll dp[200100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> h[i];
	for(int i=0;i<N;i++)cin >> a[i];
	seg.init();
	dp[0]=0ll;
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		dp[i+1]=seg.query(0,h[i])+a[i];
		seg.update(h[i],dp[i+1]);
		ans = max(ans,dp[i+1]);
		//cout << dp[i+1] << endl;
	}
	cout << ans << endl;
	return 0;
}