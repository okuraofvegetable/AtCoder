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
int H[100100];
int a[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> H[i];
	a[0]=1;
	for(int i=1;i<N;i++){
		if(H[i-1]-a[i-1]==H[i]){
			a[i]=0;
		}else if(H[i-1]-a[i-1]>H[i]){
			cout << "No" << endl;
			return 0;
		}else{
			a[i]=1;
		}
	}
	cout << "Yes" << endl;
	return 0;
}