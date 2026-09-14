class Solution {
public:
    long long minEnd(int n, int x) {
        int X=x;
        long long ans=0;
        int num = n-1;
        for(int i=0;i<64;i++){
            if((X&1)==0){
                if(num&1)ans|= ((long long)1<<i);
                num>>=1;
            }
            else ans|= ((long long)1<<i);
            X>>=1;
        }
        return ans;
    }
};