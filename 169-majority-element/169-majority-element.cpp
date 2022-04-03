class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int number = nums[0], counter = 1, N = nums.size();
        bool change_value = false;
        
        for (int i = 1; i < N; i++) {
            if (change_value) {
                number = nums[i];
                change_value = false;
            }
            
            if (nums[i] == number) 
                counter++;
            else
                counter--;
            if (!counter)
                change_value = true;
        }
        
        return number;
    }
};