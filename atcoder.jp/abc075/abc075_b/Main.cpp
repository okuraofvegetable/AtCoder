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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int H,W;
string s[55];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={-1,1,-1,0,1,-1,0,1};
char cnt(int x,int y){
	int c = 0;
	for(int d=0;d<8;d++){
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(nx<0||ny<0||nx>=H||ny>=W)continue;
		if(s[nx][ny]=='#')c++;
	}
	return (char)('0'+c);
}
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> s[i];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(s[i][j]=='#')printf("#");
			else printf("%c",cnt(i,j));
		}
		printf("\n");
	}
	return 0;
}