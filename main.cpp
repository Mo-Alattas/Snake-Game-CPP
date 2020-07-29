#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

/////parameters
bool GameOver;
const int width = 20;    /////screen boarders
const int height = 20;
int x,y, fruitX,fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

////functions
void setup()
{
    srand(time(0));
    GameOver = false;
    nTail=0;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = 1+(rand()%(width-1));
    fruitY = rand()%height;
    for(int i=0;i<100;i++)
        {
            tailX[i]=0; tailY[i]=0;
        }
    score = 0;
 //   char rst;
 //   cin>>rst;
 //   if(rst == 'x'){}
}

///gameover function
void gameover()
{

    setup();

}
void draw()
{

    system("cls");


    for(int i=0;i<width+2;i++){cout<<"#";}
    cout<<endl;



    for(int i=0;i<height;i++)
    {

///////////////////////////////////////////////////////line print start
    for(int j=0;j<width+2;j++)
        {
            if(j==0) {cout<<"|";}

            else if(i==y && j==x) {cout<<"O";}

            else if(i==fruitY && j==fruitX) { cout<<"?";}

            else { bool printCrt = false;
                   for (int t = 0; t<nTail;t++)
                       {
                         if(tailX[t] == j && tailY[t] == i) { cout<<"O";printCrt=true;}
                       }
                    if(!printCrt){cout<<" ";}
                 }

             if(j==width){cout<<"|";}

        } cout<<endl;

///////////////////////////////////////////////////////////////////end of line
    }
    for(int i=0;i<width+2;i++){cout<<"#";}
    cout<<endl;

    cout<<"Score: "<< score<<endl;
 //   cout<<"fruitX: "<< fruitX<<endl;
 //   cout<<"fruitY: "<< fruitY<<endl;
 //   cout<<"X: "<< x<<endl;
 //   cout<<"Y: "<< y<<endl;
  //  cout<<"nTail: "<< nTail<<endl;
  //  cout<<"tailPrint: "<< tailPrint<<endl;

}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }

}

void logic()
{

    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    int prev2X, prev2Y;
    /////tail control
    for (int i = 1; i<nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
//////change dir
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }


/////head and fruit control

    if (x>width){x=1;} else if (x<=0){x=width;}
    if (y>=height){y=0;} else if (y<0){y=height-1;}
    if (x==fruitX && y==fruitY)
    {
        score +=10;
        //do{
                fruitX = 1+rand()%width;fruitY = rand()%height;
       // }while (fruitX!=x && y==fruitY);

        nTail++;

    }

    for(int i=0;i<nTail;i++)
        {
            if (x==tailX[i] && y==tailY[i]){GameOver=true;}
            if (x==tailX[nTail-1] && y==tailY[nTail-1]){x--;y--;}
        }


}

////Main function
int main()
{
  setup();

  while(!GameOver)
  {
      draw();
      input();
      logic();
      Sleep(50);

  }
    system("cls");
    cout<<"Your Score is: "<< score<<endl;
    cout<< "Enter:\n 1 to retry.......\n 2 to Exist....... "<<endl;
    int x;
    cin>>x;
    if (x==1){main();}


    return 0;
}
