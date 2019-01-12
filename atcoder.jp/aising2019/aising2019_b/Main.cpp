#include<bits/stdc++.h>
using namespace std;
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
int N;
int A,B;
int P[104];
int a[4];
int main(){
	cin >> N;
	cin >> A >> B;
	for(int i=0;i<N;i++){
		cin >> P[i];
		if(P[i]<=A)a[0]++;
		else if(P[i]<=B)a[1]++;
		else a[2]++;
	}
	cout << min(min(a[0],a[1]),a[2]) << endl;
	return 0;
}