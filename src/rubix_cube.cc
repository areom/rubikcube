#include "rubik_cube.h"

SinglePiece::SinglePiece(){
    color[0] = RED;         //FRONT
    color[1] = ORANGE;      //BACK
    color[2] = GREEN;       //RIGHT
    color[3] = BLUE;        //LEFT
    color[4] = YELLOW;      //TOP
    color[5] = WHITE;       //BOTTOM
}


void SinglePiece::column_switch(){
    Color temp{color[0]};
    color[0] = color[5];
    color[5] = color[1];
    color[1] = color[4];
    color[4] = temp;
}


void SinglePiece::row_switch(){
    Color temp{color[0]};
    color[0] = color[3];
    color[3] = color[1];
    color[1] = color[2];
    color[2] = temp;
}


void SinglePiece::level_switch(){
    Color temp{color[4]};
    color[4] = color[3];
    color[3] = color[5];
    color[5] = color[2];
    color[2] = temp;
}


RubixCube::RubixCube(){
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            for(int z = 0; z < 3; z++){
                SinglePiece p(x, y, z);
                cubes[x][y][z] = p;
            }
        }
    }
}


void RubixCube::rotate_column(size_t n){
    // x == n
    SinglePiece temp = cubes[n][0][0];
    cubes[n][2][0].column_switch(); cubes[n][0][0] = cubes[n][2][0];
    cubes[n][2][2].column_switch(); cubes[n][2][0] = cubes[n][2][2];
    cubes[n][0][2].column_switch(); cubes[n][2][2] = cubes[n][0][2];
    temp.column_switch();           cubes[n][0][2] = temp;

    temp = cubes[n][0][1];
    cubes[n][1][0].column_switch(); cubes[n][0][1] = cubes[n][1][0];
    cubes[n][2][1].column_switch(); cubes[n][1][0] = cubes[n][2][1];
    cubes[n][1][2].column_switch(); cubes[n][2][1] = cubes[n][1][2];
    temp.column_switch();           cubes[n][1][2] = temp;
}


void RubixCube::rotate_row(size_t n){
    // y == n
    SinglePiece temp = cubes[0][n][0];
    cubes[2][n][0].row_switch();    cubes[0][n][0] = cubes[2][n][0];
    cubes[2][n][2].row_switch();    cubes[2][n][0] = cubes[2][n][2];
    cubes[0][n][2].row_switch();    cubes[2][n][2] = cubes[0][n][2];
    temp.row_switch();              cubes[0][n][2] = temp;

    temp = cubes[0][n][1];
    cubes[1][n][0].row_switch();    cubes[0][n][1] = cubes[1][n][0];
    cubes[2][n][1].row_switch();    cubes[1][n][0] = cubes[2][n][1];
    cubes[1][n][2].row_switch();    cubes[2][n][1] = cubes[1][n][2];
    temp.row_switch();              cubes[1][n][2] = temp;
}


void RubixCube::rotate_level(size_t n){
    // z == n
    SinglePiece temp = cubes[0][0][n];
    cubes[2][0][n].level_switch();  cubes[0][0][n] = cubes[2][0][n];
    cubes[2][2][n].level_switch();  cubes[2][0][n] = cubes[2][2][n];
    cubes[0][2][n].level_switch();  cubes[2][2][n] = cubes[0][2][n];
    temp.level_switch();            cubes[0][2][n] = temp;

    temp = cubes[0][1][n];
    cubes[1][0][n].level_switch();  cubes[0][1][n] = cubes[1][0][n];
    cubes[2][1][n].level_switch();  cubes[1][0][n] = cubes[2][1][n];
    cubes[1][2][n].level_switch();  cubes[2][1][n] = cubes[1][2][n];
    temp.level_switch();            cubes[1][2][n] = temp;
}

void RubixCube::display(){
}
