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
int N;
int A[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> A[i];
	sort(A,A+N);
	int k = lower_bound(A,A+N,0)-A;
	int res;
	if(k==N){
		res = A[N-1];
		for(int i=0;i<N-1;i++){
			res = res - A[i];
		}
		cout << res << endl;
		res = A[N-1];
		for(int i=0;i<N-1;i++){
			cout << res << ' ' << A[i]<< endl;
			res = res - A[i];
		}
	}else if(k==0){
		res = A[0];
		for(int i=1;i<N-1;i++){
			res -= A[i];
		}
		cout << A[N-1]-res << endl;
		res = A[0];
		for(int i=1;i<N-1;i++){
			cout << res << ' ' << A[i] << endl;
			res -= A[i];
		}
		cout << A[N-1] << ' ' << res << endl;
	}else{
		int p = A[k]; //plus
		int q = A[k-1]; //minus
		for(int i=k+1;i<N;i++){
			q -= A[i];
		}
		for(int i=0;i<k-1;i++){
			p -= A[i];
		}
		cout << p - q << endl;
		p = A[k]; //plus
		q = A[k-1]; //minus
		for(int i=k+1;i<N;i++){
			cout << q << ' ' << A[i] << endl;
			q -= A[i];
		}
		for(int i=0;i<k-1;i++){
			cout << p << ' ' << A[i] << endl;
			p -= A[i];
		}
		cout << p << ' ' << q << endl;
	}
	return 0;
}