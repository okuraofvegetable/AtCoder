#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int K,N,M;
int s[100100];
int rem;
vector<int> vec;
int cnt(int X){
	int k = upper_bound(all(vec),X)-vec.begin();
	return K-k;
}
vector<int> A,B;
int main(){
	scanf("%d %d %d",&K,&N,&M);
	for(int i=0;i<K;i++){
		scanf("%d",&s[i]);
		vec.pb(s[i]);
	}
	sort(all(vec));
	rem = 100*(N-M);
	int border = (K+11)/12;
	for(int i=0;i<K;i++){
		if(cnt(s[i]-rem)-(rem!=0?1:0)<border)A.pb(i+1);
		if(cnt(s[i]+rem)<border)B.pb(i+1);
	}
	for(int i=0;i<A.size();i++)printf("%d\n",A[i]);
	printf("--------\n");
	for(int i=0;i<B.size();i++)printf("%d\n",B[i]);
	return 0;
}