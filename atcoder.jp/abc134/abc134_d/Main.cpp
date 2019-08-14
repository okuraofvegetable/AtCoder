#include <bits/stdc++.h>
using namespace std;
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
int a[200100];
int b[200100];
int main(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> a[i];
	}
	for(int i=N;i>=1;i--){
		int c = a[i];
		for(int j=i;j<=N;j+=i){
			c ^= b[j];
		}
		b[i] = c;
	}
	vector<int> ans;
	for(int i=1;i<=N;i++){
		if(b[i])ans.pb(i);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i];
		if(i+1<ans.size())cout << ' ';
		else cout << endl;
	}
	return 0;
}

