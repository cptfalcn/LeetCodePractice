#include <string>
#include <iostream>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string Says = "";
        for( int i = 0; i < n; i ++){
            Says = this->sayNth(n,Says);
        }
        return Says;
    }

    std :: string sayNth(int i, std::string Says){
        if (i==1)
            return "1";
        else
            return this->say(Says);
    }
    
    std :: string say(std::string Says){
        int count = 1;
        std:: string sayOut;
        //March through the string
        //Each time the elements changes print the number of times we saw that number
        std:: cout << Says.length();
        //Skip the first element and compare the ith to the i+1 st elements.
        for (auto it = Says.begin() + 1 ; it != Says.end(); it++) {
            if( *(it -1) != *(it)){
                std::cout << "elements not equal\n";        
                sayOut.append(std:: to_string(count));
                sayOut.append({*(it-1)});
                count = 1;
            }
            else
            {
                std::cout << "elements ARE equal\n";
                count ++;
            }
            
        }        
        sayOut.append(std:: to_string(count));
        sayOut.append({Says[Says.size()-1] });
        return sayOut;
    }
};

int main(void){
    std::string counter;
    Solution sol;
    std:: cout <<"hello world\n";
    counter = sol.say("1122");
    counter = sol.say("21");
    for (auto it = counter.begin(); it != counter.end(); it++) {
        std :: cout << *it ;
    }
    return 0;
}