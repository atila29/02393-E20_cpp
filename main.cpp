#include <iostream>
#include <string>
#include <vector>


typedef enum {
    wood, stone
} material;
typedef struct {
    int x, y;
    bool isWall;
    material type;
} field;

#define n 12
#define m 16


field playground[n][m];

int x = 5, y = 5;

void print_level() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (playground[i][j].x == x && playground[i][j].y == y) {
                std::cout<<"O";
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
            playground[i][j].isWall = !(j == 3 && i==0 )&& (i == 0 || i == (n - 1) || (j == 0 ) || j == (m - 1));
            if (playground[i][j].isWall && !(i == 3 && j == 0)) { playground[i][j].type = stone; }
            else { playground[i][j].type = wood; }
        }
    }

    std::string line;
    while (std::getline(std::cin, line))
    {

        std::vector<char> v(line.begin(), line.end());

        for(char & it : v) {
            print_level();

            struct update{int x;int y;};

            update changes{x, y};

            switch(it){
                case 'l':
                    changes.y = changes.y - 1;
                    break;
                case 'r':
                    changes.y = changes.y + 1;
                    break;
                case 'u':
                    changes.x = changes.x - 1;
                    break;
                case 'd':
                    changes.x = changes.x + 1;
                    break;
            }

            if(!playground[changes.x][changes.y].isWall) {
                x = changes.x;
                y = changes.y;
            }

            if (it == 'q')
            {
                return 0;
            }
        }

    }






}

