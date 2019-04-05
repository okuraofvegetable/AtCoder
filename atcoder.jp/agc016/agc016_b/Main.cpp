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
int a[100100];
int mx = -1,mi = INF;
void fail(){
	cout << "No" << endl;
	exit(0);
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<N;i++){
		mx = max(mx,a[i]);
		mi = min(mi,a[i]);
	}
	if(mx-mi>1)fail();
	if(mx>mi){
		int A = 0;
		for(int i=0;i<N;i++){
			if(a[i]==mi)A++;
		}
		int X = mx;
		if(A>=X)fail();
		if(2*X-A>N)fail();
		cout << "Yes" << endl;
	}else{
		if(2*mx>N&&mx+1!=N)fail();
		cout << "Yes" << endl;
	}
	return 0;
}