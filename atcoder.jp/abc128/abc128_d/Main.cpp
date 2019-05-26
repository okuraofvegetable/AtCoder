#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
int N,K;
int V[55];
int rui[55];
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++)cin >> V[i];
	rui[0]=V[0];
	for(int i=1;i<N;i++)rui[i]=rui[i-1]+V[i];
	int ans = 0;
	for(int i=0;i<=min(K,N);i++){
		for(int l=0;l<=i;l++){
			vector<int> vec;
			for(int j=0;j<l;j++)vec.pb(V[j]);
			for(int j=0;j<i-l;j++)vec.pb(V[N-1-j]);
			sort(all(vec));
			int ig = K-i;
			int cnt=0;
			int sum = 0;
			for(int j=0;j<vec.size();j++){
				if(vec[j]<0&&cnt<ig){
					cnt++;
					continue;
				}
				sum += vec[j];
			}
			ans = max(ans,sum);
		}
	}
	cout << ans << endl;
	return 0;
}