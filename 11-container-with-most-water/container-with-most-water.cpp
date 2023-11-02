class Solution {
public:
    int maxArea(vector<int>& height) {
       int maxarea;
       int area = 1;
       int i=0;
        int j=height.size()-1;
       while(i<=j){
           area = (j-i)* min(height[i], height[j]);
           maxarea = max(maxarea,area);
           if(height[i]<=height[j]){
               i++;
           }
           else{
               j--;
           }
       }

       return maxarea;
    }
};