#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,P> F;
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
const int SIZE = 500000;
struct BIT{
	int bit[SIZE+10];
	void add(int i,int x){
		i++;
		while(i<=SIZE){
			bit[i]+=x;
			i += i&-i;
		}
	}
	int sum(int i){
		i++;
		int res = 0;
		while(i>0){
			res+=bit[i];
			i -= i&-i;
		}
		return res;
	}
}bit;
int N;
int D[300100];
vector<int> vec[300100];
vector<int> zip;
ll ans = 0ll;
ll L[300100],R[300100];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&D[i]);
		zip.pb(D[i]);
	}
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<N;i++){
		int k = lower_bound(all(zip),D[i])-zip.begin();
		vec[k].pb(i);
		bit.add(i,1);
	}
	int rem = N;
	for(int i=0;i<zip.size();i++){
		int M = sz(vec[i]);
		rem -= M;
		for(int j=0;j<M;j++)bit.add(vec[i][j],-1);
		for(int j=0;j<M;j++){
			L[j]=bit.sum(vec[i][j]);
			R[j]=rem-L[j];
		}
		for(int j=1;j<M;j++){
			L[j]+=L[j-1];
			R[M-1-j]+=R[M-j];
		}
		ll ret = min(L[M-1],R[0]);
		for(int j=0;j<M-1;j++)ret = min(ret,L[j]+R[j+1]);
		ans += ret;
	}
	printf("%lld\n",ans);
	return 0;
}