#include <iostream>
#include <cstdint>

#include "logic.hpp"
#include "io.hpp"
#include "ai.hpp"




size_t szField;


main(){
    CellState Player=O;
    Vihod rezultat;
    std::cout << "Enter dimension field\n>";
    std::cin >> szField;
    cell Map[szField*szField] {};
    Pos pos, pos2;
    do{
    if(Player==O) { Player=X;
        pos = move(Map, szField );
        Map[(szField*pos.posX)+pos.posY]=X;
    }
   else { Player=O;
    
        pos2 = AI( Map );
        Map[(szField*pos2.posX)+pos2.posY]=O;
  }
    printField(Map);
    rezultat=Proverka( Map,Player );
       
    }
    while(rezultat == continium);
    if(rezultat==win){if(Player==X) std::cout <<"Win X";
        else std::cout <<"Win O";
        }
    else std::cout << "Draw";
    return 0;
}