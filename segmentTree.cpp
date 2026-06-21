class NumArray {
public:
   vector<int> nums;
   vector<int>segementTree;
   int n;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        segementTree.resize(4*n);
        build(0,0,n-1);
    }
    void build(int i,int left,int right){
        if(left==right){
            segementTree[i] = nums[left];
            return;
        }
        int mid = left + (right-left)/2;

        build(2*i+1,left,mid);
        build(2*i+2,mid+1,right);
        segementTree[i] = segementTree[2*i+1] + segementTree[2*i+2];
    }
    void updateQuery(int index,int val,int left,int right,int i){
        if(left==right){
            nums[index] = val;
            segementTree[i] = val;
            return;
        }
         int mid = left + (right-left)/2;
        if(index<=mid) updateQuery(index,val,left,mid,2*i+1);
        else if (index>mid) updateQuery(index,val,mid+1,right,2*i+2);
        segementTree[i] =  segementTree[2*i+1] +  segementTree[2*i+2];

    }
    int query(int start,int end,int left,int right,int i){
        if(right<start || left>end) return 0;
        if(start<=left && right<=end) return segementTree[i];
         int mid = left + (right-left)/2;
        return query(start,end,left,mid,2*i+1) +  query(start,end,mid+1,right,2*i+2);
    }
    
    void update(int index, int val) {
        updateQuery(index,val,0,n-1,0);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,n-1,0);
    }
};
