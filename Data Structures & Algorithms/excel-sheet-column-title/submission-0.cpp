class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans;
        while(n){
            n--;
            ans += 'A' + n%26;
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};