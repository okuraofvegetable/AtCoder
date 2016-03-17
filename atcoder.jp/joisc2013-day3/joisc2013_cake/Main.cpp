#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T &a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T &a,const T& b){if(a<b)a=b;}
const int SIZE = 1<<19;
struct segtree{
	P seg[SIZE*2];
	void update(int k,int x){
		k += SIZE-1;
		seg[k]=P(x,k-(SIZE-1));
		while(k){
			k = (k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	P query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return P(INF,INF);
		else if(a<=l&&r<=b)return seg[k];
		else{
			P lch = query(a,b,k*2+1,l,(l+r)/2);
			P rch = query(a,b,k*2+2,(l+r)/2,r);
			return min(lch,rch);
		}
	}
	int query(int a,int b){
		P ret = query(a,b,0,0,SIZE);
		return ret.sec;
	}
}seg;
int N;
int id[300100];
ll A[300100];
ll B[300100];
ll ans[300100];
ll imos[300100];
ll rui[300100][2];
ll sum(int l,int r,int rem,int dir){//[l,r]
	int k;
	if(dir==0){
		if(rem==0)k=r%2;
		else k=(r+1)%2;
	}else{
		if(rem==0)k=l%2;
		else k=(l+1)%2;
	}
	ll ret = rui[r][k];
	if(l>0)ret-=rui[l-1][k];
	return ret;
}
void solve(int l,int r){//[l,r)
	int center = seg.query(l,r);
	//printf("%d %d %d\n",l,r,center);
	ll L=0ll,R=0ll;
	int f = (center-l)%2;
	R = sum(center,r-1,f,1);
	f = (r-center-1)%2;
	L = sum(l,center,f,0);
	imos[l]+=R;imos[center]-=R;
	//printf("add [%d,%d) %lld\n",l,center,R);
	imos[center+1]+=L;imos[r]-=L;
	//printf("add [%d,%d) %lld\n",center+1,r,L);
	int lb = l,rb=r,rem = r-l;
	ans[center]+=B[center];
	while(!(lb==center&&rb==center+1)){
		int nc;
		if(lb==center)nc = seg.query(center+1,rb);
		else if(rb==center+1)nc = seg.query(lb,center);
		else{
			int lm = seg.query(lb,center);
			int rm = seg.query(center+1,rb);
			if(B[lm]<B[rm])nc = lm;
			else nc = rm;
		}
		if(nc<center){
			int num = nc-lb+1;
			rem -= num;
			ans[center]+=sum(lb,nc,rem%2,0);
			//printf("add %d %lld\n",center,sum(lb,nc,rem%2,0));
			lb = nc+1;
		}else{
			int num = rb-nc;
			rem -= num;
			ans[center]+=sum(nc,rb-1,rem%2,1);
			//printf("add %d %lld\n",center,sum(nc,rb-1,rem%2,1));
			rb = nc;
		}
	}
	if(l<center)solve(l,center);
	if(center+1<r)solve(center+1,r);
}
ll special(int c){
	ll ret = A[c];
	int l = (c-1+N)%N,r = (c+1)%N,cnt=0;
	while(1){
		cnt++;
		if(A[l]>A[r]){
			if(cnt%2==0)ret+=A[l];
			l=(l-1+N)%N;
		}else{
			if(cnt%2==0)ret+=A[r];
			if(l==r)break;
			r=(r+1)%N;
		}
	}
	return ret;
}
ll Ans[300100];
int main(){
	scanf("%d",&N);
	P mi = P(INF,INF);
	for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
		mi = min(mi,P(A[i],i));
	}
	int idx = 0;
	for(int i=mi.sec+1;i<N;i++){
		B[idx]=A[i];
		id[idx]=i;
		idx++;
	}
	for(int i=0;i<mi.sec;i++){
		B[idx]=A[i];
		id[idx]=i;
		idx++;
	}
	for(int i=0;i<N-1;i++)seg.update(i,B[i]);
	for(int i=0;i<N-1;i+=2)rui[i][0]=B[i];
	for(int i=1;i<N-1;i+=2)rui[i][1]=B[i];
	for(int i=0;i<N-1;i++){
		rui[i+1][0]+=rui[i][0];
		rui[i+1][1]+=rui[i][1];
	}
	solve(0,N-1);
	for(int i=0;i<N-1;i++)imos[i+1]+=imos[i];
	for(int i=0;i<N-1;i++)ans[i]+=imos[i];
	for(int i=0;i<N-1;i++)Ans[id[i]]=ans[i]+(N%2==1?mi.fi:0);
	Ans[mi.sec]=special(mi.sec);
	for(int i=0;i<N;i++)printf("%lld\n",Ans[i]);
	return 0;
}