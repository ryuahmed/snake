#include<iostream>
#include<stdlib.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std ;

char body[20][20] ,drction,dtemp = 'W';
int  x = 15 , y = 10 ,lenght = 3 ;
int brk = 0 ;

initiate()
{
    int i , j ;

    for( i = 0 ; i < 20 ; i++)
    {
        for( j = 0 ; j < 20 ; j++)
        {
            if( i == 0 || i == 19 || j == 0 || j == 19)
            {
                body[i][j] = 'x';
            }
            else
            {
                body[i][j] = ' ' ;
            }
        }
    }



    for( i = x ; i < x + lenght ; i++)
    {
        body[i][y] = '*' ;
    }

    body[x][y] = 'o';

}


up()
{
    int i ;
    char temp ;

    for(i = x ; i < x + lenght ; i ++ )
        {
            temp = body [i-1][y];
            body [i-1][y] = body [i][y];
            body [i][y] = temp ;
        }
        x--;

}

down()
{
    int i ;
    char temp ;

    for(i = x ; i > x -lenght ; i -- )
        {
            temp = body [i+1][y];
            body [i+1][y] = body [i][y];
            body [i][y] = temp ;
        }
        x++;

}

migi()
{
     int j ;
    char temp ;

    for(j = y ; j > y -lenght ; j -- )
        {
            temp = body [x][j+1];
            body [x][j+1] = body [x][j];
            body [x][j] = temp ;
        }
        y--;
}

hidari()
{
     int j ;
    char temp ;

    for(j = y ; j < y + lenght ; j ++ )
        {
            temp = body [x][j-1];
            body [x][j-1] = body [x][j];
            body [x][j] = temp ;
        }
        y--;
}

change()
{


    /*if(x == 5 )
        uptoleft();
    else
        up(); */

    if( drction == 'W' || drction == 'w')
    {
        if(dtemp != 'W' || dtemp == 'w' || dtemp != 'S' || dtemp != 's' )
        {
            dtemp = drction ;
            up();
        }
    }

    if( drction == 'S' || drction == 's')
    {
        if(dtemp != 'W' || dtemp == 'w' || dtemp != 'S' || dtemp != 's' )
        {
            dtemp = drction ;
            down();
        }

    }

    if( drction == 'A' || drction == 'a')
    {
        if(dtemp != 'A' || dtemp == 'a' || dtemp != 'D' || dtemp != 'd' )
        {
            dtemp = drction ;
            migi();
        }

    }

    if( drction == 'D' || drction == 'd')
    {
        if(dtemp != 'A' || dtemp == 'a' || dtemp != 'D' || dtemp != 'd' )
        {
            dtemp = drction ;
            hidari();
        }
    }

    else
    {
         if( dtemp == 'W' || dtemp == 'w')
         {
             up();
         }
          if( dtemp == 'S' || dtemp == 's')
         {
             down();
         }

          if( dtemp == 'A' || dtemp == 'a')
         {
             hidari();
         }

          if( dtemp == 'D' || dtemp == 'd')
         {
             migi();
         }


    }


}


gamecheck()
{
    int i , j ;

    for( i = 0 ; i < 20 ; i++)
    {
        for( j = 0 ; j < 20 ; j++)
        {
            if( i == 0 || i == 19 || j == 0 || j == 19)
            {
               if(body[i][j] == 'o')
                    brk = 1 ;


            }
        }
    }
}

display()
{
    int i , j ;

     for( i = 0 ; i < 20 ; i++)
    {
        for( j = 0 ; j < 20 ; j++)
        {
            cout << body[i][j];
        }
        cout << endl;
    }

}


int main ()
{
    int i,j,first=0;

    initiate();


    while(1)
    {
        drction ='0' ;

        if ( brk == 1 )
        {
            break ;
        }

        change();

        gamecheck();

        if(first>0)
            system("cls");
        display();

        _sleep(500);
         first++;
    }








}

