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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
int A[100100],AA[100100];
vector<int> v;
int B[200100];
int ans[100100];
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		scanf("%d",&A[i]);
		A[i]--;
		int a=(A[i]-i+N)%N;
		v.pb(a);
		v.pb(a+N);
	}
	sort(all(v));
	vector<int>::iterator it;
	for(int i=0;i<N;i++){ 
		it = upper_bound(all(v),i);
		B[i]=N-(*it-i);
		B[i+N]=B[i];
	}
	int cur = INF;
	for(int i=2*N-1;i>=0;i--){
		cur = min(cur,i+B[i]);
		if(i<N){
			ans[i] = cur-i+min(i,N-i);
		}
	}
	v.clear();
	for(int i=1;i<N;i++)AA[N-i]=N-A[i];
	for(int i=1;i<N;i++){
		int a=(AA[i]-i+N)%N;
		v.pb(a);
		v.pb(a+N);
	}
	sort(all(v));
	for(int i=0;i<N;i++){ 
		it = upper_bound(all(v),i);
		B[i]=N-(*it-i);
		B[i+N]=B[i];
	}
	cur = INF;
	for(int i=2*N-1;i>=0;i--){
		cur = min(cur,i+B[i]);
		if(i<N){
			ans[(N-i)%N] = min(ans[(N-i)%N],cur-i+min(i,N-i));
		}
	}
	for(int i=0;i<N;i++)printf("%d\n",ans[i]);
	return 0;
}