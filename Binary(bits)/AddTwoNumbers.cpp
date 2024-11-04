class Solution {
public:
    int getSum(int a, int b) 
    {
        while(b!=0)
        {
            int carry =a&b;   // getting the carry 
            a=a^b;            // adding  without carry (saare bits ko add krle rhe h pehle hi bina irrespective of carry)
            b=carry<<1;       // carry ko add krenge ab (b ke to saare bits add ho jayenge a me first iteration me ..uske baad carry ko b me daalke fir add krte rhenge tbtak jabtak  hme carry milta rhega)
        }
        return a;
        
    }
};