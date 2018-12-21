#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
int n,m;
int a[100100];
ll b[100100];
int l[100100],r[100100];
int d(int i){
	return (a[i+1]+m-a[i])%m;
}
int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]--;
	}
	for(int i=0;i<n-1;i++){
		r[a[i+1]]++;
		l[a[i]]++;
		b[a[i+1]]+=d(i)-1;
	}
	int k=0;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1] || a[i]==0)k++;
	}
	ll now = 0ll;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1])now+=a[i+1]+1;
		else now += a[i+1]-a[i];
	}
	ll ans = now;
	//cout << k << ' ' << now << endl;
	for(int x=1;x<m;x++){
		now = now-(k-l[x-1]-r[x-1])+b[x-1];
		k = k-r[x-1]+l[x];
		ans = min(ans,now);
		//cout << k << ' ' << now << endl;
	}
	cout << ans << endl;
	return 0;
}