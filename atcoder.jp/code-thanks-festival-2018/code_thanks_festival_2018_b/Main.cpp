#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
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
int X,Y;
int main(){
	cin >> X >> Y;
	if((X+Y)%4!=0){
		cout << "No" << endl;
		return 0;
	}
	int k = (X+Y)/4;
	int b = X-k;
	if(b%2!=0){
		cout << "No" << endl;
		return 0;
	}
	b /= 2;
	int a = k-b;
	if(a<0||b<0)cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}