#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
map<int,int> m;
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		m[k]++;
	}
	map<int,int>::iterator it;
	int ans = 0;
	for(it=m.begin();it!=m.end();it++){
		if((it->sec)%2==1)ans++;
	}	
	cout << ans << endl;
	return 0;
}