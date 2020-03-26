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

    
    if(to_print)
      return 1;
    
    cells.stage_zero();

    cells.write(std::cout);
    for (int i = 0; i < it; i++)
    {
        cells.transition();
        cells.write(std::cout);
    }

    //cells.~board_t();

    return 0;
}


