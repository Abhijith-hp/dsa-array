class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

       
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

       
        if (ind == -1) {
            reverseArray(nums, 0, n - 1); 
            return;
        }

       
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[ind], nums[i]);
                break;
            }
        }

        
        reverseArray(nums, ind + 1, n - 1); 
    }
};