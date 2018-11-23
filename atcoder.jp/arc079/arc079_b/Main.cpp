#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
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
ll K;
int main(){
	cin >> K;
	ll rem = K%50ll;
	ll a = K/50ll;
	vector<ll> ans;
	for(int i=0;i<50-rem;i++){
		ans.pb(49ll-rem);
	}
	for(int i=rem-1;i>=0;i--){
		ans.pb(50ll-i);
	}
	for(int i=0;i<ans.size();i++){
		ans[i]+=a;
	}
	cout << 50 << endl;
	for(int i=0;i<ans.size();i++){
		printf("%lld",ans[i]);
		if(i==ans.size()-1)printf("\n");
		else printf(" ");
	}
	return 0;
}