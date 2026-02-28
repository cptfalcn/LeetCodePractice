#include <math.h>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <iomanip>
#include "Template.h"
#ifndef integrator_h
#define integrator_h

/*==================================================================================
d8b          888                                     888                             
Y8P          888                                     888                             
             888                                     888                             
888 88888b.  888888 .d88b.   .d88b.  888d888 8888b.  888888 .d88b.  888d888 .d8888b  
888 888 "88b 888   d8P  Y8b d88P"88b 888P"      "88b 888   d88""88b 888P"   88K      
888 888  888 888   88888888 888  888 888    .d888888 888   888  888 888     "Y8888b. 
888 888  888 Y88b. Y8b.     Y88b 888 888    888  888 Y88b. Y88..88P 888          X88 
888 888  888  "Y888 "Y8888   "Y88888 888    "Y888888  "Y888 "Y88P"  888      88888P' 
                                 888                                                 
                            Y8b d88P                                                 
                             "Y88P"                                                  
===================================================================================*/

class backwardEuler final : public scalarConstStepper<double>{
    public:
        backwardEuler(std::shared_ptr<problem<double>>, double, double, double, double, int);
        void print(); //New
        void set(const double, const double , const double, const double);//New
        void step() override;
        void initialize() override;
}; 







#endif