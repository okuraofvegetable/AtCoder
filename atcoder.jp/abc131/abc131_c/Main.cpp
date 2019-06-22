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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
ll mgcd(ll x,ll y){
	if(x==0ll)return y;
	else return mgcd(y%x,x);
}
ll A,B,C,D;
ll f(ll X){
	ll res = X/C+X/D;
	ll g = C/mgcd(C,D)*D;
	res -= X/g;
	return X -res;
}
int main(){
	cin >> A >> B >> C >> D;
	cout << f(B)-f(A-1) << endl;
	return 0;
}