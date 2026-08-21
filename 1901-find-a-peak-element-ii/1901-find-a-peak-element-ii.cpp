class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int high=mat[0].size()-1;
        int low=0;
        while(low<=high){
            int mid=low+((high-low)/2);
            int max=0;
            for(int i=0;i<mat.size();i++){
                if(mat[i][mid]>mat[max][mid]) max=i;
            }
            int left= (mid-1>=0)? mat[max][mid-1]:-1;
            int right= (mid+1<(mat[0].size()))? mat[max][mid+1]:-1;
            if(mat[max][mid]>left && mat[max][mid]>right) return {max,mid};
            else if(mat[max][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return{-1,-1};
    }
};