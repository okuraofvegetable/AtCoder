#include <cstdio>
#include <cstdlib>
#include <cmath>

int c[16];
int n, m, i, j, k, x;

int main(void){
	for(; scanf("%d%d", &n, &m), n; printf("%d\n", x > m ? -1 : x)){
		for(i = 3; i--;)
			for(scanf("%d", &j); j--; c[n-k] = i)
				scanf("%d", &k);
		x = 0;
		for(i = n; i--; k += c[i])
			x += pow(3, i) * abs(k*2%4 - c[i]);
		x = fmin(x, pow(3, n) - 1 - x);
        printf("%d\n", x > m ? -1 : x);
        return 0;
	}
	return 0;
}