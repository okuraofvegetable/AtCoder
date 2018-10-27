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
int H,W;
string s[305];
int A[605][305][305];
int B[605][305][305];
const int g = 300;
const int MAX = g*2;
int getA(int k,int a,int b,int c){ // [a,b]
	if(a>b)return 0;
	if(b<0)return 0;
	a = max(a,0);
	b = min(b,W-1);
	if(a==0)return A[k][b][c];
	return A[k][b][c]-A[k][a-1][c];
}
int getB(int k,int a,int b,int c){ // [a,b]
	if(a>b)return 0;
	if(b<0)return 0;
	a = max(a,0);
	b = min(b,W-1);
	if(a==0)return B[k][b][c];
	return B[k][b][c]-B[k][a-1][c];
}
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> s[i];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(s[i][j]=='#'){
				for(int k=1;k<W;k++){
					if(i-k>=0&&j+k<W&&s[i-k][j+k]=='#')A[i+j][j][k]=1;
					if(i+k<H&&j+k<W&&s[i+k][j+k]=='#')B[i-j+g][j][k]=1;
				}
			}
		}
	}
	for(int i=0;i<=MAX;i++){
		for(int j=0;j<W;j++){
			for(int k=1;k<W;k++){
				A[i][j+1][k]+=A[i][j][k];
				B[i][j+1][k]+=B[i][j][k];
			}
		}
	}
	ll ans = 0ll;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(s[i][j]=='#'){
				for(int k=0;k<=MAX;k++){
					int p = abs(i+j-k);
					int l,r;
					if( p>0 && ((p&1)==0) ){
						int hp = (p>>1);
						if(k<i+j){
							l = j-p;
							r = j-hp-1;
							ans += getA(k,l,r,hp);
							/*if(getA(k,l,r,hp)){
								printf("A1: %d %d %d %d %d %d %d\n",i,j,k,l,r,p,getA(k,l,r,hp));
							}*/
						}else{
							l = j+1;
							r = j+hp;
							ans += getA(k,l,r,hp);
							/*if(getA(k,l,r,hp)){
								printf("A2: %d %d %d %d %d %d %d\n",i,j,k,l,r,p,getA(k,l,r,hp));
							}*/
						}
					}
					p = abs(i-j+g-k);
					if( p>0 && ((p&1)==0) ){
						int hp = (p>>1);
						if(k>i-j+g){
							l = j-p+1;
							r = j-hp;
							ans += getB(k,l,r,hp);
							/*if(getB(k,l,r,hp)){
								printf("B1: %d %d %d %d %d %d %d\n",i,j,k,l,r,p,getB(k,l,r,hp));
							}*/
						}else{
							l = j;
							r = j+hp-1;
							ans += getB(k,l,r,hp);
							/*if(getB(k,l,r,hp)){
								printf("B2: %d %d %d %d %d %d %d\n",i,j,k,l,r,p,getB(k,l,r,hp));
							}*/
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}