class Solution {

public:

    int trap(vector<int>& height) {

    int n = height.size();

    int total = 0;

    int leftMax[n], rightMax[n];

 

    int maximum = 0;

    leftMax[0] = 0;

    for (int i = 1; i < n; ++i)

    {  

        maximum = max(maximum, height[i-1]);

        leftMax[i] = maximum;

    }

 

    maximum = 0;

    rightMax[n-1] = 0;

    for (int i = n-2; i >= 0; --i)

    {

        maximum = max(maximum, height[i+1]);

        rightMax[i] = maximum;

    }

 

    for(int i = 0; i < n; i++) {

        int waterLevel = min(leftMax[i], rightMax[i]);

        int tappedWater = waterLevel > height[i] ? waterLevel - height[i] : 0;

        total += tappedWater;

    }

 

    return total;

    }

};