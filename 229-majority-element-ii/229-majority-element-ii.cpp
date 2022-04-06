class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Approach #1
        // brute force way 
        // make a map, count the numbers with occ > n/3 
        // O(N) time O(N) space
        
        // Approach #2
        // use counter method with a lot more variables
        // i think the counter method is also called boyer moore 
        // algorithm
        
        int N = nums.size();
        
        int count1, count2, score, num1, num2;
        count1 = count2 = score = 0, num1 = num2 = INT_MIN;
        
        
        for (int i = 0; i < N; i++) {
            if (num1 == nums[i]) {
                count1++;
            } 
            
            else if (num2 == nums[i]) {
                count2++;
            } 
            
            else if (!count1) {
                num1 = nums[i], count1 = 1;
            }
            
            else if (!count2) {
                num2 = nums[i], count2 = 1;  
            }
            
            else {
                count1--, count2--;
            }
        }
        
        vector<int> ans;
        count1 = count2 = 0;
        
        for (int i = 0; i < N; i++) if (nums[i] == num1) count1++;
        for (int i = 0; i < N; i++) if (nums[i] == num2) count2++;
        
        if (count1 > (N / 3)) ans.push_back(num1);
        if (count2 > (N / 3)) ans.push_back(num2);
        
        return ans;
    }
};