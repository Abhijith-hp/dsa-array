class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int validLeftPoints = 0;
        int cummalativeSum = 0;
        unordered_map<int,int>mpp;
        mpp[cummalativeSum] =1;
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                validLeftPoints+=mpp[cummalativeSum];
                cummalativeSum++;
            }else{
                cummalativeSum--;
                validLeftPoints-=mpp[cummalativeSum];
            }
        result+=validLeftPoints;
        mpp[cummalativeSum]++;
        }
    return result;   
    }
};