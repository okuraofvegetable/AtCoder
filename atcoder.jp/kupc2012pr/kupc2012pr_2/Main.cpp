#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int num[14];
bool bsort(char a[],char b[])
{
	if(strcmp(a,b)>0)return false;
	else if(strcmp(a,b)<0)return true;
	else return false;
}
int main()
{
	int k,n;
	cin >> n >> k;
	char t[n][k+1];
	char tmp[k+1];
	for(int i=0;i<n;i++)
	{
		cin >> t[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(bsort(t[j],t[j+1]))
			{
				strcpy(tmp,t[j]);
				strcpy(t[j],t[j+1]);
				strcpy(t[j+1],tmp);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << t[i];
	}
	printf("\n");
	return 0;
}
