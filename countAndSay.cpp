#include <string>
#include <iostream>

class Solution {
public:
    /*
    //Given an integer n, we need to perform "say" n many times
    //A do while loop is used here as the main control method with a integer counter
    */
    std::string countAndSay(int n) {
        std::string Says = "";//Populate a string as empty
        int count = 1;
        //Run the loop
        do{
            Says = this->sayNth(count,Says);
            count ++;
        }while(count <= n);
        return Says;
    }
    /*==========================================================
    // SayNth will determine if we are in the base case or need to do "say"
    // A more dynamic (recursive) approach may be possible to simplify the control structure.
    // If you can think of one, let me know.
    // Inputs:
    // integer i:  the current count
    // string Says:  A string which we should say and count.
    //========================================================= */
    std :: string sayNth(int i, std::string Says){
        if (i==1)
            return "1"; //This is the base case, call only in the first interation.
        else
            return this->say(Says);//Otherwise say and count the string given
    }
    
    /*==========================================================
    //"say" will count the number of each numbers in a string
    // A more dynamic (recursive) approach may be possible to simplify the control structure.
    // If you can think of one, let me know.
    // Inputs:
    // integer i:  the current count
    // string Says:  A string which we should say and count.
    //========================================================= */
    std :: string say(std::string Says){
        int count = 1;
        std:: string sayOut;
        //March through the string
        //Each time the elements changes print the number of times we saw that number
        //Skip the first element and compare the ith to the i+1 st elements.
        for (auto it = Says.begin() + 1 ; it != Says.end(); it++) {
            if( *(it -1) != *(it)){ //If not equal append new counts to the string        
                sayOut.append(std:: to_string(count));
                sayOut.append({*(it-1)});
                count = 1; //Reset the counter
            }
            else
            {
               //Increment our counter and proceed
                count ++;
            }
        }
        //The final element needs appending either way        
        sayOut.append(std:: to_string(count));
        sayOut.append({Says[Says.size()-1] });
        return sayOut;
    }
};

int main(void){
    std::string counter;
    Solution sol;
    counter = sol.countAndSay(5);

    std:: cout << "The returned count and say string is: ";
    for (auto it = counter.begin(); it != counter.end(); it++) {
        std :: cout << *it ;
    }
    return 0;
}