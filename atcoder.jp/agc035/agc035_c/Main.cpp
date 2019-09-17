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
int main(){
	cin >> N;
	if(__builtin_popcount(N)==1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << 1 << ' ' << 2 << endl;
	cout << 2 << ' ' << 3+N << endl;
	cout << 3+N << ' ' << 1+N << endl;
	cout << 1+N << ' ' << 2+N << endl;
	cout << 2+N << ' ' << 3 << endl;
	for(int i=4;i<N;i+=2){
		cout << i+N << ' ' << i+1 << endl;
		cout << i+N << ' ' << 1+N << endl;
		cout << 1+N << ' ' << i+1+N << endl;
		cout << i+1+N << ' ' << i << endl;
	}
	if(N%2==1)return 0;
	int K = N&(-N);
	K++;
	int J = N^K;
	K--;
	cout << N << ' ' << J+N << endl;
	cout << N+N << ' ' << K+N << endl;
	return 0;
}
