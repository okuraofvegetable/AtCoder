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
#include <cassert>
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
#define sq(x) ((x)*(x))
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
double W,H;
double X[55],Y[55];
double dist(int a,int b){
	return sqrt(sq(X[a]-X[b])+sq(Y[a]-Y[b]));
}
bool check(int a,int b,int c,int d){
	double r1 = dist(a,b),r2 = dist(c,d);
	if(X[a]-r1<0||X[a]+r1>W)return false;
	if(Y[a]-r1<0||Y[a]+r1>H)return false;
	if(X[c]-r2<0||X[c]+r2>W)return false;
	if(Y[c]-r2<0||Y[c]+r2>H)return false;
	double r = dist(a,c);
	if(r1-eps>r+r2)return true;
	else return false;
	
}
int main(){
	scanf("%d %lf %lf",&N,&W,&H);
	for(int i=0;i<N;i++)scanf("%lf %lf",&X[i],&Y[i]);
	int ans = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)continue;
			for(int k=0;k<N;k++){
				if(k==i||k==j)continue;
				for(int l=0;l<N;l++){
					if(l==i||l==j||l==k)continue;
					if(check(i,j,k,l))ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}