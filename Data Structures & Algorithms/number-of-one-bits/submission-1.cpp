class Solution {
public:
    int hammingWeight(int n) {
        int ans=0,N=n;
        while(N){
            ans += N&1;
            N>>=1;
        }
        return ans;
    }
};