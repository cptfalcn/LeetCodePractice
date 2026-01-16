#include <iostream>
#include <string>


class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        bool newLetter=false;
        bool isPanagram=false;
        int letterCnt=0;
        for (int i=0; i < sentence.size(); i++ ){//Loop over the sentence
            newLetter = true;
            for( int j = 0; j < i; j++){
                if (sentence[i]==sentence[j]){
                    newLetter = false;
                }

            }
            if(newLetter){
                letterCnt ++;
            }
        }
        if(letterCnt==26)
            isPanagram=true;
        return isPanagram;
    }
};


int main(void)
{
    Solution sol;
    std::string sentence1 = "howvexinglyquickdaftzebrasjump";
    std::string sentence2 = "packmyboxwithfivedozenliquorjugs";
    if(sol.checkIfPangram(sentence2))
        std::cout << "this is a panagram\n";
    else
        std::cout << "this is NOT a panagram\n";
    return 0;
}