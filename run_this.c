#include<stdio.h>
#include<windows.h>
#include "print date and time in ascii file.c"
#include "menu of game.c"
#include "print end design in file.c"
#define date_and_time_in_file store_date_and_time();
#define game main_menu_of_game();
#define ending_program design_of_end();
int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6); 
    date_and_time_in_file
    game
    ending_program
    return 0;   
}