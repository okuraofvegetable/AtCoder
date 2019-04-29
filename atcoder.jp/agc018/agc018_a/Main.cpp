#include<bits/stdc++.h>
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
int N,K;
int A[100100];
vector<int> v;
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++)cin >> A[i];
	for(int i=0;i<N;i++){
		if(A[i]==K){
			cout << "POSSIBLE" << endl;
			return 0;
		}
		if(A[i]>K)v.pb(A[i]-K);
	}
	if(v.size()==0){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	int g = A[0];
	for(int i=0;i<N;i++){
		g = __gcd(g,A[i]);
	}
	for(int i=0;i<v.size();i++){
		if(v[i]%g==0){
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}