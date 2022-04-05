class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right, water = 0, len(height) - 1, 0
        
        while left < right :
            h = min(height[left], height[right])
            water = max(water, h * (right - left))
            
            while ((left < right) and height[left] <= h) :
                left += 1
            
            while ((left < right) and height[right] <= h) :
                right -= 1
                
        return water