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
int N;
ll E,T;
ll x[100100];
ll dp[100100];
priority_queue<ll,vector<ll>,greater<ll> > q;
int main(){
	cin >> N >> E >> T;
	for(int i=0;i<N;i++){
		cin >> x[i];
	}
	for(int i=0;i<=N;i++){
		dp[i] = LLINF;
	}
	dp[0] = 0ll;
	dp[1] = T;
	int p = -2ll;
	for(int i=0;i<N;i++){
		while(p+1<i&&2*(x[i]-x[p+2])>T){
			p++;
			q.push(dp[p+1]-2*x[p+1]);
		}
		if(!q.empty())chmin(dp[i+1],2*x[i]+q.top());
		if(p<i-1)chmin(dp[i+1],dp[p+2]+T);
		// cout << i << ' ' << p << ' ' << dp[i] << endl;

	}
	cout << E+dp[N] << endl;
	return 0;
}
