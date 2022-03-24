#include "Validator.hpp"
#include "stdc++.h"

using namespace std;

class Validator
{
public:
    
    //the program exits if arguments are incorrect
    bool validate_args(int args)
    {
        if(args==2)
            return true;
        else
        {
            cout<<"Incorrect arguments!"<<"Should Include path_to_file"<<endl;
            exit(-1);
        }
            
    }
};
