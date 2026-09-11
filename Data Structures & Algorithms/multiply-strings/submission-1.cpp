class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return  "0";
        int n=num1.size(),m=num2.size();
        vector<int> prod(n+m+1,0);
        int lastInd=n+m;
        string ans;
        for(int i=n-1;i>=0;i--){
            int ind = lastInd;
            for(int j=m-1;j>=0;j--){
                int cur = prod[ind];
                int a=num1[i]-'0',b=num2[j]-'0';
                cur += (a*b);
                prod[ind]=cur%10;
                if(ind-1>=0)prod[ind-1]+=cur/10;
                ind--;
            }
            lastInd--;
        }

        int i=0;
        while(i<n+m+1 && prod[i]==0)i++;
        while(i<n+m+1)ans+=(prod[i++]+'0');
        return ans;
    }
};