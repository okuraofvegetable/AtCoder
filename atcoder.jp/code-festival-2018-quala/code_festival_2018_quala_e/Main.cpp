#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct event{
	ll l;
	bool type;
	int id,x;
	event(){}
	event(ll l,bool t,int id,int x):l(l),type(t),id(id),x(x){}
	bool operator < (const event& a) const{
		if(l!=a.l)return l<a.l;
		if(type!=a.type)return type;
		return x<a.x;
	}
};
int X,Y,N,D;
ll A[200100],B[200100],C[200100];
int L[200100],R[200100];
vector<event> in,out;
bool check(ll k){
	//cout << k << endl;
	for(int i=0;i<N;i++){
		L[i]=-1;
		R[i]=-1;
	}
	int good = 0, Lsum = 0, Rsum = 0;
	int en = in.size()+out.size();
	int a = 0, b = 0;
	for(int i=0;i<en;i++){
		event e,f;
		if(a==in.size())e = out[b++];
		else if(b==out.size())e = in[a++];
		else{
			e = in[a];
			f = out[b];
			e.l -= k;
			if(f<e){
				e = f;
				b++;
			}else{
				a++;
			}
		}
		//ll l = e.l;
		bool type = e.type;
		int id = e.id;
		int x = e.x;
		//printf("%lld %d %d %d\n",l,type,id,x);
		if(type){
			if(L[id]==-1){
				good++;
				L[id]=R[id]=x;
				Lsum += x;
				Rsum += x;
			}else if(x<L[id]||R[id]<x){
				if(R[id]<x){
					Rsum -= R[id];
					R[id] = x;
					Rsum += R[id];
				}else{
					Lsum -= L[id];
					L[id] = x;
					Lsum += x;
				}
			}
		}else{
			assert(L[id]<=x&&x<=R[id]);
			if(L[id]==R[id]){
				Lsum -= L[id];
				Rsum -= R[id];
				L[id]=R[id]=-1;
				good--;
			}else if(L[id]==x){
				Lsum++;
				L[id]++;
			}else{
				Rsum--;
				R[id]--;
			}
		}
		if(good==N&&Lsum<=X&&X<=Rsum)return true;
	}
	return false;
}
int main(){
	scanf("%d %d %d",&X,&Y,&N);
	D = (X+Y)/N;
	for(int i=0;i<N;i++){
		scanf("%lld %lld",&A[i],&B[i]);
		C[i] = A[i]-B[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<=min(D,X);j++){
			ll s = C[i]*j+B[i]*D;
			in.pb(event(s,true,i,j));
			out.pb(event(s,false,i,j));
		}
	}
	sort(all(in));
	sort(all(out));
	ll l = -1ll, r = LLINF;
	while(r-l>1ll){
		ll mid = (l+r)/2ll;
		if(check(mid))r=mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}