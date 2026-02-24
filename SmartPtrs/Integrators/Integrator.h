#include <math.h>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <iomanip>
#include "Problem.h"
#ifndef integrator_h
#define integrator_h
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
template<class T>
class problem{
    public:
        std::function<T(T,T)> rhs_func;
        virtual T rhs(T data, T time){
            std :: cout <<"running base problem class rhs\n";
            return data;
        };
        virtual T jac(T data, T time){
            std :: cout <<"running base problem class jac\n";
            return data;
        };
        void setFunction(std::function<T(T,T)> input ){
            this->rhs_func = input;
        }
};



/*===============================================
sample problem for f: R -> R, y' = f(x) = x
=>  y = x^2/2 + c 
=================================================*/
class fx_x : public problem<double>{
    public:
        //using problem<double>::problem;
        double rhs(double, double) override;
        double jac(double, double) override;
};


double fx_is_x(double, double);
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
/*==========================================================================
This integrator is templated to accept most data types representing I: R ->R
This format assumes a constant time stepping method.
When you created your derived version, specify the methods used in the name of the derived class
=============================================================================*/
template<typename T>
class integrator{
    public:
        friend class std::shared_ptr<problem<T>>;
        std::shared_ptr<problem<T>> p_ptr; //Look here for the specifics of the integrator rhs/jac
        integrator(std::shared_ptr<problem<T>> p_ptr): p_ptr(p_ptr){
            std :: cout << "We have created an integrator\n";
        };

        void integrate(){
            std :: cout << "Performing integration...\n";
        };
};

/*
This is the basic version of a scalar constant time stepper integrator function that all other methods should derive from.
*/
template <typename T>
class scalarConstStepper : public integrator<T>{
    protected:
        T               step_size;
        T               start_time;
        T               end_time;
        T               init_cond;
        int             steps;
        std::vector<T>  time_series;
        std::vector<T>  times;
    public:
        scalarConstStepper(std::shared_ptr<problem<double>> p_ptr, T step_size, T start_time, T end_time, T init_cond, int steps): 
        integrator<double>(p_ptr), step_size(step_size), start_time(start_time), init_cond(init_cond), steps(steps){
             std :: cout << "We have created an constant time step integrator\n";
        }
        virtual void step(){
        };//Must be overwritten
        virtual void initialize(){};  
        //You want to inherit this, and override the other methods
        void integrate(){
            int step_num =  0 ;
            this->initialize();
            while(step_num < this->steps)
            {
                this->step();
                step_num++;
            }
        }
};








class backwardEuler: public scalarConstStepper<double>{
    public:
        backwardEuler(std::shared_ptr<problem<double>>, double, double, double, double, int);
        void print();
        void set(double, double , double, double);
        void step() override;
        void initialize() override;
}; 







#endif