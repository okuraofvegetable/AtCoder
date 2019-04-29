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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,M;
int A[305][305];
int idx[305];
bool del[305];
int cnt[305];
bool check(int k){
	memset(idx,0,sizeof(idx));
	memset(del,false,sizeof(del));
	while(1){
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<N;i++){
			cnt[A[i][idx[i]]]++;
		}
		int mx = -1;
		for(int i=0;i<M;i++){
			if(!del[i]&&(mx==-1||cnt[mx]<cnt[i]))mx = i;
		}
		assert(mx!=-1);
		if(cnt[mx]<=k)return true;
		del[mx]=true;
		for(int i=0;i<N;i++){
			while(idx[i]<M&&del[A[i][idx[i]]])idx[i]++;
			if(idx[i]==M)return false;
			assert(!del[A[i][idx[i]]]);
		}
	}
}
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
			A[i][j]--;
		}
	}
	int l = 0,r = N;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout << r << endl;
	return 0;
}