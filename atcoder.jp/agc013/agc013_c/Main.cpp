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
ll N,L,T;
ll X[100100],W[100100];
vector<int> A;
int main(){
	cin >> N >> L >> T;
	for(int i=0;i<N;i++){
		cin >> X[i] >> W[i];
	}
	ll cnt = 0;
	ll K;
	for(int i=0;i<N;i++){
		int to;
		if(W[i]==1){
			to = (X[i]+T)%L;
		}else{
			to = (X[i]+L-T%L)%L;
		}
		if(i==0)K=to;
		A.pb(to);
		ll dist;
		if(W[i]!=W[0]){
			if(W[0]==1){
				dist = (X[i]-X[0]+L)%L;
			}else{
				dist = (X[0]-X[i]+L)%L;
			}
			if(dist<2*T)cnt += 1+(2*T-dist-1)/L;
		}
	}
	sort(all(A));
	ll id = 0;
	if(W[0]==1){
		id = cnt%N;
	}else{
		id = ((-cnt)%N+N)%N;
	}
	ll idx = -1;
	if(W[0]==2){
		for(int i=N-1;i>=0;i--){
			if(A[i]==K){
				idx = i;
				break;
			}
		}
	}else{
		for(int i=0;i<N;i++){
			if(A[i]==K){
				idx = i;
				break;
			}
		}
	}
	//cout << idx << ' ' << id << endl;
	ll st = (idx-id+N)%N;
	for(int i=0;i<N;i++){
		ll j = (st+i)%N;
		cout << A[j] << endl;
	}
	return 0;
}