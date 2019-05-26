#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> P;
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
ll a,b,c,n,m,x,y;
string s;
vector<T> vec;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		T a;
		cin >> a.fi.fi >> a.fi.sec;
		a.fi.sec *= -1;
		a.sec = i+1;
		vec.pb(a);
	}
	sort(all(vec));
	for(int i=0;i<n;i++){
		cout << vec[i].sec << endl;
	}
	return 0;
}
