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
int A[595];
bool check(int t){
	vector<int> vec;
	for(int i=0;i<N;i++){
		if(A[i]%t!=0)vec.pb(A[i]%t);
	}
	sort(all(vec));
	int M = vec.size();
	if(M==0)return true;
	vector<ll> a(M);
	vector<ll> b(M);
	for(int i=0;i<M;i++){
		a[i] = vec[i];
		b[i] = t-vec[i];
	}
	for(int i=1;i<M;i++){
		a[i] += a[i-1];
		b[M-1-i] += b[M-i];
	}
	ll m = min(a[M-1],b[0]); 
	for(int i=0;i<M-1;i++){
		m = min(m,max(a[i],b[i+1]));
	}
	return m<=(ll)K;
}
int main(){
	cin >> N;
	cin >> K;
	int s=0;	
	for(int i=0;i<N;i++){
		cin >> A[i];
		s += A[i];
	}
	vector<int> vec;
	for(int i=1;i*i<=s;i++){
		if(s%i==0){
			vec.pb(i);
			if(i!=s/i)vec.pb(s/i);
		}
	}
	sort(all(vec));
	for(int i=vec.size()-1;i>=0;i--){
		if(check(vec[i])){
			cout << vec[i] << endl;
			return 0;
		}
	}
	return 0;
}
