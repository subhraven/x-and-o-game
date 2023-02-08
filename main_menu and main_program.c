#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>
//#include "play.c"
char user1[26];
char user2[26];
int input_choice;
char main_menu;

int match=0,t1=0,t2=0;
char box[9]={'1','2','3','4','5','6','7','8','9'};

void reset_box()
{
    char j;int i;
    for(i=0,j='1'; i<9, j<='9' ;i++,j++)
    {
        box[i]=j;
    }
}

void display()
{
    printf("\t\t\t\t\t\t\t\t\t    --- --- --- \n");
    printf("\t\t\t\t\t\t\t\t\t   | %c | %c | %c |",box[0],box[1],box[2]);
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t    --- --- --- \n");
    printf("\t\t\t\t\t\t\t\t\t   | %c | %c | %c |",box[3],box[4],box[5]);
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t    --- --- --- \n");
    printf("\t\t\t\t\t\t\t\t\t   | %c | %c | %c |",box[6],box[7],box[8]);
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t    --- --- --- \n");  
}

int valid_input_by_user(){
    char stri[20];
    scanf("%s",stri);
    while((!('1'<=stri[0] && stri[0]<='9')) || (!(stri[1]=='\0'))){
        printf("Enter a number from 1-9 : ");
        scanf("%s",stri);
    }
    return (atoi(stri));
}

int gives_values()
{
    int num,a=1;
    while(a==1)
    {
    srand(time(NULL));
    num = (rand() % 9)+1;    // 1 to 9 numbers user or computer will generate hence making it esay to make uniform code for all  
    if(!((box[(num-1)]=='X') || (box[(num-1)]=='O'))){break;}
    }
    return(num);
}

int ask_user(int rotate)
{
    int num;
    printf("\n\n");
    if (rotate==1){printf("\t\t\t\t\t\t\t\t\t   *************\n");}


    if(input_choice==1)
    {
    if(rotate%2 != 0)
        {
            printf("\t\t\t\t\t\t\t\t\t   %s: ",user1);
            return valid_input_by_user();
        }
    else 
        {
            printf("\t\t\t\t\t\t\t\t\t   %s: ",user2);
            return valid_input_by_user();
        }
    }


    else if (input_choice==2)
    {  
    if(rotate%2 != 0)
        {
            num=gives_values();
            printf("\t\t\t\t\t\t\t\t\t   %s: %d\n",user1,num);
            
        }
    else 
        {
            printf("\t\t\t\t\t\t\t\t\t   %s: ",user2);
            return valid_input_by_user();  
        }
    }


    else if (input_choice==3) 
    {
        if(rotate%2 != 0)
        {
            printf("\t\t\t\t\t\t\t\t\t   %s: ",user1);
            return valid_input_by_user(); 
        }
        else 
        {
            num=gives_values();
            printf("\t\t\t\t\t\t\t\t\t   %s: %d\n",user2,num);
        }
    }
    printf("\n");
    return (num);
}

void check(int num,int rotate)
{
        if(!((box[(num-1)] == 'X') || (box[(num-1)] == 'O')))
            {
                if (rotate%2 != 0)
                {
                    box[num-1]='X';
                    printf("\n");
                    return ;
                }
                else
                {
                    box[num-1]='O';
                    printf("\n");
                    return ;
                }
            }
        else
            {
                printf("The place is occupied, enter other number : ");
                check (valid_input_by_user(),rotate);
            }  
}

