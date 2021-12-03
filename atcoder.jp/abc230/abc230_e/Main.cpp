#include <bits/stdc++.h>
using namespace std;
 
// Function to return the summation of
// the given harmonic series
long long int getSum(long long int n)
{
 
    // To store the summation
    long long int sum = 0;
 
    // Floor of sqrt(n)
    long long int k = sqrt(n);
 
    // Summation of floor(n / i)
    for (long long int i = 1; i * i <= n; i++) {
        sum += floor(n / i);
    }
 
    // From the formula
    sum *= 2;
    sum -= k * k;
 
    return sum;
}
 
// Driver code
int main()
{
    long long int n;
    std::cin >> n;
 
    cout << getSum(n) << std::endl;
 
    return 0;
}