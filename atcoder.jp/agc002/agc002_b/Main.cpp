#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M;
int cnt[100100];
int state[100100];
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cnt[i]=1;
		state[i]=0;
	}
	state[0]=2;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		if(state[a]==2){
			if(cnt[b]>0)state[b]=1;
			else state[b]=2;
			state[a]=0;
		}else if(state[a]==1){
			state[b]=1;
		}else{
			if(state[b]==2){
				state[b]=1;
			}
		}
		cnt[a]--;cnt[b]++;
		if(cnt[a]==0)state[a]=0;
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(state[i]>0)ans++;
	}
	cout << ans << endl;
	return 0;
}