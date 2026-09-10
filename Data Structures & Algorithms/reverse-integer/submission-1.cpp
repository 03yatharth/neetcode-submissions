class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        long long X = x;
        if(X<0){
            X=-X;
            sign = -1;
        }
        long long num=0;
        while(X){
            num*=10;
            num += X%10;
            X/=10;
        }
        num*=sign;
        if(num>INT_MAX)return 0;
        if(num<INT_MIN)return 0;
        return num;
    }
};