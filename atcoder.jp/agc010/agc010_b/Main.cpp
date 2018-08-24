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
ll N;
ll A[100100];
ll B[100100];
int main(){
	cin >> N;
	ll sum = 0ll;
	for(int i=0;i<N;i++){
		cin >> A[i];
		sum += A[i];
	}
	if(sum%(N*(N+1ll)/2ll)!=0ll){
		cout << "NO" << endl;
		return 0;
	}
	ll K = sum/(N*(N+1ll)/2ll);
	ll M = -LLINF;
	for(int i=0;i<N-1;i++){
		B[i] = A[i+1]-A[i];
		chmax(M,B[i]);
	}
	/*if(M<0ll){
		cout << "NO" << endl;
		return 0;
	}*/
	for(int i=0;i<N-1;i++){
		if((M-B[i])%N!=0ll){
			cout << "NO" << endl;
			return 0;
		}
	}
	if(M>=0ll){
		if(K-M<0ll || (K-M)%N!=0ll){
			cout << "NO" << endl;
			return 0;
		}
	}/*else{
		if(K-(N-1ll)*M<0ll || (K-(N-1ll)*M)%N!=0ll){
			cout << "NO" << endl;
			return 0;
		}
	}*/
	cout << "YES" << endl;
	return 0;
}