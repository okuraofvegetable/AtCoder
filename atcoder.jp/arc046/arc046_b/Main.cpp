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
int N,A,B;
bool win[2][105];
int main(){
	scanf("%d %d %d",&N,&A,&B);
	/*win[0][0]=false;
	win[1][0]=false;
	for(int i=1;i<100;i++){
		win[0][i]=false;
		for(int j=1;j<=A;j++){
			win[0][i]|=(i-j>=0&&!win[1][i-j]);
		}	
		for(int j=1;j<=B;j++){
			win[1][i]|=(i-j>=0&&!win[0][i-j]);
		}
		cout << i << ' ' << win[0][i] << ' ' << win[1][i] << endl;
	}*/
	if(N<=A){
		printf("Takahashi\n");
		return 0;
	}
	if(N<=B){
		printf("Aoki\n");
		return 0;
	}
	if(A==B){
		if(N%(A+1)==0)printf("Aoki\n");
		else printf("Takahashi\n");
		return 0;
	}
	if(A>B)printf("Takahashi\n");
	else printf("Aoki\n");
	return 0;
}
