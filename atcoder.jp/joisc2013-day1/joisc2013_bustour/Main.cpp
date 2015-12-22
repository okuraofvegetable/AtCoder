#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,H,W,sx,sy,gx,gy;
int ax[1010],ay[1010],bx[1010],by[1010],t[1010];
int c[1010];
vector<P> bus[1010][1010];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
P pos[1010][4010];
int dist[1010][4010];
bool used[1010][1010];
int main(){
	scanf("%d %d %d %d %d %d",&W,&H,&sx,&sy,&gx,&gy);
	scanf("%d",&N);
	priority_queue<T,vector<T>,greater<T> > q;
	for(int i=0;i<1010;i++)for(int j=0;j<4010;j++)dist[i][j]=INF;
	memset(used,false,sizeof(used));
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d %d",&ax[i],&ay[i],&bx[i],&by[i],&t[i]);
		c[i]=(bx[i]-ax[i])*2+(by[i]-ay[i])*2;
		int time = (c[i]-t[i])%c[i];
		int x = ax[i],y = ay[i];
		int dir = 0;
		for(int j=0;j<c[i];j++){
			//printf("%d %d %d\n",x,y,time);
			bus[x][y].pb(P(i,time));
			pos[i][time]=P(x,y);
			if(sx==x&&sy==y){
				dist[i][time]=time;
				q.push(T(time,P(i,time)));
			}
			if(x==bx[i]&&y==ay[i])dir++;
			if(x==bx[i]&&y==by[i])dir++;
			if(x==ax[i]&&y==by[i])dir++;
			x+=dx[dir]; y+=dy[dir];
			time++;
			if(time>=c[i])time-=c[i];
		}
	}
	while(!q.empty()){
		T a = q.top();
		q.pop();
		int v = a.fi,id = a.sec.fi,m = a.sec.sec;
		//printf("%d %d %d\n",v,id,m);
		if(dist[id][m]<v)continue;
		int nm = (m+1)%c[id];
		if(dist[id][nm]>v+1){
			dist[id][nm]=v+1;
			q.push(T(dist[id][nm],P(id,nm)));
		}
		P p = pos[id][m];
		int x = p.fi,y = p.sec;
		if(x==gx&&y==gy){
			printf("%d\n",v);
			return 0;
		}
		if(used[x][y])continue;
		for(int i=0;i<bus[x][y].size();i++){
			P info = bus[x][y][i];
			int nid = info.fi;
			int nt = info.sec;
			if(nid == id)continue;
			int ride;
			if(v<nt)ride=nt;
			else ride=((v-nt)/c[nid]+1)*c[nid]+nt;
			nt = (nt+1)%c[nid];
			if(dist[nid][nt]>ride+1){
				dist[nid][nt]=ride+1;
				q.push(T(dist[nid][nt],P(nid,nt)));
			}
		}
		used[x][y]=true;
	} 
	return 0;
}