int result(int rotate)
{
    int rot1,rot2;
    if (rotate>=5)
    {
        for(rot1=0,rot2=0;rot1<=6,rot2<=2;rot1+=3,rot2++)
        {
            if(box[rot1]==box[rot1+1] && box[rot1+1]==box[rot1+2])
            {
                if(rotate%2 != 0){printf("%s won\n",user1);t1++;}
                else{printf("%s won\n",user2);t2++;}
                return 1;
            }
            if(box[rot2]==box[rot2+3] && box[rot2+3]==box[rot2+6])
            {
                if(rotate%2 != 0){printf("%s won\n",user1);t1++;}
                else{printf("%s won\n",user2);t2++;}
                return 1;
            }
        }
        /*for(rot2=0;rot2<=2;rot2++)
        {
            if(box[rot2]==box[rot2+3] && box[rot2+3]==box[rot2+6])
            {
                if(rotate%2 != 0){printf("%s won\n",user1);t1++;}
                else{printf("%s won\n",user2);t2++;}
                return 1;
            }
        }*/
        if(box[0]==box[4]&&box[4]==box[8])
            {
                if(rotate%2 != 0){printf("%s won\n",user1);t1++;}
                else{printf("%s won\n",user2);t2++;}
                return 1;
            }
        if(box[2]==box[4]&&box[4]==box[6])
            {
                if(rotate%2 != 0){printf("%s won\n",user1);t1++;}
                else{printf("%s won\n",user2);t2++;}
                return 1;
            }
        if (rotate==9)
            {printf("It's a Tie\n");return 1;}
    }
    else{return 0;}
}

int end()
{
    char ended;
    do
    {
    printf("Do you want to continue (Y / y) / (N / n): ");
    scanf("%s",&ended);
    }while (!(ended=='y'||ended=='Y'||ended=='n'||ended=='N'));
    if (ended=='y'||ended=='Y'){return 1;}  
    else {return 0;}
}

void dump()
{
    FILE *fp;
    fp=fopen("score.txt","a");
    fputc('\n',fp);
    fprintf(fp,"%s","--------------------------------------------------------");
    putc('\n',fp);
    putc('\n',fp);
    fprintf(fp,"%s","Name of Player 1 : ");
    fprintf(fp,"%s",user1);
    putc('\n',fp);
    fprintf(fp,"%s","Name of Player 2 : ");
    fprintf(fp,"%s",user2);
    putc('\n',fp);
    fprintf(fp,"%s","Number of matches played : ");
    fprintf(fp,"%d",match);
    putc('\n',fp);
    fprintf(fp,"%s","Matches won by ");
    fprintf(fp,"%s",user1);
    fprintf(fp,"%s"," : ");
    fprintf(fp,"%d",t1);
    putc('\n',fp);
    fprintf(fp,"%s","Matches won by ");
    fprintf(fp,"%s",user2);
    fprintf(fp,"%s"," : ");
    fprintf(fp,"%d",t2);
    fclose(fp);
}

void score()
{   
    printf("--------------------------------------------------------\n");
    printf("\nName of Player 1 : %s",user1);
    printf("\nName of Player 2 : %s",user2);
    printf("\nNumber of matches played : %d",match);
    printf("\nMatches won by %s : %d",user1,t1);
    printf("\nMatches won by %s : %d\n",user2,t2);
    dump();    
}

int pvp(){

    do          
    {
    reset_box();
    printf("\t\t\t\t\t\t\t\t\t      MATCH %d\n",++match);   
    display();
    printf("\n\n"); 
    
    for(int rotate=1;rotate<=9;rotate++)
        {
            check (ask_user(rotate),rotate);
            display();
            sleep(2);
            printf("\t\t\t\t\t\t\t\t\t   *************\n");
            if (result(rotate)==1) {break;}
        }
    }while(end()==1);

    score();

    do 
    {
        printf("If you want to go to MAIN MENU then enter ('m'/ 'M')  or press  ('e' / 'E') to EXIT : ");
        scanf("%s",&main_menu);
        if(!(main_menu=='m'||main_menu=='M'||main_menu=='e'||main_menu=='E'))
        {
            printf("please enter e,E,m or M :");
            scanf("%s",&main_menu);
        }
    }while(!(main_menu=='m'||main_menu=='M'||main_menu=='e'||main_menu=='E'));

    return 0;
}

int ask_the_mode_of_game()
{
        char arr[20];
        printf("        Select your mode :\n");
        printf("   -----------------------------------\n");
        printf("    -> Enter 1 : Player VS Player\n");
        printf("    -> Enter 2 : Computer vs Player\n");
        printf("    -> Enter 3 : Player VS Computer\n");
        printf("    -> Enter 4 : Random Selection Between 2 and 3\n");
        printf("\nYour choice: ");
        scanf("%s",arr);    

        while(!(arr[0]=='1'||arr[0]=='2'||arr[0]=='3'||arr[0]=='4') || arr[1]!='\0')
        {
            printf("ERROR\n");
            printf("Enter a number in range of 1 to 4: ");
            scanf("%s",arr);
        }
        
        if (atoi(arr)==4)
        {
            srand(time(NULL));
            return ((rand()%(3-2+1))+2);
        }
        else{return atoi(arr);}
}

