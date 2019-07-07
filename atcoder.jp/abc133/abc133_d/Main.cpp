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
int N;
ll f(vector<ll> vec){
	int sum = 0;
	int M = vec.size();
	for(int i=1;i<M-1;i++){
		if(i&1)sum += vec[i];
		else sum -= vec[i];
	}
	return vec[0]+vec[M-1]-sum;
}
ll ans[100100];
int main(){
	cin >> N;
	vector<ll> v(N);
	for(int i=0;i<N;i++){
		cin >> v[i];
	}
	ans[0]=f(v);
	for(int i=1;i<N;i++){
		ans[i] = (v[i-1]-ans[i-1]/2)*2;
	}
	for(int i=0;i+1<N;i++){
		cout << ans[i] << ' ';
	}
	cout << ans[N-1] << endl;
	return 0;
}