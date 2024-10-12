#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#ifndef MAIN_H
#define MAIN_H

int menu(int *result)
{

    int option;
    returnmenu:
    printf("Welcome to my Sokoban game in C\n"
            "Press 1 to play\n"
            "Press 2 to see the rules\n"
            "Press any other keys to exit\n");
    printf("Choose an option: ");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            system("clear");
            return 1;
        case 2:
            system("clear");
            break;
        default:
            printf("Thank you for playing\n");
            *result = 3;
        return 1;
    }

    printf(" --- The rules of Sokoban --- \n"
        " - The goal of the game is simple : \n"
        " - YOU the player you are represented by a 'o' on the board \n"
        " - Your goal is to move the box represented by a 'x' into the correct position represented by a '.'"
        " - Be careful with the box because you can stuck the box and if so you loose the game \n"
        " - You can move by pressing the Z Q S D key\n"
        " - You be spawning randomly each time you play and the box will too \n"
        " --- Now let's play --- \n");
        sleep(5);
        system("clear");
        return 1;

}


char  str_show_board(char board[10][10])
{
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0 ; j < 10; j ++)
        {
            printf("%c", board[i][j]);
            if(j==9)
            {
                printf("\n");

            }
        }
    }
}
char game_start_player_position(char board[10][10], int *position_player_x , int *position_player_y)
{

        srand(time(NULL));
        *position_player_x= rand() % 8 + 1;
        *position_player_y = rand() % 8 + 1;
        board[*position_player_x][*position_player_y] = 'O';
        return 1;



}
char game_start_box_position(char board[10][10],int *posx , int *posy)
{
    srand(time(NULL));
    retry:
    *posx = rand() % 3 + 5;
    *posy = rand() % 3 + 5;
    if (board[*posx][*posy] == 'O')
        goto retry;
    else
        board[*posx][*posy] = 'X';

    return 1;
}
char game_start_goal_position(char board[10][10],int *posx, int *posy)
{
    srand(time(NULL));
    retry:
    *posx = rand() % 7 + 2;
    *posy = rand() % 7 + 2;
    if(board[*posx][*posy] == 'O' || board[*posx][*posy] == 'X')
        goto retry;
    else
        board[*posx][*posy] = '.';

    return 1;
}







char game_move(char board[10][10], int *position_player_x, int *position_player_y, int *position_box_x, int *position_box_y, int *result)
{
    char playermove;
    retry:
    printf("Choose a movement to do between : UP (z) | DOWN (s) | RIGHT (d) | LEFT (s) \n ");
    scanf(" %c", &playermove);
    switch(playermove)
    {
        case 'z':
                board[*position_player_x][*position_player_y] = ' ';
                *position_player_x = *position_player_x -1;
            if(board[*position_player_x][*position_player_y] == 'X')
            {
                *position_box_x = *position_box_x - 1;
                if(board[*position_box_x][*position_box_y] == '#')
                {
                    *result = 2;
                }
                else if (board[*position_box_x][*position_box_y] == '.')
                {
                    *result = 1;
                }
                    else
                {
                   board[*position_box_x][*position_box_y] = 'X';
                }
            }
            if(board[*position_player_x][*position_player_y] == '#')
            {
                *position_player_x = *position_player_x + 1;
            }

                board[*position_player_x][*position_player_y] = 'O';
                break;
        case 's':
                board[*position_player_x][*position_player_y] = ' ';
                *position_player_x = *position_player_x + 1;
        if(board[*position_player_x][*position_player_y] == 'X')
        {
            *position_box_x = *position_box_x + 1;
            if(board[*position_box_x][*position_box_y] == '#')
            {
                *result = 2;
            }
            else if (board[*position_box_x][*position_box_y] == '.')
            {
                *result = 1;
            }
            else
            {
                board[*position_box_x][*position_box_y] = 'X';
            }
        }
            if(board[*position_player_x][*position_player_y] == '#')
            {
                *position_player_x = *position_player_x - 1;
            }

                board[*position_player_x][*position_player_y] = 'O';
                break;

        case 'd':
                board[*position_player_x][*position_player_y] = ' ';
                *position_player_y = *position_player_y + 1;
        if(board[*position_player_x][*position_player_y] == 'X')
        {
            *position_box_y = *position_box_y + 1;
            if(board[*position_box_x][*position_box_y] == '#')
            {
                *result = 2;
            }
            else if (board[*position_box_x][*position_box_y] == '.')
            {
                *result = 1;
            }
            else
            {
                board[*position_box_x][*position_box_y] = 'X';
            }
        }
            if(board[*position_player_x][*position_player_y] == '#')
            {
                *position_player_y = *position_player_y - 1;
            }

                board[*position_player_x][*position_player_y] = 'O';
                break;

        case 'q':
                board[*position_player_x][*position_player_y] = ' ';
                *position_player_y = *position_player_y - 1;
        if(board[*position_player_x][*position_player_y] == 'X')
        {
            *position_box_y = *position_box_y - 1;
            if(board[*position_box_x][*position_box_y] == '#')
            {
                *result = 2;
            }
            else if (board[*position_box_x][*position_box_y] == '.')
            {
                *result = 1;
            }
            else
            {
                board[*position_box_x][*position_box_y] = 'X';
            }
        }
            if(board[*position_player_x][*position_player_y] == '#')
            {
                *position_player_y = *position_player_y + 1;
            }

                board[*position_player_x][*position_player_y] = 'O';
                break;

        default:
            goto retry;
    }
}






#endif //MAIN_H
