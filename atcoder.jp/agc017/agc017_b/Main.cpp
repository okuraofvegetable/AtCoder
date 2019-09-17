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
ll A,B,C,D;
int main(){
	cin >> N >> A >> B >> C >> D;
	N--;
	if(A>B)swap(A,B);
	ll diff = B-A;
	if(C==0){
		if(D*N>=diff){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		return 0;
	}
	if(C==D){
		if(diff%C==0ll&&diff/C<=N){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
		return 0;
	}
	for(ll i=0;i<=N;i++){
		ll low = diff-(D-C)*i;
		ll high = diff+(D-C)*(N-i);
		if(low<=C*(2ll*i-N)&&C*(2ll*i-N)<=high){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