void introduction()

{
    printf("\n\n"); 
    printf("\t\t\t\t\t\t\t\t\t ------------------------------------ \n");
    printf("\t\t\t\t\t\t\t\t\t| ***** WELCOME TO TIC TAC TOE ***** |\n");
    printf("\t\t\t\t\t\t\t\t\t ------------------------------------ \n");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t    ------------------- \n");
    printf("\t\t\t\t\t\t\t\t\t   | RULES OF THE GAME |\n");
    printf("\t\t\t\t\t\t\t\t\t    ------------------- \n\n");
    printf(" -------------------------------------------------------------------------- \n");
    printf("|1. %s is assigned symbol 'X'                                              \n",user1);
    printf(" -------------------------------------------------------------------------- \n");
    printf("|2. %s is assigned symbol 'O'                                              \n",user2);
    printf(" -------------------------------------------------------------------------- \n");
    printf("|3. Enter any number from 1-9 to place your symbol in that box.            \n");     
    printf(" -------------------------------------------------------------------------- \n");
    printf("|4. A symbol can't be placed at a location pre-occupied by another symbol. \n");
    printf(" --------------------------------------------------------------------------\n");
}

int main_menu_of_game(){
    printf("MAIN MENU\n\n");
    char arr[20];
    do{
        /*printf("        Select your mode :\n");
        printf("   -----------------------------------\n");
        printf("    -> Enter 1 : Player VS Player\n");
        printf("    -> Enter 2 : Computer vs Player\n");
        printf("    -> Enter 3 : Player VS Computer\n");
        printf("    -> Enter 4 : Random Selection Between 2 and 3\n");
        printf("\nYour choice: ");
        scanf("%s",arr);    

        while(!(arr[0]=='1'||arr[0]=='2'||arr[0]=='3'||arr[0]=='4') || arr[1]!='\0')
        {
            printf("ERROR\n");
            printf("Enter a number in range of 1 to 4: ");
            scanf("%s",arr);
        }*/

        input_choice=ask_the_mode_of_game();

        /*if (input_choice==4)
        {
            srand(time(NULL));
            input_choice= (rand()%(3-2+1))+2;
        }*/

        match=0;t1=0;t2=0;

        switch(input_choice)
        {
            case 1 :    printf("***** PLAYER V/S PLAYER MODE *****\n");
                        printf("Enter name of Player 1 (in 25 digits) : ");
                        scanf("%s",user1);
                        printf("Enter name of Player 2 (in 25 digits) : ");
                        scanf("%s",user2);
                        introduction();
                        printf("\n\n");
                        sleep(2);
                        pvp();
                        break;
            case 2 :    printf("***** COMPUTER V/S PLAYER *****\n");
                        user1[0] = 'C';user1[1] = 'o';user1[2] = 'm';user1[3] = 'p';user1[4] = 'u';user1[5] = 't';user1[6] = 'e';user1[7] = 'r';user1[8] = '\0';
                        printf("Player 1 is : %s\n",user1);
                        printf("Enter name of Player 2  (in 25 digits) : ");
                        scanf("%s",user2);
                        introduction();
                        printf("\n\n");
                        sleep(2);
                        pvp();
                        break;
            case 3 :    printf("***** PLAYER V/S COMPUTER *****\n");
                        user2[0] = 'C';user2[1] = 'o';user2[2] = 'm';user2[3] = 'p';user2[4] = 'u';user2[5] = 't';user2[6] = 'e';user2[7] = 'r';user2[8] = '\0';
                        printf("Enter name of Player 1 (in 25 digits) : ");
                        scanf("%s",user1);
                        printf("Player 2 is : %s\n",user2);
                        introduction();
                        printf("\n\n");
                        sleep(2);
                        pvp();                        
                        break;
        }

    }while(main_menu=='m'|| main_menu=='M');
    return 0;
}