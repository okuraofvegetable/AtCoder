#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
const int SIZE = 1<<18;
struct segtree{
	int seg[SIZE*2];
	segtree(){
		for(int i=0;i<SIZE*2;i++)seg[i]=INF;
	}
	void update(int k,int x){
		k += SIZE-1;
		seg[k]=x;
		while(k){
			k = (k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l)return INF;
		else if(a<=l&&r<=b)return seg[k];
		else return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
	int query(int a,int b){
		return query(a,b,0,0,SIZE);
	}
};
segtree seg1,seg2;
int N,Q;
string s,t;
int sa[100100],sb[100100],sc[100100];
int ta[100100],tb[100100],tc[100100];
int main(){
	scanf("%d",&N);
	cin >> s;
	t = s;
	reverse(all(t));
	for(int i=0;i<N;i++){
		if(t[i]=='(')t[i]=')';
		else if(t[i]==')')t[i]='(';
	}
	for(int i=0;i<N;i++){
		sa[i+1]=sa[i]+(s[i]=='(');
		sb[i+1]=sb[i]+(s[i]=='?');
		sc[i+1]=sc[i]+(s[i]==')');
	}
	for(int i=1;i<=N;i++)seg1.update(i,sa[i]+sb[i]-sc[i]);
	for(int i=0;i<N;i++){
		ta[i+1]=ta[i]+(t[i]=='(');
		tb[i+1]=tb[i]+(t[i]=='?');
		tc[i+1]=tc[i]+(t[i]==')');
	}
	for(int i=1;i<=N;i++)seg2.update(i,ta[i]+tb[i]-tc[i]);
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		bool flag = true;
		if((r-l+1)%2==1)flag = false;
		int half = (r-l+1)/2,na = sa[r]-sa[l-1],nb = sc[r]-sc[l-1];
		if(max(na,nb)>half)flag = false;
		int pre,mi;
		pre = sa[l-1]+sb[l-1]-sc[l-1];
		mi = seg1.query(l,r+1);
		//printf("%d %d\n",pre,mi);
		if(pre>mi)flag = false;
		swap(l,r);
		l = N-l+1,r = N-r+1;
		pre = ta[l-1]+tb[l-1]-tc[l-1];
		mi = seg2.query(l,r+1);
		//printf("%d %d\n",l,r);
		if(pre>mi)flag = false;
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}