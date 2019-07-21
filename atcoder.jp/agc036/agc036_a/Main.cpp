#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define dump(X) cout << #X << ' ' << X << endl
#define pe(X) cout << X << endl
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int main(){
	ll x;
	cin >> x;
	cout << 0  << ' ' << 0  <<  ' ';
	if(x<=1000000000ll){
		cout << x  << ' ' << 0  <<  ' ';
		cout << 0  << ' ' << 1  <<  endl;
	}else if(x<1000000000000000000ll){
			ll y = x/1000000000ll+1ll;
			cout << 1000000000ll <<  ' ' << 1 << ' ';
			cout << 1000000000ll*y-x << ' ' << y << endl;
	
	}else{
		cout << 1000000000ll << ' ' << 0 << ' ';
		cout << 0 << ' ' << 1000000000ll << endl;
	}
	return 0;
}