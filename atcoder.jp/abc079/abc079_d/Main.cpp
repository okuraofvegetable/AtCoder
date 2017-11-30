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
#define LLINF 4000000000000000000LL
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
int d[10][10];
int H,W;
int main(){
	cin >> H >> W;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin >> d[i][j];
		}
	}
	for(int k=0;k<10;k++){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				chmin(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int a;
			cin >> a;
			if(a==-1)continue;
			ans += d[a][1];
		}
	}
	cout << ans << endl;
	return 0;
}