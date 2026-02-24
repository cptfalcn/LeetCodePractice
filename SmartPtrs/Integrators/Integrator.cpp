#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <iomanip>
#include "Integrator.h"

/*=====================================
8888888888         888                  
888                888                  
888                888                  
8888888   888  888 888  .d88b.  888d888 
888       888  888 888 d8P  Y8b 888P"   
888       888  888 888 88888888 888     
888       Y88b 888 888 Y8b.     888     
8888888888 "Y88888 888  "Y8888  888     
=======================================*/ 
backwardEuler::backwardEuler(std::shared_ptr<problem<double>> p_ptr, double step_size, double start_time, double end_time, double init_cond, int steps):
scalarConstStepper(p_ptr, step_size, start_time, end_time, init_cond, steps){}   


void backwardEuler::initialize(){
    if(!this->time_series.empty()){
            std:: cout << "emptying vectors!\n";
            this->time_series.clear();
            this->times.clear();
        }
    this->time_series.push_back(this->init_cond);
    this->times.push_back(this->start_time);
}



void backwardEuler::set(double step, double start, double end, double initial){
    this->step_size= step;
    this->start_time= start;
    this->end_time = end;
    this->init_cond=initial;
}




void backwardEuler::step(){
    //y(n+1)= y(n) + h * rhs(y(n), t(n))
    //Increment the step to the back of the vector
    this->time_series.push_back(
        //y(n)
        this->time_series.back()
        //  h                   rhs         (              y(n),                   t(n)             )
        + this->step_size * this->p_ptr->rhs(   this->time_series.back(),   this->times.back())     );
    //Increment the time to the back of the vector
    times.push_back(this->times.back()+ this->step_size);
}

void backwardEuler::print(){
    for( auto x = this->time_series.begin(), y=this->times.begin(); 
        x!=this->time_series.end() && y!=this->times.end();
        ++x, ++y){
        std :: cout << *y << "\t\t" << *x << std:: endl;
    }
}

                                        


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
double fx_is_x(double data , double time){
    return time;
}



double fx_x :: rhs(double input, double time ) {
    return time;
}
double fx_x :: jac(double input, double time) {
    return 1.0;
}