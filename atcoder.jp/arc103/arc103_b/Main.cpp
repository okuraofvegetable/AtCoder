#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
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
int X[1010],Y[1010];
int U[1010],V[1010];
int A[40],B[40];
string str = "LDUR";
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		scanf("%d %d",&X[i],&Y[i]);
		U[i] = X[i]+Y[i];
		V[i] = X[i]-Y[i];
	}
	for(int i=0;i<N;i++){
		if((U[0]&1)!=(U[i]&1)){
			cout << -1 << endl;
			return 0;
		}
	}
	bool flip = false;
	if((U[0]&1)==0){
		for(int i=0;i<N;i++){
			U[i]++;
			V[i]++;
		}
		flip = true;
	}
	if(!flip){
		cout << 31 << endl;
		for(int i=0;i<31;i++){
			printf("%d ",1<<i);
		}
		printf("\n");
		for(int i=0;i<N;i++){
			int a = 0,b = 0;
			if(U[i]<0){
				a=1;
				U[i]*=-1;
			}
			if(V[i]<0){
				b=1;
				V[i]*=-1;
			}
			int s = 0, t = 0;
			for(int j=30;j>=0;j--){
				if(s==0){
					A[j]=1;
					s = 1;
				}else A[j]=0;
				if((U[i]>>j)&1)s=0;
				if(t==0){
					B[j]=1;
					t = 1;
				}else B[j]=0;
				if((V[i]>>j)&1)t=0;	
			}
			for(int j=0;j<31;j++){
				printf("%c",str[(A[j]^a)*2+(B[j]^b)]);
			}
			printf("\n");
		}
	}else{
		cout << 32 << endl;
		for(int i=0;i<31;i++){
			printf("%d ",1<<i);
		}
		printf("1\n");
		for(int i=0;i<N;i++){
			int a = 0,b = 0;
			if(U[i]<0){
				a=1;
				U[i]*=-1;
			}
			if(V[i]<0){
				b=1;
				V[i]*=-1;
			}
			int s = 0, t = 0;
			for(int j=30;j>=0;j--){
				if(s==0){
					A[j]=1;
					s = 1;
				}else A[j]=0;
				if((U[i]>>j)&1)s=0;
				if(t==0){
					B[j]=1;
					t = 1;
				}else B[j]=0;
				if((V[i]>>j)&1)t=0;	
			}
			for(int j=0;j<31;j++){
				printf("%c",str[(A[j]^a)*2+(B[j]^b)]);
			}
			printf("L\n");
		}
	}
	return 0;
}