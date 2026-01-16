#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++ )
            for(int j = i + 1; j <nums.size(); j++ )
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
    //If no complement we return the empty vector            
    return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 5, 3, 12, -8, 13, 71};
    int target = -5;
    vector<int> indices = solution.twoSum(nums, target);
    cout << "the solution is: ";
    for (auto i : indices){
        cout << i << " ";
    }
    return 0;
}