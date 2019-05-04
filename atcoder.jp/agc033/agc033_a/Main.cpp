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
int H,W;
string s[1010];
int d[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	cin >> H >> W;
	queue<P> q;
	for(int i=0;i<H;i++){
		cin >> s[i];
		for(int j=0;j<W;j++){
			if(s[i][j]=='#'){
				q.push(P(i,j));
				d[i][j]=0;
			}else{
				d[i][j]=INF;
			}
		}
	}
	while(!q.empty()){
		P a = q.front();
		q.pop();
		int x = a.fi,y = a.sec;
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||nx>=H)continue;
			if(ny<0||ny>=W)continue;
			if(d[nx][ny]!=INF)continue;
			d[nx][ny]=d[x][y]+1;
			q.push(P(nx,ny));
		}
	}
	int ans = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			ans = max(ans,d[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}