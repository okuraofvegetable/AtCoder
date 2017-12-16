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
struct Trie{
	int child_num;
	int depth;
	bool flag;
	Trie *child[2];
	Trie(int d){
		child_num = 0;
		depth = d;
		flag = false;
		for(int i=0;i<2;i++)child[i]=(Trie *)NULL;
	}
};
Trie *root;
int n;
ll L;
string s[100100];
vector<ll> vec;
void rec(Trie *ptr){
	for(int i=0;i<2;i++){
		//cout << i << endl;
		if(!(ptr->child[i])){
			if(!(ptr->flag)){
				//cout << ptr->depth << ':' << endl;
				vec.pb(L-(ll)(ptr->depth));
			}
		}else{
			rec(ptr->child[i]);
		}
	}
}
void update(string s,Trie *ptr){
	for(int i=0;i<s.size();i++){
		int idx = s[i]-'0';
		if(!(ptr->child[idx])){
			(ptr->child_num)++;
			ptr->child[idx] = new Trie((ptr->depth)+1);
		}
		ptr = ptr->child[idx];
	}
	ptr->flag = true;
	return;
}
int main(){
	scanf("%d %lld",&n,&L);
	root = new Trie(0);
	for(int i=0;i<n;i++)cin >> s[i];
	for(int i=0;i<n;i++)update(s[i],root);
	rec(root);
	ll state = 0ll;
	for(int i=0;i<vec.size();i++){
		//cout << vec[i] << endl;
		state ^= (vec[i]&-vec[i]);
	}
	if(state==0)printf("Bob\n");
	else printf("Alice\n");
	return 0;
}