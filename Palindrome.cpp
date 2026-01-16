#include <iostream>
#include <string>

int main(){
    std::string number;
    std::cout << "Please enter a number, we will check if it is a palindrome: " << std::endl;
    std::cin >> number;
    std::cout << "You entered the number " << number << std::endl;
    int len = number.size();
    std::cout << "The middle number is: " << number[len/2] << std::endl;
    std :: cout << "The number of characters is : " << len << std:: endl;
    for(int i = 0; i < len/2; i++)
        if(number[i]!=number[len-1 -i]){
            std:: cout << "This number is not a palindrome!" <<std::endl;
            return 0;
        }
    std :: cout << "This number is a palindrome!" << std :: endl;
    return 0;
}