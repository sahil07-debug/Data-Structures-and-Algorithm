class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& arr) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n==0){
            ans.push_back(arr);
            return ans;
        }
        int i=0;
        while(i<n && nums[i][1]<arr[0]){
            ans.push_back(nums[i]);
            i++;
        }
        if(i==n){
            nums.push_back(arr);
            return nums;
        }
        vector<int>a;
        if(nums[i][0]<arr[0])a.push_back(nums[i][0]);
        else a.push_back(arr[0]);
        while(i<n && nums[i][0]<=arr[1]){
            i++;
        }
        if(i==0) a.push_back(arr[1]);
        else if(nums[i-1][1]>arr[1])a.push_back(nums[i-1][1]);
        else a.push_back(arr[1]);
        ans.push_back(a);
        while(i<n){
           ans.push_back(nums[i]);
           i++;
        }
        return ans;
    }
};