#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
  
// Number of bits to  
// represent int 
#define INT_BITS 62 
  
// Function to return 
// maximum XOR subse 
// in se[] 
ll maxSubarrayXOR(ll se[], int n) { 
    // Initialize index of 
    // chosen elements 
    int index = 0; 
  
    // Traverse through all 
    // bits of integer  
    // starting from the most 
    // significant bit (MSB) 
    for (int i = INT_BITS-1; i >= 0; i--) { 
        // Initialize index of 
        // maximum element and 
        // the maximum element 
        int maxInd = index; 
        ll maxEle = -1ll; 
        for (int j = index; j < n; j++) { 
            // If i'th bit of se[j] 
            // is se and se[j] is  
            // greater than max so far. 
            if ( (se[j] & (1ll << i)) != 0ll  
                     && se[j] > maxEle ) 
                maxEle = se[j], maxInd = j; 
        } 
  
        // If there was no  
        // element with i'th 
        // bit se, move to 
        // smaller i 
        if (maxEle == -1) 
        continue; 
  
        // Put maximum element 
        // with i'th bit se  
        // at index 'index' 
        swap(se[index], se[maxInd]); 
  
        // Update maxInd and  
        // increment index 
        maxInd = index; 
  
        // Do XOR of se[maxIndex] 
        // with all numbers having 
        // i'th bit as se. 
        for (int j=0; j<n; j++){ 
            // XOR se[maxInd] those 
            // numbers which have the 
            // i'th bit se 
            if (j != maxInd && 
               (se[j] & (1ll << i)) != 0ll) 
                se[j] = se[j] ^ se[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        index++; 
    } 
  
    // Final result is  
    // XOR of all elements 
    ll res = 0ll; 
    for (int i = 0; i < n; i++) 
        res ^= se[i]; 
    return res; 
}
vector<int> ind;
ll convert(ll x){
	ll ret = 0ll;
	for(int i=0;i<ind.size();i++){
	 ret += ((x>>ind[i])&1ll)<<i;
	}
	return ret;
}	
ll se[100100]; 
ll t[100100];
int N;
int main() { 
    cin >> N;
    ll ans = 0ll;
    for(int i=0;i<N;i++){
        cin >> se[i];
        ans ^= se[i];
    }
		for(int i=0;i<63;i++){
			if(((ans>>i)&1ll)==0ll){
				ind.push_back(i);
			}
		}
		for(int i=0;i<N;i++){
			t[i] = convert(se[i]);
		}
    //cout << "Max subse XOR is "; 
		//cout << ans << endl;
		ll mt = maxSubarrayXOR(t,N);
		//cout << mt << endl;
		for(int i=0;i<ind.size();i++){
			if((mt>>i)&1ll)ans += (1ll<<(ind[i]+1));
		}
    cout << ans<< endl; 
    return 0; 
} 
