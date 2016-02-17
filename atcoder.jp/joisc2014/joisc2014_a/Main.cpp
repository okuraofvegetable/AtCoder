#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> F;
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
struct event{
	int time,pos,id,type; // 0:from 1:to 
	event(){}
	event(int time,int pos,int id,int type):time(time),pos(pos),id(id),type(type){}
	bool operator < (const event& a) const{
		if(time!=a.time)return time > a.time;
		return type < a.type;
	}
};
int N,M;
vector<P> g;
int a[300100],b[300100],ta[300100],tb[300100];
int bus[300100];
int d[100100],d2[300100];
vector<event> es;
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d %d %d",&a[i],&b[i],&ta[i],&tb[i]);
		a[i]--;b[i]--;
		es.pb(event(ta[i],a[i],i,0));
		es.pb(event(tb[i],b[i],i,1));
	}
	sort(all(es));
	for(int i=0;i<N;i++)d[i]=INF;
	for(int i=0;i<M;i++)bus[i]=INF;
	for(int i=0;i<es.size();i++){
		event e = es[i];
		if(e.type==1){
			if(e.pos==N-1){
				d[e.pos]=e.time;
				bus[e.id]=d[e.pos];
			}else{
				bus[e.id]=d[e.pos];
			}
		}else{
			d[e.pos] = min(d[e.pos],bus[e.id]);
			d2[e.id]=d[e.pos];
		}
	}
	for(int i=0;i<M;i++){
		if(a[i]==0){
			g.pb(P(d2[i],ta[i]));
		}
	}
	sort(all(g));
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int t;
		scanf("%d",&t);
		int k = upper_bound(all(g),P(t,INF))-g.begin();
		if(k==0)printf("-1\n");
		else printf("%d\n",g[k-1].sec);
	}
	return 0;
}