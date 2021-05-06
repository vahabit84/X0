#pragma once
bool is_valid_pos(size_t x,size_t y, size_t z){
    return ((x<z)&&(x>=0)&&(y>=0)&&(y<z));
} 
bool is_cell_free(CellState *map,size_t x,size_t y){
    return (map[(x*szField)+y]==Empty);
} 

Pos move(CellState *map,size_t z){
    Pos pos1;
    bool ok=false;
    while(!ok){
        std::cout << "Input position cell 1-3\n>";
        std::cin >> pos1.posX >> pos1.posY;
        pos1.posX--;
        pos1.posY--;
        if (!std::cin) {
            std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Error: please input numbers!\n>"; 
        }
        else if (!is_valid_pos(pos1.posX, pos1.posY,z))
            {
                std::cout << "Error: position is out of field bounds!\n";
            }
        else if (!is_cell_free(map,pos1.posX,pos1.posY)){
           std::cout << "Error: cell is not free!\n"; 
        }
        else ok =true;
    } 
    return pos1;  
}