#include<bits/stdc++.h>
using namespace std;
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
int n;
int a[100100];
long double func(int x){
	return ((long double)x-2.0)*logl((long double)x-1.0);
}
long double f(int i,int j){
	if(i<=j)return -2.0;
	if(i==0||j==0)return -0.0;
	return func(i)-func(j)-func(i-j);
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	int b = -1,c = -1;
	long double mx = -2.0;
	for(int i=0;i<n;i++){
		int k = lower_bound(a,a+n,a[i]/2)-a;
		for(int j=max(0,k-3);j<min(n,k+3);j++){
			long double ret = f(a[i],a[j]);
			//cout << i << ' ' << j << endl;
			if(ret>mx){
				b = i;
				c = j;
				mx = ret;
			}
		}
	}
	cout << a[b] << ' ' << a[c] << endl;
	return 0;
}
