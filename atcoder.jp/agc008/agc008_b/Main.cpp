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
int N,K;
ll a[100100];
ll rui[100100];
ll L[100100];
ll R[100100];
ll dp[100100][2];
ll sum(int l,int r){
	if(l==0)return rui[r];
	else return rui[r]-rui[l-1];
}
ll f(int l,int r){
	ll res = 0ll;
	if(l>0)res += L[l-1];
	if(r<N-1)res += R[r+1];
	return res;
}
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	for(int i=0;i<N;i++){
		rui[i] = a[i];
		if(i>0)rui[i] += rui[i-1];
	}
	for(int i=0;i<N;i++){
		if(i>0)L[i] += L[i-1];
		L[i] += max(a[i],0ll);
	}
	for(int i=N-1;i>=0;i--){
		if(i<N-1)R[i] = R[i+1];
		R[i] += max(a[i],0ll);
	}
	ll ans = 0ll;
	for(int i=0;i<N-K+1;i++){
		chmax(ans,sum(i,i+K-1)+f(i,i+K-1));
		chmax(ans,f(i,i+K-1));
	}
	cout << ans << endl;	
	return 0;
}
