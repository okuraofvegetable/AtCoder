#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct edge{
	int to;
	ll cost;
	edge(){}
	edge(int to,ll cost):to(to),cost(cost){}
};
int A[5];
int N,M;
int L[100100],R[100100],C[100100];
ll d[200100];
vector<int> zip;
vector<edge> g[200100];
void dijkstra(int s){
	for(int i=0;i<M;i++)d[i]=LLINF;
	priority_queue<P,vector<P>,greater<P> > q;
	d[s]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec;
		if(d[v]<a.fi)continue;
		for(int i=0;i<g[v].size();i++){
			edge e = g[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(P(d[e.to],e.to));
			}
		}
	}
}
ll dist[5][5];
int main(){
	for(int i=0;i<5;i++)scanf("%d",&A[i]);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&L[i],&R[i]);
		C[i]=R[i]-L[i]+1;
		L[i]--;
		zip.pb(L[i]);zip.pb(R[i]);
	}
	for(int i=0;i<4;i++){
		zip.pb(A[i]);
		A[i+1]+=A[i];
	}
	sort(all(zip));
	M = sz(zip);
	for(int i=0;i<5;i++)A[i]=lower_bound(all(zip),A[i])-zip.begin();
	for(int i=0;i<N;i++){
		L[i]=lower_bound(all(zip),L[i])-zip.begin();
		R[i]=lower_bound(all(zip),R[i])-zip.begin();
		g[L[i]].pb(edge(R[i],C[i]));
		g[R[i]].pb(edge(L[i],C[i]));
	}
	for(int i=0;i<4;i++){
		dijkstra(A[i]);
		for(int j=i+1;j<4;j++){
			dist[i][j]=d[A[j]];
		}
	}
	ll ans = LLINF;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			int a = -1,b = -1;
			for(int k=0;k<4;k++){
				if(k!=i&&k!=j){
					if(a==-1)a=k;
					else b = k;
				}
			}
			ans = min(ans,dist[i][j]+dist[a][b]);
		}
	}
	if(ans==LLINF)printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}