
#include "../include/cell_t.hpp"

#include "../include/cell_1.hpp"
#include "../include/cell_2.hpp"
#include "../include/cell_3.hpp"

#include "../include/board_t.hpp"

#include <iostream>


int cell_2::update_state() 
{
    if (alive_neighbours_!= 2 &&
        alive_neighbours_!= 4 &&
        alive_neighbours_!= 5 )
        return 0;
    else
        return 2;
    
}


int cell_2::get_state(void) const 
{
    return 2;
}

std::ostream& cell_2::write(std::ostream& os)
{
    os << "2";
    return os;
} 

std::ostream& operator<<(std::ostream& os, cell_2& cell)
{
    cell.write(os);

    return os;
}

