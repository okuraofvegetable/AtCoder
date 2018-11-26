#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
int N;
ll a[1010];
ll sum(int l,int r){ //[l,r]
	if(l==0)return a[r];
	else return a[r]-a[l-1];
}
ll X;
int dp1[1010];
int dp2[1010];
int rec2(int i);
int rec1(int i){
	if(dp1[i]!=-INF)return dp1[i];
	for(int j=i;j<N;j++){
		int f;
		if(sum(i,j)>=X)f = 1;
		else f = -1;
		dp1[i] = max(dp1[i],f+rec2(j+1));
	}
	return dp1[i];
}
int rec2(int i){
	if(dp2[i]!=INF)return dp2[i];
	for(int j=i;j<N;j++){
		int f;
		if(sum(i,j)>=X)f = 1;
		else f = -1;
		dp2[i] = min(dp2[i],f+rec1(j+1));
	}
	return dp2[i];
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<N;i++)a[i+1] += a[i];
	ll l = -1000000000001ll, r = 1000000000001ll;
	while(r-l>1ll){
		ll mid = (l+r)/2ll;
		X = mid;
		for(int i=0;i<N;i++){
			dp1[i]=-INF;
			dp2[i]=INF;
		}
		dp1[N]=0;
		dp2[N]=0;
		if(rec1(0)>=0)l=mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}