class Solution {
public:
    int daystaken(vector<int>weights,int cap){
        int n=weights.size();
         int days=1;
         int load=0;
         for(int i=0;i<n;i++){
            if(load+weights[i]>cap){
                days++;
                load=weights[i];
            }else{
                load+=weights[i];
            }
         }
         return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
          int low=*max_element(weights.begin(),weights.end());
          int high = accumulate(weights.begin(), weights.end(), 0);
                while(low<=high){
                      int mid=low+(high-low)/2;
                      if(daystaken(weights,mid)<=days){
                           high=mid-1;
                      }else{
                        low=mid+1;
                      }
                }
                return low;
    }
};