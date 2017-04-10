// AOJ ITP1_1_C Rectangles
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[55][30];
int a[30];
string s[55];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	cin >> s[i];
    	for(int j=0;j<s[i].size();j++){
    		cnt[i][s[i][j]-'a']++;
    	}
    }
    for(int i=0;i<26;i++){
    	a[i]=10000;
    	for(int j=0;j<n;j++){
    		a[i]=min(a[i],cnt[j][i]);
    	}
    }
    for(int i=0;i<26;i++){
    	for(int j=0;j<a[i];j++)printf("%c",'a'+i);
    }
	printf("\n");
    return 0;
}