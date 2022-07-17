class Solution {
public:
    /*
     * the left and right pointer works as a double edge sword
     * let's say : left value is L and right is R
     * if the height of curr block is H
     * For ex. 
     * if L > R : 
        - we can add [max left value till yet] - [H] to our result
        - Why? 
        - Because we know this is the max left height
          If the right height was smaller, this cond'n will never run
     */
    
    int trap(vector<int>& height) {
        int sum = 0, maxleft = 0, maxright = 0, l = 0, r = size(height) - 1;
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= maxleft) maxleft = height[l];
                else sum += maxleft - height[l];
                l++;
            } else {
                if (height[r] >= maxright) maxright = height[r];
                else sum += maxright - height[r];
                r--; 
            }
        }
        
        return sum;
    }
};