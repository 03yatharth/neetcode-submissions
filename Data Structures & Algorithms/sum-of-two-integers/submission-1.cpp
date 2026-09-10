class Solution {
public:
    int getSum(int a, int b) {
        int c=a&b,num=a^b;
        c<<=1;
        if(c)return getSum(num,c);
        return num;
    }
};