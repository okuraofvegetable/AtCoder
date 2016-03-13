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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
const int SIZE = 1<<17;
struct RMQ{
	int seg[SIZE*2];
	void update(int k,int x){
		k += SIZE-1;
		seg[k]=x;
		while(k){
			k = (k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return -INF;
		else if(a<=l&&r<=b)return seg[k];
		else return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
	int query(int a,int b){
		if(a>=b)return -INF;
		return query(a,b,0,0,SIZE);	
	}
}seg;
struct event{
	int x,y,val;
	event(){}
	event(int x,int y,int val):x(x),y(y),val(val){}
	bool operator < (const event& a) const{
		return x < a.x;
	}
};
int H,W,N;
P pos[100100];
vector<int> zx,zy;
vector<int> px[100100],py[100100];
int Leftcnt(int y){  //[0,y)
	return lower_bound(all(zy),y)-zy.begin();
}
int Rightcnt(int y){ //[y,sz(zy))
	return sz(zy)-Leftcnt(y);
}
int Uppercnt(int x){ //[0,x)
	return lower_bound(all(zx),x)-zx.begin();
}
int Lowercnt(int x){ //[x,sz(zx))
	return sz(zx)-Uppercnt(x);
}
int ans = 0;
int main(){
	scanf("%d %d %d",&H,&W,&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&pos[i].fi,&pos[i].sec);
		pos[i].fi--;pos[i].sec--;
		zx.pb(pos[i].fi);zy.pb(pos[i].sec);
	}
	sort(all(zx));
	sort(all(zy));
	zx.erase(unique(all(zx)),zx.end());
	zy.erase(unique(all(zy)),zy.end());
	ll base = (ll)(H-sz(zx))*(ll)(W-sz(zy));
	//cout << base << endl;
	for(int i=0;i<N;i++){
		pos[i].fi = lower_bound(all(zx),pos[i].fi)-zx.begin();
		pos[i].sec = lower_bound(all(zy),pos[i].sec)-zy.begin();
		py[pos[i].sec].pb(pos[i].fi);
		px[pos[i].fi].pb(pos[i].sec);
	}
	for(int i=0;i<zx.size();i++)sort(all(px[i]));
	for(int i=0;i<zy.size();i++)sort(all(py[i]));
	// -------- left and upper
	vector<event> ev;
	int idx = 0;
	for(int i=0;i<zy.size();i++){
		seg.update(i,-INF);
		int x = py[i][sz(py[i])-1];
		event e = event(x,i,W-zy[i]-sz(zy)+i);
		ev.pb(e);
	}
	sort(all(ev));
	for(int i=0;i<zx.size();i++){
		int rb = px[i][sz(px[i])-1];
		int add = H-zx[i]+i-sz(zx);
		//printf("add %d,rb %d\n",add,rb);
		int hori = seg.query(rb+1,sz(zy));
		//printf("%d\n",hori+add);
		if(hori>=0)ans = max(ans,hori+add);
		while(idx<ev.size()&&ev[idx].x==i){
			seg.update(ev[idx].y,ev[idx].val);
			//printf("update %d %d\n",ev[idx].y,ev[idx].val);
			idx++;
		}
	}
	//-------- right and upper
	ev.clear();
	for(int i=0;i<zy.size();i++){
		seg.update(i,-INF);
		int x = py[i][sz(py[i])-1];
		event e = event(x,i,zy[i]-i);
		ev.pb(e);
	}
	sort(all(ev));
	idx = 0;
	for(int i=0;i<zx.size();i++){
		int rb = px[i][0];
		int add = H-zx[i]+i-sz(zx);
		//printf("add %d\n",add);
		int hori = seg.query(0,rb);
		//printf("%d\n",hori+add);
		if(hori>=0)ans = max(ans,hori+add);
		while(idx<ev.size()&&ev[idx].x==i){
			seg.update(ev[idx].y,ev[idx].val);
			//printf("update %d %d\n",ev[idx].y,ev[idx].val);
			idx++;
		}
	}
	//-------- left and lower
	ev.clear();
	for(int i=0;i<zy.size();i++){
		seg.update(i,-INF);
		int x = py[i][0];
		event e = event(x,i,W-zy[i]-sz(zy)+i);
		ev.pb(e);
	}
	sort(all(ev));
	reverse(all(ev));
	idx = 0;
	for(int i=sz(zx)-1;i>=0;i--){
		int rb = px[i][sz(px[i])-1];
		int add = zx[i]-i;
		//printf("add %d\n",add);
		int hori = seg.query(rb+1,sz(zy));
		//printf("%d\n",hori+add);
		if(hori>=0)ans = max(ans,hori+add);
		while(idx<ev.size()&&ev[idx].x==i){
			seg.update(ev[idx].y,ev[idx].val);
			//printf("update %d %d\n",ev[idx].y,ev[idx].val);
			idx++;
		}
	}
	//-------- right and lower
	ev.clear();
	for(int i=0;i<zy.size();i++){
		seg.update(i,-INF);
		int x = py[i][0];
		event e = event(x,i,zy[i]-i);
		ev.pb(e);
	}
	sort(all(ev));
	reverse(all(ev));
	idx = 0;
	for(int i=sz(zx)-1;i>=0;i--){
		int rb = px[i][0];
		int add = zx[i]-i;
		//printf("add %d\n",add);
		int hori = seg.query(0,rb);
		//printf("%d\n",hori+add);
		if(hori>=0)ans = max(ans,hori+add);
		while(idx<ev.size()&&ev[idx].x==i){
			seg.update(ev[idx].y,ev[idx].val);
			//printf("update %d %d\n",ev[idx].y,ev[idx].val);
			idx++;
		}
	}
	for(int i=0;i<zx.size();i++){
		int L = zy[px[i][0]],R = zy[px[i][sz(px[i])-1]];
		//printf("%d %d\n",L-1-Leftcnt(L-1),W-R-2-Rightcnt(R+2));
		ans = max(ans,L-1-Leftcnt(L-1));
		ans = max(ans,W-R-2-Rightcnt(R+2));
	}
	for(int i=0;i<zy.size();i++){
		int U = zx[py[i][0]],D = zx[py[i][sz(py[i])-1]];
		//printf("%d %d\n",U-1-Uppercnt(U-1),H-D-2-Lowercnt(D+2));
		ans = max(ans,U-1-Uppercnt(U-1));
		ans = max(ans,H-D-2-Lowercnt(D+2));
	}
	printf("%lld\n",base+(ll)ans);
	return 0;
}