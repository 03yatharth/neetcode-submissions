class Solution {
public:
    int reverse(int x) {
        long long X=x,num=0;
        while(X){
            num = num*10 + X%10;
            X/=10;
        }
        if(num>INT_MAX)return 0;
        if(num<INT_MIN)return 0;
        return num;
    }
};
