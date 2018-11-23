#include <bits/stdc++.h>
using namespace std;
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
int a[33];
int b[33];
ll L;
ll mygcd(ll a,ll b){
	if(b==0ll)return a;
	return mygcd(b,a%b);
}
ll mylcm(ll a,ll b){
	return a/mygcd(a,b)*b;
}
int main(){
	for(int i=2;i<=30;i++)cin >> a[i];
	b[29]=a[30];
	for(int i=28;i>=2;i--)b[i]=a[i+1]%i;
	L = 1ll;
	for(int i=2;i<=15;i++){
		L = mylcm(L,(ll)i);
	}
	ll ans = 0;
	for(int i=1;i<=L;i++){
		bool flag = true;
		ans = i;
		for(int j=1;j<15;j++){
			if(b[j]!=i%j){
				flag = false;
				break;
			}
		}
		if(flag)break;
		if(i==L)ans = -1ll;
	}
	if(ans==-1){
		printf("invalid\n");
		return 0;
	}
	while(ans<=1000000000000ll){
		bool flag = true;
		for(int i=2;i<=30;i++){
			ll ret = ans;
			int k = 0ll;
			while(ret>0ll){
				k+=(int)(ret%(ll)i);
				ret/=(ll)i;
			}
			if(a[i]!=k){
				flag = false;
				break;
			}
		}
		if(flag){
			printf("%lld\n",ans);
			return 0;
		}
		ans += L;
	}
	printf("invalid\n");
	return 0;
}