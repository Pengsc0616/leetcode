class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //pwwwkew
        unordered_map<char,int> maps;
        int ans=0, temp=0;
        for(int i=0; i<s.size(); i++){
            maps.clear();
            temp=0;
            for(int j=i; j<s.size(); j++){
                maps[s[j]]++;
                //temp++;
                //ans=max(ans,temp);
                if(maps[s[j]]>1){
                    //ans=max(ans,temp);
                    break;
                }
                temp++;
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
