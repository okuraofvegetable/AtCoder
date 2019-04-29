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
int H,W,h,w;
ll a[505][505];
const ll A = 300000ll;
int main(){
	cin >> H >> W >> h >> w;
	if(H%h==0&&W%w==0){
		cout << "No" << endl;
		return 0;
	}
	memset(a,0,sizeof(a));
	if(h==1){
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(j%w==(w-1))a[i][j]=-(A*(ll)(w-1)+1ll);
				else a[i][j]=A;
			}
		}
	}else if(w==1){
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(i%h==(h-1))a[i][j]=-(A*(ll)(h-1)+1ll);
				else a[i][j]=A;
			}
		}
	}else{
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(i%h==0||j%w==0)a[i][j]=A;
				if(i%h==(h-1)&&j%w==(w-1))a[i][j]=-(A*(ll)(h+w-1)+1ll);
			}
		}
	}
	cout << "Yes" << endl;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			printf("%lld",a[i][j]);
			if(j==W-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}