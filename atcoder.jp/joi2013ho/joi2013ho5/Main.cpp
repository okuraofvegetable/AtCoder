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
int N;
int A[100100],type[100100];
vector<int> tx,ty,b;
set<int> s;
set<P> sp;
vector<int> v,zip;
int l[100100],r[100100],eq[100100];
const int SIZE = 1<<18;
struct segtree{
	int seg[SIZE*2],lazy[SIZE*2];
	void lazy_evaluate(int k){
		seg[k]+=lazy[k];
		if(k<SIZE-1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int k,int l,int r,int x){
		if(a>=b)return;
		lazy_evaluate(k);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]+=x;
			lazy_evaluate(k);
		}else{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		lazy_evaluate(k);
		if(r<=a||b<=l)return -1;
		else if(a<=l&&r<=b)return seg[k];
		else{
			int lch = query(a,b,k*2+1,l,(l+r)/2);
			int rch = query(a,b,k*2+2,(l+r)/2,r);
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
			return max(lch,rch);
		}
	}
}seg;
struct BIT{
	ll bit[SIZE+10];
	void add(int i,ll x){
		while(i<=SIZE){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
}bit;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		zip.pb(A[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<N;i++)A[i] = lower_bound(all(zip),A[i])-zip.begin()+1;
	for(int i=0;i<N;i++){
		if(s.lower_bound(A[i])==s.end()){
			tx.pb(i);
			ty.pb(A[i]);
			type[i]=1;
		}
		s.insert(A[i]);
	}
	s.clear();
	for(int i=N-1;i>=0;i--){
		if(s.lower_bound(-A[i])==s.end()&&!type[i]){
			b.pb(i);
			type[i]=1;
		}
		s.insert(-A[i]);
	}
	reverse(all(b));
	//for(int i=0;i<tx.size();i++)printf("%d\n",tx[i]);
	//for(int i=0;i<b.size();i++)printf("%d\n",b[i]);
	int idx = 0;
	for(int i=0;i<N;i++){
		if(idx<sz(tx)&&tx[idx]==i){
			v.pb(ty[idx]);
			idx++;
		}
		int k = upper_bound(all(v),A[i])-v.begin();
		eq[i] = lower_bound(all(v),A[i])-v.begin();
		l[i]=k;
		r[i]=idx;//[l,r)
		//printf("%d %d %d\n",eq[i],l[i],r[i]);
	}
	//for(int i=0;i<N;i++)if(!type[i])printf("%d %d\n",l[i],r[i]);
	idx = 0;
	ll ret = 0;
	for(int i=0;i<N;i++){
		if(idx<sz(b)&&b[idx]==i){
			vector<int> tmp;
			while(!sp.empty()&&sp.begin()->fi<=A[b[idx]]){
				int v = sp.begin()->sec;
				sp.erase(sp.begin());
				//printf("delete %d\n",v);
				if(A[v]==A[b[idx]]){
					seg.update(eq[v],r[v],0,0,SIZE,-1);
					tmp.pb(v);
				}else{
					seg.update(eq[v],l[v],0,0,SIZE,-1);
					seg.update(l[v],r[v],0,0,SIZE,-2);
				}
			}
			ret = max(ret,(ll)seg.query(0,SIZE,0,0,SIZE));
			for(int j=0;j<tmp.size();j++)seg.update(l[tmp[j]],r[tmp[j]],0,0,SIZE,-1);
			idx++;
		}else{
			if(type[i])continue;
			sp.insert(P(A[i],i));
			//printf("add %d\n",i);
			seg.update(eq[i],l[i],0,0,SIZE,1);
			seg.update(l[i],r[i],0,0,SIZE,2);
		}
		//printf("\n");
	}
	ll base = 0ll;
	for(int i=0;i<N;i++){
		base += i-bit.sum(A[i]);
		bit.add(A[i],1);
	}
	//cout  << base << ' ' << ret << endl;
	if(base==0ll){
		if(sz(zip)==N)printf("1\n");
		else printf("0\n");
	}
	else printf("%lld\n",base-ret-1);
	return 0;
}