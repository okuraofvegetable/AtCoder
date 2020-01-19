#include <stdio.h>
int main(void)
{
	int n,i,a,b,A,B;
	//while(1)
	{
		A = 0;
		B = 0;
		scanf("%d",&n);
		if(n == 0) return 0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			if(a > b)
			{
				A += a+b;
			}
			else if(a < b)
			{
				B += a+b;
			}
			else
			{
				A += a;
				B += b;
			}
		}
		printf("%d %d\n",A,B);
	}
	return 0;
}
