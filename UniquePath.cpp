#include <iostream>
#define box "\u25A0"
#define path "\u25AA"


class Solution {
public:
    /*
        The unique path problem (Leetcode problem 62) is equivalent to finding 
        the binomial coefficients of m choose n.  Brute forcing the formula
        results in integer overflows due to repeated multiplication via the
        factorial function.  To mitigate overflow recursion and pascal's 
        triangle is used to add integers instead of multiplying.
    */
    int uniquePaths(int m, int n) {
        return fastBin(m,n);
    }

    /*====================================
    //Fast Binomial Coefficients
    //Using recursion the binomial coefficients for m choose n are calculated
    //Inputs:  m, n.
    //Output:  m choose n
    //======================================
    */

    int fastBin(int n, int m){
        int result = 0;
        if( (n==1) or (m == 1) or n ==0 or m ==0 )//Base case
            return 1;
        else 
        return fastBin(m, n -1) + fastBin(m-1, n);//Recursion case
    }
    /*===================================================
    //This is a purely ornamental addition to visualize the maze onto the console,
    //and is not part of the original problem.
    //===================================================
    */
    void drawBox(int m, int n){
        this->drawTopBot(m);
        for (int i = 0; i < n; i++)
            this->drawSide(n,m);
        this->drawTopBot(m);

    }
    void drawTopBot(int m){
        for (int i = 0 ; i < m+2; i++)
            std:: cout << box ;
        std:: cout << std::endl;
    }
    void drawSide(int n, int m ){
        std :: cout << box;
        for (int i = 0 ; i < m; i++)
            std:: cout << path ;
        std :: cout << box  << std::endl;
    }
};

int main(void){
    Solution sol;
    int m = 3;
    int n = 7;
    sol.drawBox(m,n);
    std:: cout << sol.fastBin(m,n) << " unique traversal paths exist." << std::endl;
    return 0;
}
