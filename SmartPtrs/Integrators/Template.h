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
        // //virtual void setFunction(std::function<T(T,T)> input)=0;
        // void setFunction(std::function<T(T,T)> input ){
        //     this->rhs_func = input;
        // }
};


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



#endif