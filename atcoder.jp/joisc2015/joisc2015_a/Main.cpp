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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int K,M,Q;
char str[200100];
int A[200100],B[200100],C[200100];
int main(){
	scanf("%d %d",&K,&M);
	scanf("%s",str);
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		scanf("%d %d %d",&A[i],&B[i],&C[i]);
	}
	for(int i=0;i<K;i++){
		int now = i;
		for(int j=Q-1;j>=0;j--){
			int L = B[j]-A[j];
			if(now>=C[j]+L){
				now -= L;
			}else if(C[j]<=now&&now<C[j]+L){
				now = A[j]+now-C[j];
			}
			//printf("%d ",now);
		}
		printf("%c",str[now]);
	}
	printf("\n");
	return 0;
}