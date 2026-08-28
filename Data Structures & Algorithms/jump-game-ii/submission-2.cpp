class Solution {
public:
    int jump(vector<int>& nums) {
        int jmp=0,l=0,r=0,n=nums.size();
        while(r<n){
            if(r==n-1)return jmp;
            int maxR = 0;
            for(int i=l;i<=r;i++){
                maxR = max(maxR,i+nums[i]);
            }
            l=r;
            r = maxR;
            jmp++;
        }
        return jmp;
    }
};