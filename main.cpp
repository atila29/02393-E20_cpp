#include <iostream>
#include <string>


typedef enum {
    wood, stone
} material;
typedef struct {
    int x, y;
    bool isWall;
    material type;
} field;

#define n 16
#define m 12


field playground[n][m];

int x = 5, y = 5;

void print_level() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (playground[i][j].x == x && playground[i][j].y == y) {
                std::cout<<"0";
            }
            else if (playground[i][j].isWall) {
                std::cout<<"*";
            }
            else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i == 0 || i == (n - 1) || (j == 0 && i != 3) || j == (m - 1));
            if (playground[i][j].isWall && !(i == 3 && j == 0)) { playground[i][j].type = stone; }
            else { playground[i][j].type = wood; }
        }
    }

    std::string line;
    while (std::getline(std::cin, line))
    {

        if (line == "l")
        {
            y--;
        }
        else if (line == "r")
        {
            y++;
        }
        else if (line == "u")
        {
            x--;
        }
        else if (line == "d")
        {
            x++;
        }


        print_level();

        if (line == "q")
        {
            break;
        }
    }






}

