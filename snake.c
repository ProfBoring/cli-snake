#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
int width = 30;
int height = 30;
int x_snake = 10;   // initial snake X
int y_snake = 5;    // initial snake Y
char dir = 'd';     // initial direction: 'w','a','s','d'
int isRunning = 1;  //game state variable
int again=0;       //replay variable
void drawGame(int width, int height)
{
//creating top boundary
 for(int i=0;i<width+2;i++){
    printf("[]");
 }
 printf("\n");
 //creating snake and left and right boundaries
 for(int y=0;y<height;y++){
    printf("[]");
    for(int x=0;x<width;x++){
        if(x==x_snake && y==y_snake)
            printf("O ");
        else
            printf("  ");
    }
    printf("[]\n");
 }
 //creating bottom boundary
 for(int i=0;i<width+2;i++){
    printf("[]");}
    printf("\n");}

void gameInput(){
    if( _kbhit()){              //_kbhit() is a function from conio.h which waits for input without pausing the rest of the program
        char key=_getch();      //similarly _getch() is from conio.h the input doesnt echo or appear on tnhe command line
        switch(key){
        case 'w': dir = 'w'; break;
        case 'a': dir = 'a'; break;
        case 's': dir = 's'; break;
        case 'd': dir = 'd'; break;
        }
    }
}
void logic() {
    switch (dir) {
        case 'w': y_snake--; break;    //remember, the origin (0,0) is at the top left, so to increase y coord we must head downwards
        case 's': y_snake++; break;
        case 'a': x_snake--; break;
        case 'd': x_snake++; break;
    }

    // collision with walls → stop game
    if (x_snake < 0 || x_snake >= width || y_snake < 0 || y_snake >= height)
        isRunning = 0;
}

int main(){
    char again;
    do
    {x_snake=10;
     y_snake=5;
     dir='d';
     isRunning=1;
    
    while(isRunning==1){
        drawGame(width,height);
     gameInput();
     logic();
     Sleep(150);
     system("cls"); //clears the console after each frame (windows specific)
    }
    //retry?
    printf("Game Over!\n");
    printf("enter 'Q' to quit or 'R' to retry\n");

    do
    {
        again=_getch();
        again=tolower(again); //tolower makes it case-insensitive
    } while(again!='r' && again!='q');
    }while(again=='r');

 printf("Thanks for playing!\n");
 return 0;   
}




