
#include "../include/cell_t.hpp"

#include "../include/cell_1.hpp"
#include "../include/cell_2.hpp"
#include "../include/cell_3.hpp"
#include "../include/cell_x.hpp"

#include "../include/board_t.hpp"

#include <iostream>


int cell_x::update_state(void) 
{
    if (alive_neighbours_!= 1 )
        return 0;
    else 
        return 4;

}


int cell_x::get_state(void) const 
{
    return 4;
}

std::ostream& cell_x::write(std::ostream& os)
{
    os << "x";
    return os;
} 

std::ostream& operator<<(std::ostream& os, cell_x& cell)
{
    cell.write(os);

    return os;
}

