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
int H,W;
string f[2010];
int u[2010][2010];
int d[2010][2010];
int l[2010][2010];
int r[2010][2010];
int calc(int x,int y){
	return l[x][y]+r[x][y]+u[x][y]+d[x][y]+1;
}
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> f[i];
	for(int i=0;i<W;i++){
		if(f[0][i]=='#')u[0][i]=-1;
		else u[0][i]=0;
	}
	for(int i=1;i<H;i++){
		for(int j=0;j<W;j++){
			if(f[i][j]=='#')u[i][j]=-1;
			else u[i][j] = u[i-1][j]+1; 
		}
	}
	for(int i=0;i<W;i++){
		if(f[H-1][i]=='#')d[0][i]=-1;
		else d[0][i]=0;
	}
	for(int i=H-2;i>=0;i--){
		for(int j=0;j<W;j++){
			if(f[i][j]=='#')d[i][j]=-1;
			else d[i][j] = d[i+1][j]+1; 
		}
	}
	for(int i=0;i<H;i++){
		if(f[i][0]=='#')l[i][0]=-1;
		else l[i][0]=0;
	}
	for(int i=0;i<H;i++){
		for(int j=1;j<W;j++){
			if(f[i][j]=='#')l[i][j]=-1;
			else l[i][j]=l[i][j-1]+1;
		}
	}
	for(int i=0;i<H;i++){
		if(f[i][W-1]=='#')r[i][W-1]=-1;
		else r[i][W-1]=0;
	}
	for(int i=0;i<H;i++){
		for(int j=W-2;j>=0;j--){
			if(f[i][j]=='#')r[i][j]=-1;
			else r[i][j]=r[i][j+1]+1;
		}
	}

	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(f[i][j]=='#')continue;
			ans = max(ans,calc(i,j));
		}
	}
	cout << ans << endl;
	return 0;
}