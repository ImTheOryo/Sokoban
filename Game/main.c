#include "main.h"

char board[10][10] =
        {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
        };

int playerx = 0, playery =0;
int boxx, boxy;
int goalx, goaly;
int result =0;
int main(void) {
    menu(&result);
    game_start_player_position(board, &playerx, &playery);
    game_start_box_position(board, &boxx, &boxy);
    game_start_goal_position(board, &goalx, &goaly);
    while(result == 0) {
        if(board[goalx][goaly] == ' ')
            board[goalx][goaly] = '.';
        system("clear");
        printf("- Position of player is : %d : %d\n",playerx,playery);
        printf("- Position of box is : %d : %d\n",boxx, boxy);
        printf("- Goal position is : %d : %d\n",goalx,goaly);
        str_show_board(board);
        game_move(board,&playerx,&playery,&boxx,&boxy,&result);
    }
    system("clear");
    if(result == 1)
    {
        printf("You win\n");
    }
    else if (result == 2)
    {
        printf("You lose\n");
    }
    else
    return 0;
}
