#include <stdio.h>
#include <stdlib.h>
#include "include/conio.h"
#include "include/calendar.h"

static int calendar[6][7]; //Stores the dates in the order to be displayed
static const char *days[7] = {"Sun", "Mon", "Tue",         //Short name of the days
                              "Wed", "Thu", "Fri", "Sat"}; 

void arr_fill(int m, int y)
{
 int leap, nod, som, i, j, dim, day;//nod - No. of Days, som - Start of Month, dim is nod for a loop
 som = 1; //01/01/1900 starts on Monday and week starts with Sunday. Hence Monday is 1
 for (j = 0; j < 6; j++)
 {
  for (i = 0; i < 7; i++)
   calendar[j][i] = 0;
 }
 if (y % 4 == 0)
 {
  if (y % 100 == 0)
  {
   if (y % 400 == 0)
    leap = 1;
   else
    leap = 0; 
  }
  else
   leap = 1;
 }
 else
  leap = 0;
 if (m == 2)
 {
  if(leap == 0)
   nod = 28;
  else
   nod = 29; 
 }
 else if (m == 4 || m == 6 || m == 9 || m == 11)
  nod = 30;
 else
  nod = 31;
 if (y >= 1900)
 {
  for (i = 1900; i < y; i++)
  { //Loop calculates Start of year and stores it in Start of month
   if (i % 4 == 0)
   {
    if (i % 100 == 0)
    {
     if(i % 400 == 0)
      som += 2;
     else
      som++; 
    }
    else
     som += 2;
   }
   else
    som++; 
  }//som will be huge if year is 2000s. Hence find remainder with 7
 }
 else
 {
  for (i = 1900; i > y; i--)
  {
   if (i % 4 == 1 || i % 4 == -3)
   {
    if (i % 100 == 1 || i % 100 == -99)
    {
     if (i % 400 == 1 || i % 400 == -399)
      som -= 2;
     else
      som--; 
    }
    else
     som -= 2;
   }
   else
    som--; 
  }
 }
 if (som >= 0 || som % 7 == 0)//2nd condition so that som < 7  
  som %= 7;//som now has Start of inputted year.
 else
  som = 7 + (som % 7);//For years below 1899  
 for (i = 1; i < m; i++)
 {
  if (i == 2)
  {
   if (leap == 0)
    dim = 28;
   else
    dim = 29;  
  }
  else if (i == 4 || i == 6 || i == 9 || i == 11)
   dim = 30;
  else
   dim = 31;
  for (j = 1; j <= dim; j++)
  {
   if(som == 6)
    som = 0;
   else
    som++; 
  }  
 }//som now has Start of inputted month
 day = 1;
 for (i = som; i < 7; i++)
  calendar[0][i] = day++;
 for (j = 1; j < 6; j++)
 {
  for (i = 0; i < 7; i++)
  {
   calendar[j][i] = day++;
   if(day > nod)
    break;
  }
  if (day > nod)
   break;
 }
}

void arr_print(int m, int y)
{
 system("clear");
 int col, row, i, j;
 gotoxy(35, 1);
 if (y > 0)
  printf("%s %d CE", nom[m - 1], y);
 else
 {
  y = (-1 * y) + 1;
  printf("%s %d BCE", nom[m - 1], y);
 } 
 for (i = 0; i < 7; i++)
 {
  col = (i + 1) * 10;
  gotoxy(col, 2);
  printf("%s", days[i]);
 }
 for (j = 0; j < 6; j++)
 {
  for (i = 0; i < 7; i++)
  {
   row = j + 3;
   col = (i + 1) * 10;
   gotoxy(col, row);
   if (calendar[j][i] != 0)
    printf("%d", calendar[j][i]);
   else
    printf(" "); 
  }
 }
 printf("\n   Up arrow key: Next year, same month\n");
 printf(" Down arrow key: Previous year, same month\n");
 printf("Right arrow key: Same year, next month\n");
 printf(" Left arrow key: Same year, previous month\n");
 printf("  Any other key: Close the program");
}
//End of calendar.c