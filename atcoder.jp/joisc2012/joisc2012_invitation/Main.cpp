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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct group{
	int ld,rd,lc,rc;
	ll cost;
	group(){}
	group(int ld,int rd,int lc,int rc,ll cost):ld(ld),rd(rd),lc(lc),rc(rc),cost(cost){}
	bool operator < (const group& a) const{
		return cost > a.cost;
	}
};
struct UnionFind{
	int par[500100],rank[500100];
	void init(){
		for(int i=0;i<500100;i++){
			par[i]=i;
			rank[i]=i;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void unite(int a,int b){
		//printf("unite %d %d\n",a,b);
		a = find(a);
		b = find(b);
		if(a==b)return;
		if(rank[a]<rank[b])par[a]=b;
		else{
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}	
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
}uf;
vector<group> gs;
vector<int> dog,cat;
set<int> sd,sc;
ll ans = 0ll;
int cnt = 0;
int A,B,C,N,M;
int p[100100],q[100100],r[100100],s[100100];
ll t[100100];
bool used[200100],usec[200100];
int main(){
	scanf("%d %d %d",&A,&B,&C);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d %lld",&p[i],&q[i],&r[i],&s[i],&t[i]);
		dog.pb(p[i]);dog.pb(q[i]+1);
		cat.pb(r[i]);cat.pb(s[i]+1);
	}
	sort(all(dog));
	sort(all(cat));
	dog.erase(unique(all(dog)),dog.end());
	cat.erase(unique(all(cat)),cat.end());
	for(int i=0;i<N;i++){
		p[i] = lower_bound(all(dog),p[i])-dog.begin();
		q[i] = lower_bound(all(dog),q[i]+1)-dog.begin();
		r[i] = lower_bound(all(cat),r[i])-cat.begin();
		s[i] = lower_bound(all(cat),s[i]+1)-cat.begin();
		gs.pb(group(p[i],q[i],r[i],s[i],t[i]));
		//printf("%d %d %d %d %lld\n",p[i],q[i],r[i],s[i],t[i]);
	}
	for(int i=0;i<sz(dog)-1;i++){
		//printf("insert dog %d\n",i);
		sd.insert(i);
	}
	for(int i=0;i<sz(cat)-1;i++){
		//printf("insert cat %d\n",i);
		sc.insert(i);
	}
	sort(all(gs));
	M = N*2+5;
	//printf("M %d\n",M);
	uf.init();
	for(int i=0;i<N;i++){
		group g = gs[i];
		//printf("%d %d %d %d %lld\n",g.ld,g.rd,g.lc,g.rc,g.cost);
		set<int>::iterator it;
		int curd = *(--sd.upper_bound(g.ld));
		if(!used[curd]){
			cnt += (dog[curd+1]-dog[curd]-1);
			ans += g.cost*(dog[curd+1]-dog[curd]-1);
			used[curd]=true;
		}
		while(1){
			it = sd.upper_bound(curd);
			if(it==sd.end())break;
			int next = *it;
			if(next<g.rd){
				if(!used[next]){
					cnt += (dog[next+1]-dog[next]-1);
					ans += g.cost*(dog[next+1]-dog[next]-1);
					used[next]=true;
				}
				if(!uf.same(curd,next)){
					ans += g.cost;
					cnt++;
					uf.unite(curd,next);
				}
				sd.erase(next);
				//printf("erase dog %d\n",next);
			}
			else break;
		}
		int curc = *(--sc.upper_bound(g.lc));
		if(!usec[curc]){
			cnt += (cat[curc+1]-cat[curc]-1);
			ans += g.cost*(cat[curc+1]-cat[curc]-1);
			usec[curc]=true;
		}
		while(1){
			it = sc.upper_bound(curc);
			if(it==sc.end())break;
			int next = *it;
			if(next<g.rc){
				if(!usec[next]){
					cnt += (cat[next+1]-cat[next]-1);
					ans += g.cost*(cat[next+1]-cat[next]-1);
					usec[next]=true;
				}
				if(!uf.same(curc+M,next+M)){
					ans += g.cost;
					cnt++;
					uf.unite(curc+M,next+M);
				}
				sc.erase(next);
				//printf("erase cat %d\n",next);
			}
			else break;
		}
		if(!uf.same(curd,curc+M)){
			ans += g.cost;
			cnt++;
			uf.unite(curd,curc+M);
		}
		//printf("cnt %d ans %lld\n",cnt,ans);
	}
	if(cnt+1==A+B)printf("%lld\n",ans);
	else printf("-1\n");
	return 0;
}