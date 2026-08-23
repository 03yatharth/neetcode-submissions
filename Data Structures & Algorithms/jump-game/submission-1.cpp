class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        while(l<=r){
            r = max(r,l+nums[l]);
            if(r>=n-1)return true;
            l++;
        }
        return false;
    }
};