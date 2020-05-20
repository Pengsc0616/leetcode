class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //43 24 2134 2142 214   //4376 //[2,3]
        unordered_map<int, int> spider; // spider[ num[i] ] = i
        vector<int> ansVec;
        for (int i = 0; i < nums.size(); i++)
        {
            int secondWord = target - nums[i];
            if (spider.find(secondWord) != spider.end())
            {
                //we know that secondWord's position must smaller than i;
                ansVec.push_back(spider[secondWord]);
                ansVec.push_back(i);
                return ansVec;
            }
            spider[nums[i]] = i; //secondWord is not actually a word in "nums"
        }
        return ansVec;
    }
};