class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=0;
        vector<pair<int,int>> arr;
        while(j<n){
            if(arr.size()<2){
                if(arr.size()==1 && arr[0].first==nums[j]){
                   arr[0].second=j;
                   j++;
                   ans=max(ans,j-i);
                   continue;
                }
                arr.push_back({nums[j],j});
                j++;
                ans=max(ans,j-i);
                continue;
                }
            else{
                if(nums[j]==arr[0].first){
                    arr[0].second=j;
                }
                else if(nums[j]==arr[1].first){
                    arr[1].second=j;
                }
                else{
                    if(arr[0].second>arr[1].second){
                        ans=max(ans,(j-i));
                        i=arr[1].second+1;
                        arr[1]={nums[j],j};
                    }
                    else{
                        ans=max(ans,(j-i));
                        i=arr[0].second+1;
                        arr[0]={nums[j],j};
                    }
                }
                ans=max(ans,(j-i+1));
                j++;
            }
        }
        return ans;
    }
};