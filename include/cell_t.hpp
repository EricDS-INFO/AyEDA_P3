// [cell_t.hpp]
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
    This file contains the Cell class definition.
*/
#ifndef CELL_H
#define CELL_H


#include <iostream>
class board_t;
class cell_t
{
    private:
        // debe no depender de este atributo
        
        int i_, j_;
        int n_, m_;
    protected:
        int alive_neighbours_;

    public:
        static cell_t* create_cell(int type, int i, int j);
       
        cell_t(void){}

        cell_t(int i, int j):
        i_(i), 
        j_(j){};
        

        ~cell_t(void){};

        virtual int get_state(void) const;
        

        virtual int get_i_pos(void);
        virtual void set_i_pos(int i);

        virtual int get_j_pos(void);
        virtual void set_j_pos(int j);

        /* Ahora va a devolver el tipo de célula*/
        virtual int update_state(void);

        /*Este método opera igual*/
        virtual int count_neighbours(const board_t& board);

        std::ostream& write( std::ostream& os);
        friend std::ostream& operator<< (std::ostream& os, cell_t& cell);

    private:
        int left(int pos, int n);
        int right(int pos, int n);
        int up(int pos, int m);
        int down(int pos, int m);
};
#endif
