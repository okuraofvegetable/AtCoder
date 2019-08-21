#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef pair<P,int> T;
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
int X,Y,Z,K;
ll A[1010],B[1010],C[1010];
int main(){
	cin >> X >> Y >> Z >> K;
	for(int i=0;i<X;i++){
		cin >> A[i];
	}
	for(int i=0;i<Y;i++){
		cin >> B[i];
	}
	for(int i=0;i<Z;i++){
		cin >> C[i];
	}	
	sort(A,A+X);
	sort(B,B+Y);
	sort(C,C+Z);
	vector<ll> vec;
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			vec.pb(A[i]+B[j]);
		}
	}
	sort(all(vec),greater<ll>());
	vector<ll> ans;
	for(int i=0;i<min((int)vec.size(),(int)K);i++){
		for(int k=0;k<Z;k++){
			ans.pb(vec[i]+C[k]);
			//cout << vec[i] << ' ' << C[k] << endl;
		}
	}
	sort(all(ans),greater<ll>());
	for(int i=0;i<K;i++){
		cout << ans[i] << endl;
	}
	return 0;
}

