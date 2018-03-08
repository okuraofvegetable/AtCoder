#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
int d[105][105];
int a[1010],b[1010],c[1010];
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)d[i][j]=0;
			else d[i][j]=INF;
		}
	}
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		a[i]--;
		b[i]--;
		d[a[i]][b[i]]=c[i];
		d[b[i]][a[i]]=c[i];
	}
	for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	/*for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",d[i][j]);
		}
		cout << endl;
	}*/
	int ans = 0;
	for(int i=0;i<M;i++){
		int f = a[i], t = b[i];
		bool flag = false;
		for(int j=0;j<N;j++){
			if(abs(d[f][j]-d[t][j])==c[i]){
				flag = true;
				break;
			}
		}
		if(!flag)ans++;
	}
	printf("%d\n",ans);
 	return 0;
}