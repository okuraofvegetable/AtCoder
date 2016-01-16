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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int n,m;
int X[105],Y[105];
vector<P> g[105];
int dist[105][105];
bool can(int pre,int cur,int next){
	if(pre==-1)return true;
	int dot = (X[pre]-X[cur])*(X[next]-X[cur])+(Y[pre]-Y[cur])*(Y[next]-Y[cur]);
	if(dot>0)return false;
	else return true;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d %d",&X[i],&Y[i]);
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		g[a].pb(P(b,c));
		g[b].pb(P(a,c));
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)dist[i][j]=INF;
	priority_queue<T,vector<T>,greater<T> > q;
	q.push(T(0,P(-1,0)));
	while(!q.empty()){
		T a = q.top();
		q.pop();
		int d = a.fi,pre = a.sec.fi,cur = a.sec.sec;
		if(pre!=-1&&dist[cur][pre]<d)continue;
		for(int i=0;i<g[cur].size();i++){
			int to = g[cur][i].fi,cost = g[cur][i].sec;
			if(can(pre,cur,to)){
				if(dist[to][cur]>d+cost){
					dist[to][cur]=d+cost;
					q.push(T(dist[to][cur],P(cur,to)));
				}
			}
		}
	}
	int ans = INF;
	for(int i=0;i<n;i++)ans = min(ans,dist[1][i]);
	if(ans==INF)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}