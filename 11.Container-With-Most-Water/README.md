If you think you can just check every area with different height like below, your time limit will be exceeded

```cpp
//this one is wrong
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, current=0;
        int i=0, j=0;
        for(i=0; i<height.size()-1; i++){
            for(j=1; j<height.size(); j++){
                current = min(height.at(i),height.at(j))*(j-i);
                if(current>ans){
                    ans = current;
                }
            }
        }
        return ans;
    }
};
```

The main idea of the one below is that we make the first height and the last height as our edges,
which means that the only way that other area and beat this one is one side of the height is taller
than the previous height

### as we shrink edge, the only way that current area can beat the previous one is beacuse now's height is higher

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        //the point is, we don't need to memorize the two height of the final answer
        int i = 0;
        int j = height.size()-1;
        int ans = 0;
        int w_height = 0;
        while(i<j){
            w_height = min(height[i], height[j]);
            if(w_height*(j-i) > ans){
                ans = w_height*(j-i);
            }
            while(height[i] <= w_height && i<j) i++;//when both sides are higher than w_height, we stop and calculate if the height beat edge
            while(height[j] <= w_height && i<j) j--;//when both sides are higher than w_height, we stop and calculate if the height beat edge
        }
        return ans;
    }
};
```