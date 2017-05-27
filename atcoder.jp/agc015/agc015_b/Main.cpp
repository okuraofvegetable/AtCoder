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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
string s;
ll N;
ll u[100100];
ll d[100100];
ll ans = 0ll;
int main(){
	cin >> s;
	N = (ll)s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]=='U')u[i]++;
		else d[i]++;
	}
	for(int i=1;i<(int)s.size();i++){
		u[i]+=u[i-1];
		d[i]+=d[i-1];
	}
	for(int i=(int)s.size()-1;i>0;i--){
		if(s[i]=='U'){
			ans += u[i-1]*3ll;
			ans += d[i-1]*4ll;
		}else{
			ans += u[i-1]*2ll;
			ans += d[i-1]*3ll;
		}
	}
	cout << ans << endl;
	return 0;
}