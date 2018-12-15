#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 100000000000000000ll
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
ll add(ll a,ll b){
	return a+b;
}
struct P{
	ll x,y;
	int val;
	P() {}
	P(ll x,ll y):x(x),y(y){}
	P(ll x,ll y,int val):x(x),y(y),val(val){}
	P operator +(P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator -(P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator *(double d){
		return P(d*x,d*y);
	}
	ll dot(P p){
		return add(x*p.x,y*p.y);
	}
	ll det(P p){
		return add(x*p.y,-y*p.x);
	}
};
bool comp(const P& p,const P& q){
	if(p.x!=q.x)return p.x<q.x;
	return p.y<q.y;
}
vector<P> convex_hull(P* ps,int n){
	sort(ps,ps+n,comp);
	int k=0;
	vector<P> qs(2*n);
	for(int i=0;i<n;i++){
		while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<0ll)k--;
		qs[k++]=ps[i];
	}
	for(int i=n-2,t=k;i>=0;i--){
		while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<0ll)k--;
		qs[k++]=ps[i];
	}
	qs.resize(k-1);
	return qs;
}
int R,C,N;
int M;
P ps[200100];
bool used[100100];
bool Xedge(int x){
	if(x==0||x==R)return true;
	else return false;
}
bool Yedge(int y){
	if(y==0||y==C)return true;
	else return false;
}
int main(){
	cin >> R >> C >> N;
	for(int i=0;i<N;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if((Xedge(x1)||Yedge(y1))&&(Xedge(x2)||Yedge(y2))){
			ps[2*M]=P(x1,y1,i+1);
			ps[2*M+1]=P(x2,y2,i+1);
			M++;
		}
	}
	M*=2;
	vector<P> ch = convex_hull(ps,M);
	assert(ch.size()==M);
	/*for(int i=0;i<ch.size();i++){
		cout << ch[i].x << ' ' << ch[i].y << ' ' << ch[i].val << endl;
 	}*/
 	stack<int> s;
 	for(int i=0;i<ch.size();i++){
 		int c = ch[i].val;
 		if(used[c]){
 			if(s.top()!=c){
 				printf("NO\n");
 				return 0;
 			}
 			s.pop();
 		}else{
 			s.push(c);
 			used[c]=true;
 		}
 	}
 	printf("YES\n");
	return 0;
}