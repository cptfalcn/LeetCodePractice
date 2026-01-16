#include <iostream>
#define box "\u25A0"
#define path "\u25AA"

//Prone to overflow
int fact(int n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

int Choose(int n, int r){
    return fact(n)/(fact(r)* fact(n -r));
}


//This is the version that is less prone to overflow because addition is used, not mult.
int fastBin(int n, int m){
    int result = 0;
    if( (n==1) or (m == 1) or n ==0 or m ==0 )//Base case
        return 1;
    else 
        return fastBin(m, n -1) + fastBin(m-1, n);//Recursion case
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        return Choose(m+n-2, m-1);
    }
    //Visualizes the maze, uses m and n.
    //Calls the two other draw functions and the macro defined ANSCII codes.
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
    int m = 8;
    int n = 5;
    sol.drawBox(m,n);
    //std:: cout << sol.uniquePaths(m,n)<< " unique traversals paths exist."<<std::endl;
    std:: cout << fastBin(m,n) << " unique traversal paths exist." << std::endl;
    return 0;
}
