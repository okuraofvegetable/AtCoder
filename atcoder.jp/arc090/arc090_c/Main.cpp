#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M;
int S,T;
int U[200100],V[200100],D[200100];
ll d[100100];
ll fS[100100],fT[100100];
vector<P> g[100100];
priority_queue<P,vector<P>,greater<P> > q;
bool used[100100];
int main(){
	scanf("%d %d",&N,&M);
	scanf("%d %d",&S,&T);
	S--;T--;
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&U[i],&V[i],&D[i]);
		U[i]--;V[i]--;
		g[U[i]].pb(P(V[i],D[i]));
		g[V[i]].pb(P(U[i],D[i]));
	}
	for(int i=0;i<N;i++){
		d[i]=LLINF;
	}
	d[S]=0ll;
	q.push(P(0ll,S));
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec;
		if(d[v]<a.fi)continue;
		for(int i=0;i<g[v].size();i++){
			int to = g[v][i].fi;
			ll cost = g[v][i].sec;
			if(d[to]>d[v]+cost){
				d[to]=d[v]+cost;
				q.push(P(d[to],to));
			}
		}
	}
	/*for(int i=0;i<N;i++){
		cout << d[i] << ' ';
	}
	cout << endl;*/
	fS[S]=1ll;
	for(int i=0;i<N;i++)q.push(P(d[i],i));
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec;
		for(int i=0;i<g[v].size();i++){
			int to = g[v][i].fi;
			ll cost = g[v][i].sec;
			if(d[to]==d[v]+cost){
				fS[to]=(fS[to]+fS[v])%MOD;
			}
		}
	}
	fT[T]=1ll;
	for(int i=0;i<N;i++)q.push(P(-d[i],i));
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec;
		for(int i=0;i<g[v].size();i++){
			int to = g[v][i].fi;
			ll cost = g[v][i].sec;
			if(d[to]==d[v]-cost){
				fT[to]=(fT[to]+fT[v])%MOD;
			}
		}
	}
	/*for(int i=0;i<N;i++){
		cout << fS[i] << ' ';
	}
	cout << endl;
	for(int i=0;i<N;i++){
		cout << fT[i] << ' ';
	}
	cout << endl;*/
	ll ans = (fS[T]*fS[T])%MOD;
	for(int i=0;i<N;i++){
		if(d[i]*2ll!=d[T])continue;
		ll t1 = (fS[i]*fS[i])%MOD;
		ll t2 = (fT[i]*fT[i])%MOD;
		ans = (ans+MOD-(t1*t2)%MOD)%MOD;
	}
	for(int i=0;i<M;i++){
		int u = U[i],v = V[i],c = D[i];
		if(d[u]>d[v])swap(u,v);
		if(d[u]+c!=d[v])continue;
		if(2ll*d[u]<d[T]&&2ll*d[v]>d[T]){
			ll t1 = (fS[u]*fS[u])%MOD;
			ll t2 = (fT[v]*fT[v])%MOD;
			ans = (ans+MOD-(t1*t2)%MOD)%MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}