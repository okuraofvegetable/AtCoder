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
const int SIZE = 1<<19;
struct segtree{
	int seg[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k,int l,int r){
		seg[k]+=lazy[k]*(r-l);
		if(k<SIZE-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int k,int l,int r,int x){
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]+=x;
			lazy_evaluate(k,l,r);
			return;	
		}else{
			lazy_evaluate(k,l,r);
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			seg[k]=seg[k*2+1]+seg[k*2+2];
		}
	}
	int query(int a,int b,int k,int l,int r){
		lazy_evaluate(k,l,r);
		if(r<=a||b<=l)return 0;
		else if(a<=l&&r<=b){
			return seg[k];
		}else{
			int lch = query(a,b,k*2+1,l,(l+r)/2);
			int rch = query(a,b,k*2+2,(l+r)/2,r);
			seg[k]=seg[k*2+1]+seg[k*2+2];
			return lch+rch;
		}
	}
}seg;
int n,m,k;
int a[100100],b[100100];
int p[100100],q[100100],r[100100];
vector<int> in[100100],out[100100];
int ans[100100];
vector<int> zip;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		zip.pb(a[i]);zip.pb(b[i]);	
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&p[i],&q[i],&r[i]);
		q[i]--;r[i]--;
		in[q[i]].pb(i);
		out[r[i]].pb(i);
		zip.pb(p[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<n;i++){
		a[i]=lower_bound(all(zip),a[i])-zip.begin();
		b[i]=lower_bound(all(zip),b[i])-zip.begin();
	}
	for(int i=0;i<m;i++){
		p[i]=lower_bound(all(zip),p[i])-zip.begin();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<in[i].size();j++){
			int id = in[i][j];
			ans[id]-=seg.query(p[id],p[id]+1,0,0,SIZE);
		}
		seg.update(a[i],b[i]+1,0,0,SIZE,1);
		for(int j=0;j<out[i].size();j++){
			int id = out[i][j];
			ans[id]+=seg.query(p[id],p[id]+1,0,0,SIZE);
		}
	}
	for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	return 0;
}