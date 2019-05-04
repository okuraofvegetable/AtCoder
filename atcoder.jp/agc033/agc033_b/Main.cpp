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
int H,W,N;
int sx,sy;
string S[2];
int L[2][200100];
int R[2][200100];
int U[2][200100];
int D[2][200100];
int cntL(int id,int a,int b){
	//[a,b]
	if(a==0)return L[id][b];
	return L[id][b]-L[id][a-1];
}
int cntR(int id,int a,int b){
	//[a,b]
	if(a==0)return R[id][b];
	return R[id][b]-R[id][a-1];
}
int cntU(int id,int a,int b){
	//[a,b]
	if(a==0)return U[id][b];
	return U[id][b]-U[id][a-1];
}
int cntD(int id,int a,int b){
	//[a,b]
	if(a==0)return D[id][b];
	return D[id][b]-D[id][a-1];
}
int main(){
	cin >> H >> W >> N;
	cin >> sx >> sy;
	sx--;sy--;
	cin >> S[0];
	cin >> S[1];
	for(int i=0;i<2;i++){
		for(int j=0;j<N;j++){
			if(S[i][j]=='L'){
				L[i][j]++;
			}
			if(S[i][j]=='R'){
				R[i][j]++;
			}
			if(S[i][j]=='U'){
				U[i][j]++;
			}
			if(S[i][j]=='D'){
				D[i][j]++;
			}
		}
		for(int j=1;j<N;j++){
			L[i][j]+=L[i][j-1];
			R[i][j]+=R[i][j-1];
			U[i][j]+=U[i][j-1];
			D[i][j]+=D[i][j-1];
		}
	}
	int cx,cy;
	cx = sx;
	cy = sy;
	for(int i=0;i<N;i++){
		if(S[0][i]=='R')cy++;
		if(cy>=W){
			cout << "NO" << endl;
			return 0;
		}
		if(S[1][i]=='L'&&cy>0)cy--;
	}
	cx = sx;
	cy = sy;
	for(int i=0;i<N;i++){
		if(S[0][i]=='L')cy--;
		if(cy<0){
			cout << "NO" << endl;
			return 0;
		}
		if(S[1][i]=='R'&&cy<W-1)cy++;
	}
	cx = sx;
	cy = sy;
	for(int i=0;i<N;i++){
		if(S[0][i]=='U')cx--;
		if(cx<0){
			cout << "NO" << endl;
			return 0;
		}
		if(S[1][i]=='D'&&cx<H-1)cx++;
	}
	cx = sx;
	cy = sy;
	for(int i=0;i<N;i++){
		if(S[0][i]=='D')cx++;
		if(cx>=H){
			cout << "NO" << endl;
			return 0;
		}
		if(S[1][i]=='U'&&cx>0)cx--;
	}
	cout << "YES" << endl;
	return 0;
}