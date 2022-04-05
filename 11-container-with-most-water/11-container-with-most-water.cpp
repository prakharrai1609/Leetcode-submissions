class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
            Logic : we are trying to find the max water right?
            The max water will either have max width or max height or both
            
            Solution :
            - we start with the max width i.e. the first and last height
            - now to find more water than max width the height should be maximum
            - we move the left and right pointers to the next max height
            - we keep doing this until every max height is exhausted
        */
        
        int N = height.size(), water = 0;
        int left = 0, right = N - 1;
        
        while (left < right) {
            int h = min(height[left], height[right]);
            water = max(water, (right - left) * h);
            
            while (height[left] <= h and left < right)
                left++;
            
            while (height[right] <= h and left < right)
                right--;
        }
        
        return water;
    }
};