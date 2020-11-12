#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *l,*r;
};
node* parse(string S){
	// cout << S << endl;
	int nest = 0;
	int val = 0;
	int st = -1;
	int end = -1;
	for(int i=0;i<S.size();i++){
		if(S[i]=='('){
			nest++;
		}else if(S[i]==')'){
			nest--;
		}
		if(nest==0&&S[i]=='['){
			st = i;
		}
		if(st!=-1&&'0'<=S[i]&&S[i]<='9'){
			val = val*10+(int)(S[i]-'0');
		}
		if(st!=-1&&S[i]==']'){
			end = i;
			break;
		}
	}
	if(st==-1){
		return NULL;
	}
	//cout << st << ' ' << end << endl;
	node* v = (node*)malloc(sizeof(node));
	v->val = val;
	v->l = parse(S.substr(1,st-2));
	v->r = parse(S.substr(end+2,S.size()-end-3));
	return v; 
}
node* conv(node* a,node* b){
	node* v = (node*)malloc(sizeof(node));
	v->val = (a->val)+(b->val);
	if((a->l)==NULL||(b->l)==NULL)v->l = NULL;
	else v->l = conv(a->l,b->l);
	if((a->r)==NULL||(b->r)==NULL)v->r = NULL;
	else v->r = conv(a->r,b->r);
	return v;
}
void print(node* v){
	if(v==NULL){
		cout << "";
		return;
	}
	cout << '(';
	print(v->l);
	cout << ')';
	cout << '[' <<  v->val << ']';
	cout << '(';
	print(v->r);
	cout << ')';
	return;
}
string s,t;
int main(){
	cin >> s >> t;
	node *a = parse(s);
	node *b = parse(t);
	node *c = conv(a,b);
	print(c);
	cout << endl;
	return 0;
}
