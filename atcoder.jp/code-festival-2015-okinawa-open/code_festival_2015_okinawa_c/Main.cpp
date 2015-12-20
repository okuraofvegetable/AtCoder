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
int N,cnt=0;
int side[50010],mid[50010];
int state[50010];
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		string s[3];
		for(int j=0;j<3;j++)cin >> s[j];
		if(i%2==0){
			if(s[0][0]=='#'){side[i]++;cnt++;}
			if(s[0][1]=='#'){mid[i]++;cnt++;}
			if(s[0][2]=='#'){side[i]++;cnt++;}
		}else{
			if(s[0][0]=='#'){side[i]++;cnt++;}
			if(s[1][0]=='#'){mid[i]++;cnt++;}
			if(s[2][0]=='#'){side[i]++;cnt++;}
		}
		if(side[i]+mid[i]==3)state[i]=2;
		else if(side[i]==1&&mid[i]==1)state[i]=1;
		else state[i]=0;
	}
	int x = 0;
	for(int i=0;i<N;i++)x^=state[i];
	int rem = 3*N-cnt;
	if(rem%2==0){
		if(x!=0)printf("Snuke\n");
		else printf("Sothe\n");
	}else{
		if(x!=0)printf("Sothe\n");
		else printf("Snuke\n");
	}
	return 0;
}
