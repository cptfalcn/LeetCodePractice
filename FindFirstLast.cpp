#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;



class Solution {
public:
    int searchleft(vector<int>& nums, int target, int mid){
        //The initial index mid is given to us, perform a binary search using the mid as a upper boundary.
        int lower, center, upper;
        upper = mid; //The initial upper
        lower = 0; //The lowest bound
        center = mid/2;
        bool go = true;
        int count = 0 ;
        do{
            //First guess using half the midline
            cout << "Trying to locate left at index " << center << endl;
            if(nums[center+1]==target&&nums[center]!=target){
                //We stumbled onto the boundary or get caught into a rounding scheme error.
                return center+1;
            }
            else if(nums[center]< target){
                //We jumped too far, set the following:
                lower = center;
                //cout << (upper+lower)/2 << endl;
                center = std::max( 0,( (upper + lower)/2 ) );

            }
            else if(nums[center]==target)
            {
                //Parse a few cases:
                //boundary, thus done
                //Interior, binary search goes down and continue
                if (nums[center-1]==nums[center+1]){
                    //Interior, Reject the upper half
                    upper = center; 
                    center = (upper + lower)/2;
                }
                else{
                    return center;
                }
                count ++;
                if (count > nums.size())
                    go = false;
            }

        }while(go);
        lower = -1;
        return lower;
    }

    int searchright(vector<int>& nums, int target, int mid){
        //The initial index mid is given to us, perform a binary search using the mid as a lower boundary.
        int lower, center, upper;
        upper = nums.size(); //The initial upper
        lower = mid; //The lowest bound
        center = (upper + lower) /2;
        bool go = true;
        int count = 0 ;
        do{
            //First guess using half the midline
            cout << "Trying to locate right at index " << center << endl;
            if(nums[center-1]==target && nums[center]!=target){
                return center -1;
            }
            else if(nums[center] > target){
                //We jumped too far, reject the upper portion
                upper = center;
                center = (upper + lower) /2;
            }
            else if(nums[center]==target)
            {
                //Parse a few cases:
                //boundary, thus done
                //Interior, binary search goes down and continue
                if (nums[center-1]==nums[center+1]){
                    //Interior, Reject the lower half
                    lower = center; 
                    center = (upper + lower)/2;
                }
                else{
                    return center;
                }
                count ++;
                if (count > nums.size())
                    go = false;
               
            }
        }while(go);
        upper= -1;
        return upper;
    }
    
    //Perform a regular binary search until we hit a target.
    //The interval starts at [0, nums.size()], 
    //Iterate through the edges checking neighbors 
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower =0;
        int upper = nums.size();
        int mid = floor((nums.size())/2);
        bool ongoing = true;
        int count = 0; //If we try more than 2*length loops terminate with a failure.
        cout << "The mid point of this array is indexed to: " << mid << endl;
        do{
            if (nums[mid]==target)//We are in the middle of the array, set upper and lower bounds and double search
            {
                cout << "Found a target at index " << mid << endl;
                lower = this->searchleft(nums, target, mid);
                upper = this->searchright(nums, target, mid);
                //cout << lower << " " << upper << endl;
                return {lower, upper};
            }//Else we reject.  Then figure out to look "up" or "down"
            else if(nums[mid]<target)//We are below the target area, extend upward and continue single search.
            {
                lower = mid;
                mid=(upper + lower)/2;
            }
            else if(nums[mid]>target)//We are above the target area, extend downward
            {
                upper = mid;
                mid=(upper + lower)/2;
            }
            count ++;
            if (count > 2*nums.size())
            {
                cout << "Failed to find the target number!!!\n";
                ongoing = false;
            }

        }while(ongoing);
        //If nothing found
        return {-1,-1};
    }

};

int main(void)
{
    vector<int> vec = {0,0,0,0,0,0,1,1,1,2,2,3,3,4};
    vec = {3,3,3,3,3,3,3,3,4,4,4,4,5,7,7,8,8,10};
    vector<int> targetLoc = {-1,-1};
    Solution sol;
    //Run the class function.
    int target = 2;
    //int k=sol.removeDuplicates(vec);
    targetLoc=sol.searchRange(vec, target);
    cout << "We located the boundaries at indices (" << targetLoc[0] << ", " << targetLoc[1] << ").\n";
    
    for(auto & element : vec)
        cout << element << endl;
    //vector<int> expectedNums = {0,1,2,3,4}; // The expected answer with correct length
    //Run the judging function
    // if (k != expectedNums.size()){
    //     cout << "incorrect length\n";
    //     return 1;
    // }
    // for (int i = 0; i < k; i++) 
    //     if( vec[i] != expectedNums[i]){
    //         std::cout << "error in entry " << i << endl;
    //         return 1;
    //     }

    return 0;
}