
#include "../include/cell_t.hpp"

#include "../include/cell_1.hpp"
#include "../include/cell_2.hpp"
#include "../include/cell_3.hpp"

#include "../include/board_t.hpp"

#include <iostream>


int cell_1::update_state() 
{
    if (alive_neighbours_!= 2 &&
        alive_neighbours_!= 3 )
        return 0;
    else
        return 1;
    
}


int cell_1::get_state(void) const 
{
    return 1;
}

std::ostream& cell_1::write(std::ostream& os)
{
    os << "1";
    return os;
} 

std::ostream& operator<<(std::ostream& os, cell_1& cell)
{
    cell.write(os);

    return os;
}

