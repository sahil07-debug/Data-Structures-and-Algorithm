class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 and divisor == -1) return 2147483647;
        int neg=1;
        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0)) neg=-1;
         unsigned int x = dividend < 0 ? -(unsigned int)dividend : dividend;
        unsigned int y = divisor < 0 ? -(unsigned int)divisor : divisor;
        if(x<y) return 0;
        unsigned int count=0;
        while(x>=y){
           unsigned int temp=y;
           unsigned int mul=1;
            while((x>>1)>=temp){
                temp<<=1;
                mul<<=1;
            }
            count+=mul;
            x=x-temp;      
        }
         if(neg==-1) return -count;
         return count;  
    }
};