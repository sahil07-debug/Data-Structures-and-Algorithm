class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back({});
        int n=nums.size();
        if(n==1){
            ans.push_back(nums);
            return ans;
        }
        else if(n>1){
            int u=1<<n;
            for (int i=1;i<u;i++){
                int j=i;
                int k=0;
                vector<int>p;
                while(j!=0){
                    if(j&1) p.push_back(nums[k]);
                    k++;
                    j=j>>1;
                }
                ans.push_back(p);
            }
            
        }
        return ans;
        
    }
};