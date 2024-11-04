class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int i = 0;
        int j = 31;

        while (i < j)
        {
            uint32_t bit_i = (n >> i) & 1; // Extract the i-th bit
            uint32_t bit_j = (n >> j) & 1; // Extract the j-th bit

             if(bit_i!=bit_j)
             {
                n^=(1<<j);  // toggling the jth bit
                n^=(1<<i);  // toggling the ith bit
             }

            i++;
            j--;
        }
        return n;
    }
};
