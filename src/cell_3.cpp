
#include "../include/cell_t.hpp"

#include "../include/cell_1.hpp"
#include "../include/cell_2.hpp"
#include "../include/cell_3.hpp"

#include "../include/board_t.hpp"

#include <iostream>


int cell_3::update_state() 
{
    if (alive_neighbours_!= 5 &&
        alive_neighbours_!= 1 )
        return 0;
    else
        return 3;
    
}


int cell_3::get_state(void) const 
{
    return 3;
}

std::ostream& cell_3::write(std::ostream& os)
{
    os << "3";
    return os;
} 

std::ostream& operator<<(std::ostream& os, cell_3& cell)
{
    cell.write(os);

    return os;
}

