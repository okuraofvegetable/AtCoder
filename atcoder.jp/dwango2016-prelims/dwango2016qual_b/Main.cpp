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
int A[100100];
int B[100100];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)scanf("%d",&A[i]);
	B[0]=A[0];
	for(int i=1;i<N;i++){
		if(B[i-1]!=A[i-1])B[i]=A[i-1];
		else if(A[i-1]<A[i])B[i]=A[i-1];
		else B[i]=A[i];
	}
	B[N-1]=A[N-2];
	for(int i=0;i<N;i++)printf("%d%c",B[i],(i==N-1)?'\n':' ');
	return 0;
}