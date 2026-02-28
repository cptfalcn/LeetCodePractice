#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <iomanip>
#include "Integrator.h"
#include "Problem.h"

/*====================================================================================
         d8b                   .d888   .d88          88b.                                  
         88P                  d88P"   d88P"          "Y88b                                 
         8P                   888    d88P              Y88b                                
888  888 "        888888      888888 888    888  888    888      888888      888  888      
888  888                      888    888    `Y8bd8P'    888                  `Y8bd8P'      
888  888          888888      888    Y88b     X88K     d88P      888888        X88K        
Y88b 888                      888     Y88b. .d8""8b. .d88P                   .d8""8b.      
 "Y88888                      888      "Y88 888  888 88P"                    888  888      
     888                                                                                   
Y8b d88P                                                                                   
 "Y88P"                                                                                    
======================================================================================*/

/*===============================================
sample problem for f: R -> R, y' = f(x) = x
=>  y = x^2/2 + c 
=================================================*/

double fx_x :: rhs(const double input, const double time ) {
    return time;
}
double fx_x :: jac(const double input, const double time) {
    return 1.0;
}

/*===============================================
sample problem for f: R -> R, y' = f(x) = x^2
=>  y = x^3/3 + c 
=================================================*/
double fx_x2 :: rhs(const double input, const double time ) {
    return time*time;
}
double fx_x2 :: jac(const double input, const double time) {
    return 2*time;
 }



 double fx_sinx :: rhs(const double input, const double time ) {
    return sin(time);
}
double fx_sinx :: jac(const double input, const double time) {
    return cos(time);
 }