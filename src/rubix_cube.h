#include<vector>

typedef enum _Color{
    RED = 0,    //FRONT
    ORANGE,     //BACK
    GREEN,      //RIGHT
    BLUE,       //LEFT
    YELLOW,     //TOP
    WHITE       //BOTTOM
}Color;


class SinglePiece{
    public:
        SinglePiece(size_t nx, size_t ny, size_t nz);
        Color color[6];
        void column_switch();
        void row_switch();
        void level_switch();
};

class RubixCube{
    public:
        RubixCube();
        void rotate_column(size_t n);
        void rotate_row(size_t n);
        void rotate_level(size_t n):
        void display();
    
    private:
        SinglePiece cubes[3][3][3];
}
