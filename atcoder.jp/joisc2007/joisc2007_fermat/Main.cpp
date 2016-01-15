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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int n,p;
int mpow(int a,int x){
	int res = 1;
	while(x){
		if(x&1)res = (res*a)%p;
		a = (a*a)%p;
		x >>= 1;
	}
	return res;
}
int cnt[10010];
int main(){
	scanf("%d %d",&p,&n);
	for(int i=0;i<p;i++)cnt[mpow(i,n)]++;
	ll ans = 0ll;
	for(int i=0;i<p;i++){
		ans += (ll)cnt[i]*(ll)cnt[i]*(ll)cnt[(i+i)%p];
		for(int j=i+1;j<p;j++){
			int k = (i+j)%p;
			ans += 2ll*(ll)cnt[i]*(ll)cnt[j]*(ll)cnt[k];
		}
	}
	printf("%lld\n",ans);
	return 0;
}