#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <functional>
#include <iomanip>
#include "Integrator.h"

using namespace std;
int main(int argc, char** argv){
    std:: cout << "hello world\n";
    std::shared_ptr<fx_x> pb_ptr = make_shared<fx_x>();
   
    auto i_ptr = make_shared<integrator<double>>(pb_ptr);
   
    //testing the derived constant stepper class.
    auto test_ptr = make_shared<backwardEuler>(pb_ptr, .1, 0.0, 1.0, 0.0, 10);
    test_ptr->integrate();
    test_ptr->print();

    return 0;
}