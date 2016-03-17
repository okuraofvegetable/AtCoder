#include <bits/stdc++.h>
#include "Memory_lib.h"
using namespace std;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int merge(int A,int B,int C,int D){
	int ret = A;
	ret<<=7;
	ret+=B;
	ret<<=7;
	ret+=C;
	ret<<=1;
	ret+=D;
	return ret;
}
int Memory(int N, int M) {
	int M_ = M;
	int type = M&1;
	M >>= 1;
	int stack_len = M&((1<<7)-1);
	M >>= 7;
	int idx = M&((1<<7)-1);
	M >>= 7;
	int loop_num = M&((1<<7)-1);
	if(idx>N||loop_num>N||stack_len>N){
		return -2;
	}
	if(loop_num==N)return -1;
	if(idx==N){
		if(stack_len!=0)return -2;
		return merge(loop_num+1,0,0,0);
	}
	char c = Get(idx+1);
	if(c=='['||c=='<'){
		if(stack_len==loop_num){
			if(c=='[')type=0;
			else type=1;
		}
		stack_len++;
	}else{
		if(stack_len-1==loop_num){
			if(c==']'&&type==1){
				return -2;
			}
			if(c=='>'&&type==0){
				return -2;
			}
		}
		stack_len--;
	}
	idx++;
	return merge(loop_num,idx,stack_len,type);
}