#include "cell_t.hpp"


#ifndef CELL_2
#define CELL_2


class cell_2: public cell_t 
{
    
    private:
    int i_, j_;
    
    public:
    cell_2(int i, int j):
    i_(i), 
    j_(j){}

    int get_state();
    
    int update();
    std::ostream& write(std::ostream& os) const;
};

#endif