#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
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
int main(){
	int N;
	cin >> N;
	int ans = 0;
	if(N%2==0){
		for(int i=1;i<=N/2-1;i++)ans += i;
		ans *= 4;
	}else{
		for(int i=1;i<=(N-1)/2;i++){
			ans += 2*i-1;
		}
		for(int i=1;i<(N-1)/2;i++){
			ans += 2*i-1;
		}
	}
	cout << ans << endl;
	return 0;
}