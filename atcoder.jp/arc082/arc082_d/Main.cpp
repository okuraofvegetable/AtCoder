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
int dir = -1;
int low = 0,high,mid = 0;
int f(int x){
	if(x<=mid)return low;
	else return min(high,low+x-mid);
}
int X,K,Q;
struct query{
	int type; // 0 upd,1 query
	int time,a,id;
	query(int type,int time,int a,int id):type(type),time(time),a(a),id(id){}
};
bool comp(query a,query b){
	return a.time < b.time;
}
vector<query> qs;
int ans[100100];
void update(int T){
	if(dir==-1){
		if(low<T)mid = min(X,mid+T-low);
		low = max(0,low-T);
		high = max(0,high-T);
	}else{
		low = min(X,low+T);
		high = min(X,high+T);
	}
}
int main(){
	scanf("%d",&X);
	high = X;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int r;
		scanf("%d",&r);
		qs.pb(query(0,r,-1,-1));
	}
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int t,a;
		scanf("%d %d",&t,&a);
		qs.pb(query(1,t,a,i));
	}
	sort(all(qs),comp);
	int prev = 0;
	for(int i=0;i<qs.size();i++){
		//printf("%d: %d %d %d %d\n",i,qs[i].type,qs[i].time,qs[i].a,qs[i].id);
		//printf("low %d high %d mid %d\n",low,high,mid);
		if(qs[i].type==0){
			update(qs[i].time-prev);
			dir*=-1;
		}else{
			update(qs[i].time-prev);
			ans[qs[i].id]=f(qs[i].a);
		}
		prev = qs[i].time;
	}
	for(int i=0;i<Q;i++)printf("%d\n",ans[i]);
	return 0;
}