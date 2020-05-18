class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[2000];
        ugly[0]=1;
        //ix represent which location in ugly-array do i want to multiply with x
        int i2, i3, i5;
        i2=i3=i5=0;
        int nextprime2 = ugly[i2]*2;
        int nextprime3 = ugly[i3]*3;
        int nextprime5 = ugly[i5]*5;
        for(int a=1; a< n ; a++){
            ugly[a] = min(nextprime2, min(nextprime3, nextprime5));
            if(ugly[a]==nextprime2){
                i2++;
                nextprime2 = ugly[i2]*2;
            }
            if(ugly[a]==nextprime3){
                i3++;
                nextprime3 = ugly[i3]*3;
            }
            if(ugly[a]==nextprime5){
                i5++;
                nextprime5 = ugly[i5]*5;
            }
        }
        return ugly[n-1];
    }

};
