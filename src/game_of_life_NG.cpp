#include <iostream>
#include <vector>


#include "../include/cell_t.hpp"
#include "../include/board_t.hpp"

void write_pattern(int n, int m);

void run_generations(int it, int n, int m, board_t& cells);

int create_osc(int n, int m, board_t& cells);
int create_ship(int n, int m, board_t& cells);
int select_1by1(int n, int m, board_t& cells);


int main(void) {
    int n, m, it;
    bool to_print = false;


    std::cout << "INTRODUZCA LAS DIMENSIONES DEL TABLERO: \n";
    std::cout << "filas: ";
    std::cin >> n;
    std::cout << "\n";
    std::cout << "columnas: ";
    std::cin >> m;
    std::cout << "\nINTRODUZCA AHORA EL NÚMERO DE TURNOS: ";
    std::cin >> it;
    std::cout << "\n\n\n";

    board_t cells(n, m);

    int opt = 5;
    std::cout << "SELECCIONE UNA OPCIÓN DE INICIO: " << std::endl;
    std::cout << "Seleccionar oscilador de 3 células     --> introducir 1 \n";
    std::cout << "Seleccionar planeador pequeño          --> introducir 2 \n";
    std::cout << "Seleccionar manualmente las posiciones --> introducir 3 \n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "salir                                  --> introducir 0 \n\n";
    std::cout << "Introduzca una opción: ";
    std::cin >> opt;

    switch (opt)
    {
        case 1:
    
            to_print = create_osc(n,m, cells);
            break;
    
        case 2:
            to_print = create_ship(n, m, cells);
            break;
    
        case 3:
    
            std::cout << "SELECCIONE LAS POSICIONES DEL TABLERO DONDE HAY UNA CÉLULA VIVA: \n";
            to_print = select_1by1(n, m, cells);
            break;
    
        case 0:
            cells.~board_t();
            to_print = false;
            break;
    
        default:
            break;
    }
    
    if(to_print)
      return 1;
    
    run_generations(it, n, m,cells);
    
    cells.~board_t();
    return 0;
}


///// FUNCIONES /////

void write_pattern(int n, int m)
{
    std::cout << "Este es el patrón que sigue el tablero: \n";

    std::cout << "\n╔";
    for (int i = 0; i < m; i++)
        std::cout << "════════";
    std::cout << "╗\n\n";
    for  (int i = 0; i < n; i++ ) 
    {

        std::cout << "║";
        for (int j = 0; j < m; j++ )
        {
            std::cout << " " 
            << "[" << i << "][" <<  j << "]"
            << " ";
        }
        std::cout << "║\n\n";
    }
        std::cout << "╚";
    for (int i = 0; i < m; i++)
        std::cout << "════════";

    std::cout << "╝\n\n";


}

void run_generations(int it, int n, int m, board_t& cells)
{
    std::cout << "Turno 0: \n";
    cells.write(std::cout);
    
    for (int i = 0; i < it; i++) 
    {
        for (int i = 1 ; i < n + 1; i++)
        {
            for (int j = 1 ; j < m + 1; j++)
            {
                cells.at(i,j).count_neighbours(cells);
            }
        }
    
        for (int i = 1 ; i < n + 1; i++)
        {
            for (int j = 1 ; j < m + 1; j++)
            {
                cells.at(i,j).updateState();
            }
        }

        for (int i = 0; i < cells.get_n(); i++) {
            for (int j = 0; j < cells.get_m(); j++)
            {
                cells.at(i, j).set_state( cells.at(i,j).get_next() );
            }
        }
    
        std::cout << "Turno" << it <<  ": \n";
        cells.write(std::cout);        
    }

}

int create_osc(int n, int m, board_t& cells)
{
    if(n >= 3 && m >=3)
    {
        if(((n + m) % 2) == 1)
        {
            cells.at(n/2 + 20, m/2 ).set_state(1);
            cells.at(n/2 + 20, m/2 + 1).set_state(1);
            cells.at(n/2 + 20, m/2 + 2).set_state(1);
        } 
        if (((n + m) % 2) == 0)
        {
            cells.at(n/2 + 1 , m/2  ).set_state(1);
            cells.at(n/2 + 1 , m/2 + 1).set_state(1);
            cells.at(n/2 + 1 , m/2 + 2 ).set_state(1);
        }
        return 0;
    } 
    else
    {
        std::cout << "ERROR: required at least a 3x3 board" 
        << std::endl;
        return 1;
    }
}
int create_ship(int n, int m, board_t& cells)
{
    if (n >= 5 && m >= 5)
    {
        cells.at(3 , 1 ).set_state(1);
        cells.at(4 , 2 ).set_state(1);
        cells.at(4 , 3 ).set_state(1);
        cells.at(3 , 3 ).set_state(1);
        cells.at(2 , 3 ).set_state(1);
        return 0;
    }
    else
    {
        std::cout << "ERROR: required at least a 5x5 board"
        << std::endl;
        return 1;
    }
  
}

int select_1by1(int n, int m, board_t& cells)
{

    write_pattern(n ,m);   
    int x = 1;
    std::vector< std::pair<int, int> > nums;

    std::cout << "Indique la secuencia de números por pareja que quiere que sean células vivas \n\n";
    
    while (x != 0) {
        std::pair<int,int> aux;
        std::cout << "introduzca una pareja de coordenadas: \n";
        std::cout << "Y: ";
        std::cin >> aux.first;
        std::cout << "X: ";
        std::cin >> aux.second;
        
        nums.push_back(aux);

        std::cout << "¿Desea terminar ? 0 -> si, otro -> no :";
        std::cin >> x;
    }

    
    for (int i = 1 ; i < n + 1; i++)
    {
        for (int j = 1 ; j < m + 1; j++)
        {
            for (unsigned int k = 0; k < nums.size(); k++)
                if (i == nums[k].first && j == nums[k].second )
                    cells.at(i,j).set_state(1);

        }
    }
    return 0;
} 


