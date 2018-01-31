#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
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
string S;
int M;
int r[100100];
int main(){
	cin >> S;
	M = S.size();
	for(int i=M-1;i>=0;i--){
		r[i]=r[i+1];
		if(S[i]=='+')r[i]++;
		else if(S[i]=='-')r[i]--;
	}
	vector<int> vec;
	for(int i=0;i<M;i++){
		if(S[i]=='M'){
			vec.pb(r[i]);
		}
	}
	sort(all(vec));
	ll ans = 0ll;
	for(int i=0;i<vec.size();i++){
		if(i<(vec.size()/2))ans -= vec[i];
		else ans += vec[i];
		//cout << i << ' ' << ans << endl;
	}
	cout << ans << endl;
	return 0;
}