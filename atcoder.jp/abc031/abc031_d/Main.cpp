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
#define INF 1000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int K,N;
string v[100];
string w[100];
vector<vector<string> > vec[55];
vector<vector<string> > can[55];
vector<string> cur;
int id;
void split(string s,int n){
	if(n==0){
		if(s=="")vec[id].pb(cur);
		return;
	}
	for(int i=1;i<=min(3,(int)s.size());i++){
		cur.pb(s.substr(0,i));
		split(s.substr(i),n-1);
		cur.pop_back();
	}
}
vector<string> ans;
bool ex = false;
void dfs(int x){
	if(ex)return;
	if(x==N){
		ex = true;
		return;
	}
	vector<string> tmp;
	tmp = ans;
	for(int i=0;i<vec[x].size();i++){
		bool flag = true;
		for(int j=0;j<v[x].size();j++){
			int idx = v[x][j]-'1';
			if(ans[idx]==""){
				ans[idx]=vec[x][i][j];
			}else if(ans[idx]!=vec[x][i][j]){
				flag = false;
				break;
			}
		}
		if(flag)dfs(x+1);
		if(ex)break;
		ans = tmp;
	}
	return;
}
int main(){
	scanf("%d %d",&K,&N);
	for(int i=0;i<N;i++){
		cin >> v[i] >> w[i];
	}
	for(int i=0;i<N;i++){
		id = i;
		split(w[i],(int)v[i].size());
	}
	/*for(int k=0;k<N;k++){
		for(int i=0;i<vec[k].size();i++){
			for(int j=0;j<vec[k][i].size();j++){
				cout << vec[k][i][j];
				if(j==(int)vec[k][i].size()-1)cout << endl;
				else cout << ' ';
			}
		}
		cout << endl;
	}*/
	for(int i=0;i<K;i++)ans.pb("");
	dfs(0);
	for(int i=0;i<K;i++)cout << ans[i] << endl;
	return 0;
}