#include <bits/stdc++.h>
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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
template<class T>
void input(vector<T>& vec,int n){
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
}
ll dp[55][2];
int N,p;
int A[55];
int main(){
	cin >> N >> p;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	dp[0][0] = 1ll;
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
		 dp[i+1][(j+A[i])%2]+=dp[i][j];
		 dp[i+1][j] += dp[i][j];
		}
	}	
	cout << dp[N][p] << endl;
	return 0;
}
