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