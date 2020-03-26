#include "cell_t.hpp"

#ifndef CELL_1
#define CELL_1

class cell_1: public cell_t 
{
    private:
    int i_, j_;
    
    public:
    cell_1(int i, int j):
    i_(i), 
    j_(j){}

    ~cell_1(){}

    int get_state() const;

    int update_state();
    std::ostream& write(std::ostream& os);
    friend std::ostream& operator<< (std::ostream& os, cell_1& cell);

};

#endif