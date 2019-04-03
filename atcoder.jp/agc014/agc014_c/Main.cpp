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
int H,W,K;
string A[805];
int f[805][805];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	cin >> H >> W >> K;
	P st;
	for(int i=0;i<H;i++){
		cin >> A[i];
		for(int j=0;j<W;j++){
			f[i][j]=INF;
			if(A[i][j]=='S'){
				st = P(i,j);
			}
		}
	}
	f[st.fi][st.sec]=0;
	queue<T> q;
	q.push(T(st,0));
	while(!q.empty()){
		T a = q.front();
		q.pop();
		int x = a.fi.fi, y = a.fi.sec;
		int v = a.sec;
		if(f[x][y]<v)continue;
		for(int d=0;d<4;d++){
			int nx = x+dx[d];
			int ny = y+dy[d];
			if(nx<0||nx>=H||ny<0||ny>=W)continue;
			if(A[nx][ny]=='#')continue;
			if(f[nx][ny]<=v+1)continue;
			//cout << nx << ' ' << ny  << ' ' << v+1 << endl;
			f[nx][ny]=v+1;
			q.push(T(P(nx,ny),v+1));
		}
	}
	/*for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(f[i][j]!=INF)cout << f[i][j];
			else cout << '*';
		}
		cout << endl;
	}*/
	int ans = INF;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(f[i][j]>K)continue;
			int d = INF;
			d = min(i,H-1-i);
			d = min(d,j);
			d = min(d,W-1-j);
			if(d==0)ans = 1;
			else{
				ans = min(ans,(d-1)/K+2);
			}
		}		
	}
	cout << ans << endl;
	return 0;
}