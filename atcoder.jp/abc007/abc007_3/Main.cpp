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
int R,C;
int sy,sx;
int gy,gx;
string c[55];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int d[55][55];
int main(){
	cin >> R >> C;
	cin >> sy >> sx;
	sy--;sx--;
	cin >> gy >> gx;
	gy--;gx--;
	for(int i=0;i<R;i++){
		cin >> c[i];
	}
	queue<P> q;
	q.push(P(sy,sx));
	memset(d,-1,sizeof(d));
	d[sy][sx]=0;
	while(!q.empty()){
		P a = q.front();
		q.pop();
		int f = d[a.fi][a.sec];
		for(int i=0;i<4;i++){
			int ny = a.fi+dy[i];
			int nx = a.sec+dx[i];
			if(ny<0||nx<0||ny>=R||nx>=C)continue;
			if(d[ny][nx]!=-1)continue;
			if(c[ny][nx]=='#')continue;
			d[ny][nx]=f+1;
			q.push(P(ny,nx));
		}
	}
	cout << d[gy][gx] << endl;
	/*for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}*/
	return 0;
}