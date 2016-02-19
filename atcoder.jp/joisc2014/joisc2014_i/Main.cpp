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
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
P p[200100];
const int SIZE = 200100;
struct BIT{
	vector<int> bitx[SIZE],bity[SIZE];
	void add(int i,int x){
		int ax = p[x].X,ay = p[x].Y;
		while(i<=N){
			while(!bitx[i].empty()&&bitx[i].back()<ax){
				bitx[i].pop_back();
				bity[i].pop_back();
			}
			bitx[i].pb(ax);
			bity[i].pb(ay);
			i += i&-i;
		}
	}
	ll sum(int i){
		ll res = 0ll;
		int crt = -1;
		while(i>0){
			int num = sz(bity[i]);
			int k = lower_bound(all(bity[i]),crt)-bity[i].begin();
			res += num-k;
			if(k<num)crt = bity[i].back();
			i -= i&-i;
		}
		return res;
	}
}bit;
vector<int> zip;
bool comp_y(P a,P b){
	return a.Y < b.Y;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d %d",&p[i].X,&p[i].Y);
		zip.pb(p[i].X);
	}
	sort(all(zip));
	for(int i=0;i<N;i++){
		p[i].X = lower_bound(all(zip),p[i].X)-zip.begin()+1;	
	}
	sort(p,p+N,comp_y);
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		ans += bit.sum(p[i].X);
		bit.add(p[i].X,i);
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}