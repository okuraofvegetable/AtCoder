#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000ll
#define LLINF 2000000000000000000ll
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
int X[200100];
vector<int> vec;
int N;
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> X[i];
		vec.pb(X[i]);
	}
	sort(all(vec));
	for(int i=0;i<N;i++){
		if(X[i]<vec[N/2])cout << vec[N/2] << endl;
		else cout << vec[N/2-1] << endl;
	}
	return 0;
}