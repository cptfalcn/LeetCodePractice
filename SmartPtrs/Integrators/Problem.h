#include <math.h>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <iomanip>
#ifndef problem_h
#define problem_h
/*===================================================================================
                         888      888                                      888                            
                         888      888                                      888                            
                         888      888                                      888                            
88888b.  888d888 .d88b.  88888b.  888  .d88b.  88888b.d88b.        .d8888b 888  8888b.  .d8888b  .d8888b  
888 "88b 888P"  d88""88b 888 "88b 888 d8P  Y8b 888 "888 "88b      d88P"    888     "88b 88K      88K      
888  888 888    888  888 888  888 888 88888888 888  888  888      888      888 .d888888 "Y8888b. "Y8888b. 
888 d88P 888    Y88..88P 888 d88P 888 Y8b.     888  888  888      Y88b.    888 888  888      X88      X88 
88888P"  888     "Y88P"  88888P"  888  "Y8888  888  888  888       "Y8888P 888 "Y888888  88888P'  88888P' 
888                                                                                                       
888                                                                                                       
888                                                                                                       
====================================================================================*/
/*============================================================
The problem class is presented as a virtual templated base class; so 
you will need to make your own derived class, inheriting from the base class.
I suggest that your inhereting version be exactingly specific and not templated.
All problems are of the form y' = rhs(y,t).
Higher order methods may need the Jacobian.
====================================================================*/
// template<class T>
// class problem{
//     public:
//         std::function<T(T,T)> rhs_func;
//         virtual T rhs(T data, T time){
//             std :: cout <<"running base problem class rhs\n";
//             return data;
//         };
//         virtual T jac(T data, T time){
//             std :: cout <<"running base problem class jac\n";
//             return data;
//         };
//         void setFunction(std::function<T(T,T)> input ){
//             this->rhs_func = input;
//         }
// };


// double fx_is_x(double  , double );


// double fx_x :: rhs(double , double ); 
// double fx_x :: jac(double , double ); 

#endif