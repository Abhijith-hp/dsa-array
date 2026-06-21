class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        int N = restrictions.size();


        for(int i=1;i<N;i++){
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1],restrictions[i-1][1]+dist);
        }

         for(int i=N-2;i>=0;i--){
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],restrictions[i+1][1]+dist);
        }

        int result = INT_MIN;
        for(int i=1;i<=N-1;i++){
            int leftHeight = restrictions[i-1][1];
            int currentHeight = restrictions[i][1];
            int leftPos = restrictions[i-1][0];
            int currentPos = restrictions[i][0];

           int d = currentPos - leftPos;
            int htDiff = abs(currentHeight - leftHeight);

            int peak =max(leftHeight,currentHeight)+ (d - htDiff)/2;
            result = max(result,peak);
        }
    return result;
    }
};