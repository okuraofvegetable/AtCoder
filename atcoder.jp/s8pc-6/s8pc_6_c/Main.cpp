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
int H,W;
string c[105];
int f[105][105];
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++){
		cin >> c[i];
	}
	for(int l=0;l<H;l++){
		int cnt = 0;
		for(int j=0;j<W;j++){
			if(c[l][j]=='#')cnt++;
		}
		if(cnt>0)continue;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(f[i][j]==0)continue;
				if(i+1<H&&c[i+1][j]=='.')f[i+1][j]=1;
				if(j+1<W&&c[i][j+1]=='.')f[i][j+1]=1;
			}
		}
		cnt=0;
		for(int j=0;j<W;j++)cnt+=f[l][j];
		if(cnt==0)continue;
		memset(f,0,sizeof(f));
		for(int j=0;j<W;j++)f[l][j]=1;
		for(int i=l;i<H;i++){
			for(int j=0;j<W;j++){
				if(f[i][j]==0)continue;
				if(i+1<H&&c[i+1][j]=='.')f[i+1][j]=1;
				if(j+1<W&&c[i][j+1]=='.')f[i][j+1]=1;
			}
		}
		if(f[H-1][W-1]==1){
			cout << "Yay!" << endl;
			return 0;
		}
	}
	cout << ":(" << endl;
	return 0;
}