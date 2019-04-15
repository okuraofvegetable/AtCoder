#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<pp,int> T;
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
int A[33],B[33];
int P[33],Q[33];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
		P[i]=A[i];
		Q[i]=B[i];
	}
	sort(A,A+N);
	sort(B,B+N);
	int a,b;
	if(N%2==1){
		a=A[N/2];
		b=B[N/2];
	}else{
		a=(A[(N-1)/2]+A[N/2])/2;
		b=(B[(N-1)/2]+B[N/2])/2;
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		ans += abs(a-P[i]);
		ans += abs(P[i]-Q[i]);
		ans += abs(b-Q[i]);
	}
	cout << ans << endl;
	return 0;
}