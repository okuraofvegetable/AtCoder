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
struct imos{
	vector<T> vec;
	vector<T> rui;
	imos(){}
	imos(vector<T> v){
		vec = v;
		init();
	}
	void init(){
		rui = vec;
		for(int i=1;i<rui.size();i++){
			rui[i] += rui[i-1];
		}
	}
	T sum(int l,int r){
		if(l==0)return rui[r];
		else return rui[r]-rui[l-1];
	}
};
int N;
vector<ll> A;
int main(){
	cin >> N;	
	A.resize(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	sort(all(A));
	imos<ll> rui(A);
	rui.init();
	int r = -1;
	for(int i=0;i<N-1;i++){
		ll s = rui.sum(0,i);
		if(s*2ll<A[i+1])r=i;
	}
	cout << N-1-r << endl;
	return 0;
}
