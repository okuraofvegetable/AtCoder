#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int A,B,Q;
ll s[100100],t[100100];
int main(){
	cin >> A >> B >> Q;
	for(int i=0;i<A;i++)cin >> s[i];
	for(int i=0;i<B;i++)cin >> t[i];
	for(int i=0;i<Q;i++){
		ll x;
		cin >> x;
		int a = lower_bound(s,s+A,x)-s;
		int b = lower_bound(t,t+B,x)-t;
		ll ans = LLINF;
		for(int j=max(0,a-1);j<=min(A-1,a);j++){
			for(int k=max(0,b-1);k<=min(B-1,b);k++){
				ans = min(ans,abs(x-s[j])+abs(s[j]-t[k]));
				ans = min(ans,abs(x-t[k])+abs(t[k]-s[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}