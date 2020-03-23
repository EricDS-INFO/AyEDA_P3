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

    int get_state();

    int update();
    std::ostream& write(std::ostream& os) const;
};

#endif