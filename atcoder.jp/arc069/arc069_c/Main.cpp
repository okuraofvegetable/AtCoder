#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
#define MAX_N 100100
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
}bit;
int N;
P a[100100];
ll ans[100100];
vector<P> vec;
int main(){
	cin >> N;
	ll pre = 0ll;
	for(int i=0;i<N;i++){
		cin >> a[i].fi;
		a[i].sec = i;
		if(pre<a[i].fi){
			vec.pb(a[i]);
			pre = a[i].fi;
		}
	}
	sort(a,a+N);
	int k=0;
	int M = vec.size();
	for(int i=0;i<vec.size();i++){
		while(k<N&&a[k].fi<vec[i].fi){
			bit.add(a[k].sec,a[k].fi);
			k++;
		}
		ans[vec[i].sec] = bit.sum(N-1)+(ll)(N-k)*vec[i].fi;
	}
	for(int i=M-2;i>=0;i--){
		ans[vec[i+1].sec]-=ans[vec[i].sec];
	}
	for(int i=0;i<N;i++)printf("%lld\n",ans[i]);
	return 0;
}