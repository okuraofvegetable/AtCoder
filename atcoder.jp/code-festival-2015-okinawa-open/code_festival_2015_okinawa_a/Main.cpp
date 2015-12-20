#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int H,W,K;
int f[105][105];
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,0,1,-1,0,1,-1};
bool check(int x,int y){
	for(int i=0;i<8;i++){
		int nx = x+dx[i],ny = y+dy[i];
		if(f[nx][ny])return false;
	}
	return true;
}
int main(){
	scanf("%d %d %d",&H,&W,&K);
	int cnt = 0;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(cnt<K&&check(i,j)){
				f[i][j]=1;
				cnt++;
			}
		}			
	}
	if(cnt==K){
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				if(f[i][j])printf("#");
				else printf(".");
			}
			printf("\n");
		}
	}else{
		printf("IMPOSSIBLE\n");
	}
	return 0;
}
