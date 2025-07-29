class Solution {
public:
   void moveZeroes(std::vector<int>& nums) {
   int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i]; 
                if (i != pos) {
                    nums[i] = 0; 
                }
                pos++;  
            }
        } 
    }

};