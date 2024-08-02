class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 1. Make a unsigned integer that can have 32 bits
        uint32_t reversed = 0;

        // 2. 32 baar chalega loop because it is mentioned that unsigned 32 bit int
        for(int i=0 ; i<32 ; i++){
            // 3. Make one space for next bit, M.S.B gots fixed in first iteration 
            reversed = reversed<<1;

            // 4. Now add that bit into this reversed comaping to n
            if(n&1){
                // 5. if the bit is 1 , set 1 in reversed as well
                reversed = reversed | 1;
            }

            // 6. Shift the n one bit right so that the L.S.B can be compared again
            n = n >> 1;
        }
        // 7. We are going from 0 -> number in reversed and we are extracting last digit of n and placing it into starting didgits of reversed.
        return reversed;
    }
};