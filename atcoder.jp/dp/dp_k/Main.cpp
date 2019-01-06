#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
int N,K;
int a[105];
bool dp[100100];
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	sort(a,a+N);
	for(int i=0;i<a[0];i++)dp[i]=false;
	for(int i=a[0];i<=K;i++){
		bool flag = false;
		for(int j=0;j<N;j++){
			if(i>=a[j]&&!dp[i-a[j]]){
				flag = true;
				break;
			}
		}
		dp[i]=flag;
	}
	if(dp[K])cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}