class Solution {
public:
   bool check(int mid, unordered_map<int,vector<vector<int>>>&adj,long long k,int n){
    vector<long long>result(n,LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>> pq;
    result[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(cost>k) continue;
        if(result[node]<cost)continue;
        if(node == n - 1 && cost <= k) return true;
        for(auto &ngbor:adj[node]){
            int  nextNode = ngbor[0];
            int nextCost = ngbor[1];
            if(nextCost<mid) continue;
            if(nextCost+cost<result[nextNode]){
                result[nextNode] = nextCost+cost;
                pq.push({nextCost+cost,nextNode});
            }
        }
    }
    return false;
   }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int left = INT_MAX;
        int right = INT_MIN;
        unordered_map<int,vector<vector<int>>>adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,cost});
            left = min(left,cost);
            right = max(right,cost);
        }
        int result = -1;
        while(left<=right){
           int mid = left + (right-left)/2;
           if(check(mid,adj,k,n)){
            result  = mid;
            left = mid+1;
           }else right = mid-1;
        }
    return result;
    }
};