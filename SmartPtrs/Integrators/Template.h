#ifndef template_h
#define template_h
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
        virtual T rhs(T data, T time)=0;
        virtual T jac(T data, T time)=0;
        // void setFunction(std::function<T(T,T)> input ){
        //     this->rhs_func = input;
        // }
};


/*==========================================================================
This integrator is templated to accept most data types representing I: R ->R
This format assumes a constant time stepping method.
Both the variable and constant time stepper versions derive from this.
In your derived version, specify the methods used in the name of the derived class
=============================================================================*/
/*=============================================================================
the problem class is a public interface for the integrator problem:
that is an integrator "has-a" problem it is trying to solve.
This is a "Friend" of the integrator, because the interface needs access to the
data the integrator contains.
===============================================================================*/
template<typename T>
class integrator{
    public:
        friend class std::shared_ptr<problem<T>>;
        std::shared_ptr<problem<T>> p_ptr; //Look here for the specifics of the integrator rhs/jac
        integrator(const std::shared_ptr<problem<T>> p_ptr): p_ptr(p_ptr){
            std :: cout << "We have created an integrator\n";
        };

        void integrate(){
            std :: cout << "Performing integration...\n";
        };
};

/*===============================================
This is the basic version of scalar, constant-time-stepping integrator.
Derive all methods of this type from this class.
=================================================*/
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




#endif