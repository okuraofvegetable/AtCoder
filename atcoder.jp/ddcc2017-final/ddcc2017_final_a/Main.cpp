#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int dist(int x,int y){
	return x*x+y*y;
}
int K;
int main(){
	cin >> K;
	int ans = 0;
	for(int i=-100;i<=100;i+=K){
		for(int j=-100;j<=100;j+=K){
			int mx = 0;
			chmax(mx,dist(i,j));
			chmax(mx,dist(i+K,j));
			chmax(mx,dist(i,j+K));
			chmax(mx,dist(i+K,j+K));
			if(mx<=10000)ans++;
		}
	}
	cout << ans << ' ';
	ans = 0;
	for(int i=-150;i<=150;i+=K){
		for(int j=-150;j<=150;j+=K){
			int mx = 0;
			chmax(mx,dist(i,j));
			chmax(mx,dist(i+K,j));
			chmax(mx,dist(i,j+K));
			chmax(mx,dist(i+K,j+K));
			if(mx<=150*150)ans++;
		}
	}
	cout << ans << endl;
	return 0;	
}