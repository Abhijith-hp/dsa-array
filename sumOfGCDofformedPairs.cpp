class Solution {
public:
    long long gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<long long>preFixSums;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            preFixSums.push_back(gcd(maxi,nums[i]));
        }
        sort(preFixSums.begin(),preFixSums.end());
        int i=0,j=preFixSums.size()-1;
        long long ans = 0;
        while(i<j){
           ans+=gcd(preFixSums[i],preFixSums[j]);
           i++;
           j--;
        }
    return ans;
    }
};