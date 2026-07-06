class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto lamda = [](vector<int>&v1,vector<int>&v2){
            if(v1[0]==v2[0]) return v1[1]>v2[1];
            return v1[0] < v2[0];

        };
        sort(intervals.begin(),intervals.end(),lamda);
        int last = intervals[0][1];
        int count = 1;
        for(int i=1;i<intervals.size();i++){
            if(last>=intervals[i][1]) continue;
            last = intervals[i][1];
            count++;
        }
    return count;
    }
};