#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int W,H,N;
int f[3010][3010];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,-1,1,0,-1,1};
priority_queue<T,vector<T>,greater<T> > q;
int main(){
	scanf("%d %d %d",&W,&H,&N);
	for(int i=0;i<N;i++){
		int x,y,h;
		scanf("%d %d %d",&x,&y,&h);
		if(f[x][y]>-h){
			f[x][y]=-h;
			q.push(T(-h,P(x,y)));
		}
	}
	while(!q.empty()){
		T a = q.top();
		q.pop();
		int x=a.sec.fi,y=a.sec.sec,d=a.fi;
		if(f[x][y]<d)continue;
		for(int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<0||nx>=W||ny<0||ny>=H)continue;
			if(f[nx][ny]>d+1){
				f[nx][ny]=d+1;
				q.push(T(d+1,P(nx,ny)));
			}
		}
	}
	ll ans = 0ll;
	for(int i=0;i<W;i++){
		for(int j=0;j<H;j++){
			//printf("%d ",-f[i][j]);
			ans -= (ll)f[i][j];
		}
		//printf("\n");
	}
	printf("%lld\n",ans);
	return 0;
}