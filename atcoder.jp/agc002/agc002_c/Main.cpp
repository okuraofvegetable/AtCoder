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
int N,L;
int a[100100];
int main(){
	cin >> N >> L;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	int l = 0;
	int id = -1;
	for(int i=1;i<N;i++){
		if(l < a[i]+a[i-1]){
			l = a[i]+a[i-1];
			id = i;
		}
	}
	if(l<L){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for(int i=1;i<id;i++)cout << i << endl;
	for(int i=N-1;i>id;i--)cout << i << endl;
	cout << id << endl;
	return 0;
}