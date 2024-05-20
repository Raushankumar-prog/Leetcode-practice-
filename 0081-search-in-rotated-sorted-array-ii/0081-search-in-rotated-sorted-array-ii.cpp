class Solution {
public:
    bool search(vector<int>& nums, int target) {
          ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)return true;
            if(nums[low]==nums[mid] & nums[high]==nums[mid]){
                   low=low+1;
                   high=high-1;
                   continue;
            }
            if(nums[mid]<=nums[high]){
                  if(nums[mid]<=target & target<=nums[high] ){
                    low=mid+1;
                  }else{
                    high=mid-1;
                  }
            }
            else{
                   if(nums[mid]>=target & target>=nums[low] ){
                    high=mid-1;
                  }else{
                    low=mid+1;
                  }
            }
        }
        return false;
    }
};