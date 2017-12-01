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
int N;
string s;
int val[55];
int next[55];
deque<int> deq;
int main(){
	cin >> N;
	cin >> s;
	for(int i=0;i<N;i++){
		if(s[i]=='R')val[i]=0;
		if(s[i]=='G')val[i]=1;
		if(s[i]=='B')val[i]=2;
	}
	for(int i=0;i<N;i++){
		next[i]=-1;
		for(int j=i+1;j<N;j++){
			if(val[j]!=val[i]){
				next[i]=val[j];
				break;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(deq.empty())deq.pb(val[i]);
		else if(deq.front()==val[i]){
			deq.pop_front();
		}else if(deq.back()==val[i]){
			deq.pop_back();
		}else if(deq.front()==next[i]){
			deq.push_back(val[i]);
		}else if(deq.back()==next[i]){
			deq.push_front(val[i]);
		}else{
			deq.push_back(val[i]);
		}
	}
	cout << deq.size() << endl;
	return 0;
}