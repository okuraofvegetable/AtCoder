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
int H,W;
string s[500];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int k=0;
int f[405][405];
ll num[200000][2];
void dfs(int x,int y){
	f[x][y]=k;
	if(s[x][y]=='#')num[k][0]++;
	else num[k][1]++;
	for(int d=0;d<4;d++){
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(nx<0||nx>=H||ny<0||ny>=W)continue;
		if(f[nx][ny]!=-1)continue;
		if(s[nx][ny]==s[x][y])continue;
		dfs(nx,ny);
	}
}
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> s[i];
	memset(f,-1,sizeof(f));
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(f[i][j]==-1&&s[i][j]=='#'){
				k++;
				dfs(i,j);
			}
		}
	}
	ll ans = 0ll;
	for(int i=0;i<=H*W;i++){
		ans += num[i][0]*num[i][1];
	}
	cout << ans << endl;
	return 0;
}