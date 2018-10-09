#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef pair<ll,P> T;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2100000000
#define LLINF 1000000000000000
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
int N,M,K;
string d;
string s[1010];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
string str = "UDLR";
int dir[4][1000100];
ll dist[1010][1010];
priority_queue<T,vector<T>,greater<T> > q;
int main(){
	scanf("%d %d %d",&N,&M,&K);
	cin >> d;
	for(int i=0;i<N;i++)cin >> s[i];
	memset(dir,-1,sizeof(dir));
	for(int i=0;i<4;i++){
		int f = -1;
		for(int j=0;j<K;j++){
			if(d[j]==str[i]){
				f = j;
				break;
			}
		}
		if(f==-1)continue;
		dir[i][K]=K+f;
		for(int j=K-1;j>=0;j--){
			dir[i][j]=dir[i][j+1];
			if(d[j]==str[i])dir[i][j]=j;
		}
		/*for(int j=0;j<K;j++){
			printf("%d ",dir[i][j]);
		}
		printf("\n");*/
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dist[i][j]=LLINF;
		}
	}
	P S,G;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(s[i][j]=='S')S = P(i,j);
			if(s[i][j]=='G')G = P(i,j);
		}
	}
	q.push(T(0ll,S));
	dist[S.fi][S.sec]=0ll;
	while(!q.empty()){
		T a = q.top();
		q.pop();
		int x = a.sec.fi, y = a.sec.sec;
		ll v = a.fi;
		if(dist[x][y]<v)continue;
		//cout << x << ' ' << y << ' ' << v << endl;
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M)continue;
			if(s[nx][ny]=='#')continue;
			int vk = (int)(v%(ll)K);
			if(dir[i][v%K]==-1)continue;
			ll nv = dist[x][y]+dir[i][vk]-vk+1;
			if(dist[nx][ny]>nv){
				dist[nx][ny]=nv;
				q.push(T(nv,P(nx,ny)));
			}
		}
	}
	if(dist[G.fi][G.sec]==LLINF)printf("-1\n");
	else printf("%lld\n",dist[G.fi][G.sec]);
	return 0;
}