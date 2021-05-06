#pragma once
#include<random>



Pos AI (CellState* map){
    
    CellState A[szField*szField];
    for(size_t i=0;i<(szField*szField);i++){
        A[i]=map[i];
    }
    Pos C[szField*szField];
    size_t n=0;
    for (size_t i=0;i<szField;i++){
        for(size_t j=0; j<szField;j++){
            if(A[(i*szField)+j]==Empty) { n++;
            C[n].posX=i;
            C[n].posY=j;
            }
        }
    }
    for(size_t i=1; i<n;i++){
        A[(C[i].posX*szField)+C[i].posY]=O;
        if(is_win(A, O)) return C[i];
        else A[(C[i].posX*szField)+C[i].posY]=Empty;
    }
    
    for(size_t i=1; i<n; i++){
        A[(C[i].posX*szField)+C[i].posY]=X;
        if(is_win(A, X)) return C[i];
        else A[(C[i].posX*szField)+C[i].posY]=Empty;
    }
    
    size_t idx;
    do{
    std::mt19937 algorithm;
    std::uniform_int_distribution<> dist(1, n);
    idx = dist(algorithm);
    }
    while (!is_valid_pos(C[idx].posX,C[idx].posY, szField));
    return C[idx];
}