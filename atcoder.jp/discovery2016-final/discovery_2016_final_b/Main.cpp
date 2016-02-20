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
int N,X;
int T[100100],A[100100];
vector<int> dish[100100];
bool check(int x){
	int idx=N-1;
	priority_queue<int> q;
	for(int i=100000;i>x;i--){
		for(int j=0;j<dish[i].size();j++){
			q.push(dish[i][j]);
		}
	}
	ll sum = 0;
	for(int i=x;i>0;i--){
		for(int j=0;j<dish[i].size();j++){
			q.push(dish[i][j]);
		}
		if(!q.empty()){
			sum += q.top();
			q.pop();
		}
	}
	return sum>=X;
}
int main(){
	scanf("%d %d",&N,&X);
	for(int i=0;i<N;i++){
		scanf("%d",&T[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		dish[T[i]].pb(A[i]);
	}
	int l=0,r=100100;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r==100100)printf("-1\n");
	else printf("%d\n",r);
	return 0;
}