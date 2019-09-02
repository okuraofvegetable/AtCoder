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
int A,B,C;
bool ok(){
	if(A&1)return false;
	if(B&1)return false;
	if(C&1)return false;
	return true;
}
int main(){
	cin >> A >> B >> C;
	if(!ok()){
		cout << 0 << endl;
		return 0;
	}
	if(A==B&&B==C){
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	while(ok()){
		int a = (B+C)/2;
		int b = (A+C)/2;
		int c = (B+A)/2;
		A = a;
		B = b;
		C = c;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
