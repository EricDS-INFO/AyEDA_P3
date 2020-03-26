// [board_t.cpp]
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
    This file contains all the methods development from the board class.
*/

#include "../include/board_t.hpp"
#include "../include/cell_t.hpp"
#include "../include/cell_1.hpp"

#include <iostream>

board_t::board_t(int n = 300, int m = 300)
{
    dimensions_.first = n + 2;
    dimensions_.second = m + 2;
    /*dynamic matrix of cells is created*/
    cell_grid_ = new cell_t **[dimensions_.first];
    
    for (int i = 0; i < dimensions_.first; i++) 
    {
        cell_grid_[i] = new cell_t *[dimensions_.second];
        for (int j = 0; j < dimensions_.second; j++)
        {
            cell_grid_[i][j] = new cell_t(i,j);
        }
    }

    /*this sets the default state of the cells as dead*/
    for (int i = 0; i < dimensions_.first ; i++)  
        for (int j = 0; j < dimensions_.second; j++ )
        {
            cell_grid_[i][j]->set_i_pos(i);
            cell_grid_[i][j]->set_j_pos(j);
        }
}


board_t::board_t(int n = 300, int m = 300, int cell_size = 5)
{
    dimensions_.first = n + 2;
    dimensions_.second = m + 2;
    cell_size_ = cell_size;
    /*dynamic matrix of cells is created*/
    cell_grid_ = new cell_t **[dimensions_.first];
    
    for (int i = 0; i < dimensions_.first; i++) 
    {
        cell_grid_[i] = new cell_t *[dimensions_.second];
        for (int j = 0; j < dimensions_.second; j++)
        {
            cell_grid_[i][j] = new cell_t(i,j);
        }
    }

    /*this sets the default state of the cells as dead*/
    for (int i = 0; i < dimensions_.first ; i++)  
        for (int j = 0; j < dimensions_.second; j++ )
        {
            cell_grid_[i][j]->set_i_pos(i);
            cell_grid_[i][j]->set_j_pos(j);
        }
}

board_t::~board_t()
{    
    for (int i = 0; i < dimensions_.first ; i++) 
    {

        for (int j = 0; j < dimensions_.second; j++)
            delete[] cell_grid_[i][j];

        //delete[] cell_grid_[i];
    }

    dimensions_.first = 0;
    dimensions_.second = 0;

        
    delete[] cell_grid_;

}

cell_t* board_t::at(const int i, const int j ) const
{
   return cell_grid_[i][j];
}

cell_t* board_t::at(const int i, const int j)
{
   return cell_grid_[i][j];
}

std::ostream& board_t::write(std::ostream& os)
{
    os << "\n╔";
    for (int i = 1; i < (dimensions_.second - 1); i++)
        os << "═══";
    os << "╗\n";
    for (int i = 1; i < dimensions_.first - 1; i++)  
    {
        os << "║";
        for (int j = 1; j < dimensions_.second - 1; j++ )
        {
            os << " " << cell_grid_[i][j]->get_state() << " ";       
        }
        os << "║\n";
    }
    os << "╚";
    for (int i = 1; i < (dimensions_.second - 1 ); i++)
        os << "═══";
    os << "╝\n";

    return os;
}


void board_t::stage_zero() 
{
    
    std::cout << "--- Indique el estado del tablero al inicio ---\n";
    std::cout << "Las dimensiones son: " 
              << dimensions_.first - 2<< "X"
              << dimensions_.second - 2<< "\n";
    std::cout << std::endl;
    std::cout << "Deberá indicar el tipo de célula y la posición en la que ese encuentra\n"; 
    std::cout << "Introduzca: \n"
              << "0 - para una célula muerta (valor por defecto)\n"
              << "1 - para una célula 23/3 \n";
    for (int i  = 1; i < dimensions_.first - 1; i++)
    {
        for (int j = 1; j < dimensions_.second -1; j++ )
        {
            int type = 0;
            std::cout <<"Introduzca el tipo en [" 
            << i << "]["
            << j << "]: ";
            std::cin >> type;
            delete cell_grid_[i][j];
            cell_grid_[i][j] = cell_grid_[i][j]->create_cell(type, i, j);
            std::cout << "célula creada: " 
            << cell_grid_[i][j]->get_state() << std::endl;
        }
    }
}


void board_t::transition() 
{
    for (int i = 1; i < dimensions_.first - 1; i++)
    {
        for (int j = 1 ; j < dimensions_.second -1 ; j++)
        {
             cell_grid_[i][j]->count_neighbours(*this);      
        }
    }

    for (int i = 1; i < dimensions_.first - 1; i++)
    {
        for (int j = 1 ; j < dimensions_.second -1 ; j++)
        {
            std::cout << "se actualiza una célula: "
                     << cell_grid_[i][j]->get_state()
                     <<"\n";
           int state = cell_grid_[i][j]->update_state();
           if (cell_grid_[i][j]->get_state() != state)
           {
            delete cell_grid_[i][j];
            cell_grid_[i][j] = cell_grid_[i][j]->create_cell(state, i, j);
            
           }

        }
    }

    
}