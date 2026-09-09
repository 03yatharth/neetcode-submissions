class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1,n=digits.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            int cur = digits[i]+carry;
            ans.push_back(cur%10);
            carry=cur/10;
        }
        if(carry)ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};