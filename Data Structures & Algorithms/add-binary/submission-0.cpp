class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1,j=b.length()-1,c=0;
        string ans;
        while(i>=0 || j>=0 || c){
            int b1=0,b2=0;
            if(i>=0)b1 = a[i]=='1'? 1 : 0;
            if(j>=0)b2 = b[j]=='1'? 1 : 0;
            int sum = b1 + b2 + c;
            ans += ((sum%2) + '0');
            c = sum/2;
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
