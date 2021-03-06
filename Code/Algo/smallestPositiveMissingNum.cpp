int findMissing(int arr[], int n) { 
    
   set<int> s;
   int m = 1;
   
   for(int i = 0;i<n;i++)
   {
       if(m < arr[i])
            s.insert(arr[i]);
        else if(m == arr[i])
        {
            m = m+1;
            while(s.count(m))
            {
                s.erase(m);
                m++;
            }
        }
   }
   return m;
   
}

// best soln
// O(n) time and O(1) extra space solution:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> present(n+1, false);
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0 && nums[i] <= n)
                present[nums[i]] = true;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(!present[i])
                return i;
        }
        
        return n+1;
    }
};