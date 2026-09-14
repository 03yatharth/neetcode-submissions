class Solution {
public:
    long long minEnd(int n, int x) {
        int X=x,ind = 0;
        vector<int> bits(64,0);
        while(X){
            if(X&1)bits[ind]=1;
            ind++;
            X>>=1;
        }
        int num = n-1;
        for(int i=0;i<64;i++){
            if(bits[i])continue;
            if(num&1){
                bits[i]=1;
            }
            num>>=1;
        }
        long long ans=0;
        for(int i=63;i>=0;i--){
            ans<<=1;
            ans|=bits[i];
        }
        return ans;
    }
};