#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> & nums) {
        int j =1;  //number of unique elements, which is ideally the index we need to place new elements into!  Nice. 
        for(int i = 1; i < nums.size(); i ++) 
        {
            if(nums[i-1]!=nums[i])//Our numbers are not equal, this element needs to be shifted to the end of the unique queue
            {
                nums[j]=nums[i];
                j++; //Now, the back of the line gets shifted up an index
            }
        }
        cout << "We have this many unique elements: " << j << endl;
        return j;
    }

};

int main(void)
{
    vector<int> vec = {0,0,0,0,0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    //Run the class function.
    int k=sol.removeDuplicates(vec);

    for(auto & element : vec)
        cout << element << endl;
    vector<int> expectedNums = {0,1,2,3,4}; // The expected answer with correct length
    //Run the judging function
    if (k != expectedNums.size()){
        cout << "incorrect length\n";
        return 1;
    }
    for (int i = 0; i < k; i++) 
        if( vec[i] != expectedNums[i]){
            std::cout << "error in entry " << i << endl;
            return 1;
        }

    return 0;
}