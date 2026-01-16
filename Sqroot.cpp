#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int upper, lower, mid;
        upper = x;
        lower = x/2;
        return x;
    }
};

int main(){
    Solution sol;
    int num = 64;
    int sqrt = sol.mySqrt(num);
    std :: cout <<"The estimated square root of " << num << " is :" << sqrt;
    return 0;
}