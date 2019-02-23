#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
int h[105];
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> h[i];
	int ans = 0;
	for(int i=1;i<=100;i++){
		int f = 0;
		for(int j=0;j<N;j++){
			if(h[j]>=i&&f==0){
				ans++;
				f=1;
			}
			if(h[j]<i&&f==1)f=0;
		}
	}
	cout << ans << endl;
	return 0;
}