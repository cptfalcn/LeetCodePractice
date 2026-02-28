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
#include "Problem.h"
#include "Template.h"

using namespace std;
int main(int argc, char** argv){
    //std:: cout << "hello world\n";
    const double pi = M_PI;
    std::shared_ptr<fx_x> pb_ptr = make_shared<fx_x>();
    std::shared_ptr<fx_x2> pb_ptr2 = make_shared<fx_x2>();
    std::shared_ptr<fx_sinx> pb_ptr3 = make_shared<fx_sinx>();
   
    auto i_ptr = make_shared<integrator<double>>(pb_ptr);
   
    //testing the derived constant stepper class.
    auto test_ptr = make_shared<backwardEuler>(pb_ptr, 1e-1, 0.0, 1.0, 0.0, 1e1);
    test_ptr->integrate();
    test_ptr->print();

    return 0;
}