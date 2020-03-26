#include "cell_t.hpp"

#ifndef CELL_X
#define CELL_X


class cell_x: public cell_t 
{
    
    private:
    int i_, j_;
    
    public:
    cell_x(int i, int j):
    i_(i), 
    j_(j){}

    ~cell_x(){}

    int get_state(void) const;

    int update_state(void);
    std::ostream& write(std::ostream& os);
    friend std::ostream& operator<< (std::ostream& os, cell_x& cell);
};

#endif