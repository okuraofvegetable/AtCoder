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
priority_queue<P,vector<P>,greater<P> > q;
int N,M;
int X,Y;
int a[100100],b[100100];
int main(){
	scanf("%d %d",&N,&M);
	scanf("%d %d",&X,&Y);
	for(int i=0;i<N;i++)scanf("%d",&a[i]);
	for(int i=0;i<M;i++)scanf("%d",&b[i]);
	int x = 0,y = 0,cnt = 0,t = 0;
	while(1){
		while(x<N&&a[x]<t)x++;
		if(x>=N)break;
		t = a[x]+X;
		cnt++;
		while(y<M&&b[y]<t)y++;
		if(y>=M)break;
		t = b[y]+Y;
		cnt++;
	}
	cout << cnt/2 << endl;
	return 0;
}