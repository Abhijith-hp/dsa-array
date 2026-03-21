class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         int n = points.size();
        if (n <= 2) return n;
        int res = 1;
        for(int i=0;i<n;i++){
            unordered_map<double,int> count;
            double slope;
            for(int j=i+1;j<n;j++){
               if(points[i][0]==points[j][0])
                   slope = numeric_limits<double>::infinity();
                else
                    slope = (double)(points[j][1] - points[i][1]) /
                            (points[j][0] - points[i][0]);
                count[slope]++;
                res = max(res, count[slope] + 1);
            }
        }
    return res;
    }
};