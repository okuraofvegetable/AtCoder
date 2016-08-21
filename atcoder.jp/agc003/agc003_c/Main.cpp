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
int N;
vector<int> A;
vector<int> odd,even;
int main(){
	scanf("%d",&N);
	A.resize(N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	vector<int> zip = A;
	sort(all(zip));
	for(int i=0;i<N;i++)A[i]=lower_bound(all(zip),A[i])-zip.begin();
	for(int i=0;i<N;i++){
		if(i%2==0)even.pb(A[i]);
		else odd.pb(A[i]);
	}
	sort(all(odd));
	sort(all(even));
	for(int i=0;i<odd.size();i++)A[i*2+1]=odd[i];
	for(int i=0;i<even.size();i++)A[i*2]=even[i];
	//for(int i=0;i<N;i++)printf("%d ",A[i]);
	//puts("");
	ll ans = 0;
	for(int i=0;i<N;i++){
		if(i%2!=A[i]%2)ans++;
	}
	printf("%lld\n",ans/2);
	return 0;
}