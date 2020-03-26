#include "cell_t.hpp"

#ifndef CELL_3
#define CELL_3


class cell_3: public cell_t 
{
    
    private:
    int i_, j_;
    
    public:
    cell_3(int i, int j):
    i_(i), 
    j_(j){}

    ~cell_3(){}

    int get_state() const;

    int update_state();
    std::ostream& write(std::ostream& os);
    friend std::ostream& operator<< (std::ostream& os, cell_3& cell);
};

#endif