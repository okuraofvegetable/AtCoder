#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
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
#define MAX_N 200100
struct BIT{
	ll bit[MAX_N+1];
	void init(){
		memset(bit,0,sizeof(bit));
	}
	void add(int i,ll x){
		assert(i>=0);
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		if(i<0)return 0ll;
		i++;
		ll res=0;
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
}bit,cnt;
int N;
ll M;
int a[100100];
const int GETA = 100000;
bool check(int x){
	bit.init();
	cnt.init();
	ll s = 0ll;
	for(int i=0;i<N;i++){
		if(a[i]>x)bit.add(i,-1);
		else bit.add(i,1);
	}
	cnt.add(GETA,1);
	for(int i=0;i<N;i++){
		cnt.add(GETA+bit.sum(i),1);
		s += cnt.sum(GETA+bit.sum(i)-1);
	}
	//cout << s << endl;
	return s>=(M/2+1);
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	M = N;
	M = M*(M-1)/2ll+M;
	int l = 0, r = 1000000000;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}