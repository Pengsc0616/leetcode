If you think you can just check every area with different height like below, your time limit will be exceeded

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0, current=0;
        int i=0, j=0;
        for(i=0; i<height.size()-1; i++){
            for(j=1; j<height.size(); j++){
                current = min(height.at(i),height.at(j))*(j-i);
                //cout << min(height.at(i),height.at(j)) << " " << j-i << endl;
                if(current>ans){
                    ans = current;
                }
            }
            //cout << max(height.at(i),height.at(j)) << " " << j-i;
            //cout << j-i;
        }
        return ans;
    }
};
```