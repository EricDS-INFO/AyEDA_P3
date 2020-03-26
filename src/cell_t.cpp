// [cell_t.cpp]
//
// AUTOR: Eric Dürr Sierra.
// DATE:  February 2020
// 
// SUBJECT: AyEDA (Algoritmos y Estructuras de Datos Avanzadas)
//
// Ingeniería informática - ESIT ULL 
// (Escuela Superior de Ingeniería y Tecnología - Universidad de La Laguna)
//
// DESCRIPTION:
/*
    This file contains all the methods development from the cell class.
*/


#include "../include/cell_t.hpp"

#include "../include/cell_1.hpp"
#include "../include/cell_2.hpp"
#include "../include/cell_3.hpp"

#include "../include/board_t.hpp"

#include <iostream>
#define INFINITE 1

cell_t* cell_t::create_cell(int type, int i, int j)
{
    cell_t* current_cell;

    switch (type)
    {
    case 0:
        current_cell = new cell_t(i, j);
        break;
    
    case 1:
        current_cell = new cell_1(i, j);
        break;
    
    case 2:
        current_cell = new cell_2(i, j);
        break;

    case 3:
        current_cell = new cell_3(i, j);
        break;
  
    default:
        std::cout << "unknown cell \n";
        std::exit(1);
        break;
    }

    return current_cell;
}

int cell_t::get_state(void) const 
{
    return 0;
}


int cell_t::get_i_pos(void)
{
    return i_;
}

void cell_t::set_i_pos(int i)
{
    i_ = i;
}

int cell_t::get_j_pos(void)
{
    return j_;
}

void cell_t::set_j_pos(int j)
{
    j_ = j;
}

std::ostream& cell_t::write( std::ostream& os) 
{
    os << " ";
    return os;
}

std::ostream& operator<<(std::ostream& os, cell_t& cell)
{
    cell.write(os);

    return os;
}


int cell_t::update_state(void)
{
    if ( alive_neighbours_ == 3)
        return 1;


    if ( alive_neighbours_ == 3 ||
         alive_neighbours_ == 6 ||
         alive_neighbours_ == 8)
        return 2;
    
    if ( alive_neighbours_ == 3 ||
         alive_neighbours_ == 4 ||
         alive_neighbours_ == 6)
        return 3;
    else
        return 0;
    
}


int cell_t::count_neighbours(const board_t& board)
{
    int neighbours = 0;
    
    
        // Check the basic axis
        /* UP */
        if (board.at(i_ - 1, j_)->get_state() != 0)         neighbours++;
        /* DOWN */
        if (board.at(i_ + 1, j_)->get_state() != 0)         neighbours++;
        /* LEFT */
        if (board.at(i_, j_ - 1)->get_state() != 0)         neighbours++;
        /* RIGHT */
        if (board.at(i_, j_ + 1)->get_state() != 0)         neighbours++;

        //check the diagonal axis:
        /*1st square*/
        if (board.at(i_ - 1, j_ - 1)->get_state() != 0)     neighbours++;
        /*2nd square*/
        if (board.at(i_ + 1, j_ - 1)->get_state() != 0)     neighbours++;
        /*3rd square*/
        if (board.at(i_ - 1, j_ + 1)->get_state() != 0)     neighbours++;
        /*4th square*/
        if (board.at(i_ + 1, j_ + 1)->get_state() != 0)     neighbours++;   
    
        
    alive_neighbours_ = neighbours;

    return neighbours;
}




// this function captures the left cell values
int cell_t::left(int pos, int n)
{
    if (pos == 0 ) 
        pos = n - 1; 
    else 
        pos--;
 return pos;
}


// this function captures the right cell values
int cell_t::right(int pos, int n)
{
    if (pos == n - 1 ) 
        pos = 0; 
    else 
        pos++;
 return pos;
}

// this function captures the up cell values
int cell_t::up(int pos, int m)
{
    if (pos == 0 ) //if actual position is 0 in y axis in matrix, we get the greater number
        pos = m - 1; 
    else 
        pos--;     // we decrease one position in y axis.
 return pos;
}

// this function captures the down cell values
int cell_t::down(int pos, int m)
{
    if (pos == m - 1 ) 
        pos = 0; 
    else 
        pos++;
 return pos;
}