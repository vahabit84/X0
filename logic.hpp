#pragma once
#include<cstdint>
#include<windows.h>
enum CellState{Empty,X,O};
typedef enum CellState cell;
extern size_t szField;
struct Pos{
    size_t posX;
    size_t posY;
};
void printField(cell *A){
    system("CLS");
    for(size_t i=0;i<szField;i++){
        std::cout <<"|";
        for(size_t j=0;j<szField;j++ ) {
            if(A[(szField*i)+j]==Empty) std::cout << "_" << "|";
            if(A[(szField*i)+j]==X) std::cout << "X" << "|";
            if(A[(szField*i)+j]==O) std::cout << "0" << "|";
        }
        std::cout << "\n";
    }
}

bool is_draw(CellState *map)
{
    for (size_t i = 0; i < szField*szField; i++)
    {
        if ( map[i] == CellState::Empty)
        {
            return false;
        }
    }
    return true;
}
bool is_win(CellState *map, CellState K){

    size_t w=0;
    //stroki
    for(size_t i=0; i<szField;i++){
        w=0;
        for(size_t j=0; j<szField;j++){
            //std::cout << "stroki\n";
            if( K!=map[((i*szField)+j)] ) break;
            K=map[((i*szField)+j)];
            w++;
        }
        if(w==(szField)) return true;
        //stolbchi
        w=0;
        for(size_t j=0; j<szField;j++){
            if( K!=map[i+(j*szField)]) break;
            K=map[i+(j*szField)];w++;
        }
        if(w==szField) return true;
    }
        //dioganal 1
        w=0;
        for(size_t j=0; j<szField;j++){
            //std::cout << "dioganaal1\n";
            if( K!=map[(szField+1)*j]) break;
             K=map[(szField+1)*j];w++;
        }
        if(w==szField) return true;
        //dioganal 2
        w=0;
        for(size_t j=0; j<szField;j++){
            //std::cout << "diogsnsl2\n";
            if( K!=map[(szField-1)*(j+1)]) break;
             K=map[(szField-1)*(j+1)];w++;
        }
        if(w==szField) return true; 
return false;    
}
//проверка победа-ничья
enum Vihod{continium, win,draw};

Vihod Proverka(CellState* map,CellState player){
    if(is_win(map,player))return win;
    if(is_draw(map)){return draw;};
    return continium;
}