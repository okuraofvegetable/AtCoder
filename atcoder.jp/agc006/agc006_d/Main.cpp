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
bool check(int k){
	// cout << k << endl;
	for(int i=0;i<2*N-1;i++){
		if(a[i]>=k)b[i] = 1;
		else b[i] = 0;
		// cout << b[i] << ' ';
	}
	// cout << endl;
	if(b[N-1]==b[N-2]||b[N-1]==b[N]){
		if(b[N-1])return true;
		else return false;
	}
	int c = 1;
	while(c<N&&b[N-1-c]==b[N-1+c]&&b[N-c]!=b[N-1-c]){
		c++;
	}		
	int bit = (c+1)%2;
	int top = b[N-1]^bit;
	if(c==N){
		if(top==1)return true;
		else return false;
	}
	vi tmp;
	tmp.pb(top);
	tmp.pb(b[N-1-c]);
	tmp.pb(b[N-1+c]);
	sort(all(tmp));
	if(tmp[1])return true;
	else return false;
}
int main(){
	cin >> N;
	for(int i=0;i<2*N-1;i++){
		cin >> a[i];
	}
	int l = 1,r = 2*N-1;
	while(r-l>1){
		int mid = (l+r)/2;
		// cout << l << ' ' << r << endl;
		if(check(mid))l = mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}
