#include <stdio.h>
 
long long int gcd(long long int x, long long int y)
{
  while(x > 0 && y > 0) {
    if(x > y) {
      x = x - y;
    }
    else {
      y = y - x;
    }
  }
 
  if(x == 0) {
    return y;
  }
  else {
    return x;
  }
}
 
long long int approximate_sqrt(long long int x)
{
  long long int root = x/4;
 
  if(x <= 3) {
    return 1;
  }
  
  while(1) {
    root = (root + (x / root)) / 2;
 
    if(root * root <= x && x <= (root+1) * (root+1)) {
      return root;
    }
  }
}
 
int number_of_factors(long long int x)
{
  long long int root_x = approximate_sqrt(x);
  long long int x_iter = x;
  int num = 0;
 
  if(x == 1) {
    return 0;
  }
 
  if(x_iter % 2 == 0) {
    num++;
  }
  while(x_iter % 2 == 0) {
    x_iter = x_iter / 2;
  }
 
  long long int i = 3;
  while(i <= root_x + 1) {
 
    if(x_iter % i == 0) {
      num++;
 
      do {
        x_iter = x_iter / i;
      } while(x_iter % i == 0);
    }
 
    i += 2;
  }
 
  if(x_iter > 1) {
    num++;
  }
 
  return num;
}
 
int main(void)
{
  long long int a, b;
  scanf("%lld%lld", &a, &b);
 
  printf("%d\n", 1 + number_of_factors(gcd(a,b)));
  return 0;
}