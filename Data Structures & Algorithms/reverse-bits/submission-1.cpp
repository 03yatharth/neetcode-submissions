class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bit = n&1;
            ans<<=1;
            ans|=bit;
            n>>=1;
        }
        return ans;
    }
};