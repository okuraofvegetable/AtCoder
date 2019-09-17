#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl;
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
template<class t,class u>
ostream& operator << (ostream& os,pair<t,u> p){
	return os << p.fi << ',' << p.sec;
}
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
void fastio(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
}
int N;
string s;
int dp[200100][2];
int main(){
	cin >> N;
	cin >> s;
	for(int i=0;i<=N;i++){
		dp[i][0]=dp[i][1]=INF;
	}
	dp[0][0] = 0;
	for(int i=0;i<N;i++){
		if(s[i]=='.'){
			chmin(dp[i+1][1],dp[i][1]+1);
			chmin(dp[i+1][0],dp[i][0]);
		}else{
			chmin(dp[i+1][1],dp[i][0]);
			chmin(dp[i+1][1],dp[i][1]);
			chmin(dp[i+1][0],dp[i][0]+1);
		}
	}
	cout << min(dp[N][0],dp[N][1]) << endl;
	return 0;
}
