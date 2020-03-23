#include <iostream>
#include <cstdio>

class cell_t{
    public: 
    virtual int get_state() { return 0;} 
};

class cell_1: public  cell_t{
    public: 
    int get_state() { return 1;} 
};



int main (){

    cell_t A;
    cell_1 B;

    std::cout << "type: " << typeid(A).name() << std::endl;
    std::string name1 = typeid(A).name();
    std::string name2 = typeid(B).name();
    
    std::cout << "type: " << name1[name1.length() - 1 ] << std::endl;
    std::cout << "type: " << name2[name2.length() - 1 ] << std::endl;

    std::cout << A.get_state() << "\n";
    std::cout << B.get_state() << "\n";

    return 0;
}