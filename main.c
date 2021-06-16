#include <stdio.h>
#include <stdlib.h> //system(), atoi()
#include <string.h>
#include <ctype.h> //toupper(), tolower()
#include "include/conio.h"
#include "include/calendar.h"
                 
int main(int argc, char const *argv[])
{
 system("clear");
 int month, year, i;
 char key;
 char ms[10]; //Month String        
 printf("Enter month (as number, name or short form)\n");
 scanf("%s", ms);
 printf("Enter year\n");
 scanf("%d", &year);
 ms[0] = toupper(ms[0]);
 for (i = 1; i < strlen(ms); i++)
 {
  ms[i] = tolower(ms[i]);
 }
 for (i = 0; i < 12; i++)
 {
  if (strcmp(ms, nom[i]) == 0 || strncmp(ms, nom[i], 3) == 0 || strncmp(ms, nom[i], 4) == 0)
  {
   month = i + 1;
   break;
  }
 }
 if(i == 12)
  month = atoi(ms);
 arr_fill(month, year);
 arr_print(month, year);
 getchar();//scanf does not clear the buffer
 key = getkey();  
 while (1)
 {
  if (key == 'A')
   year++;
  else if (key == 'B')
   year--;
  else if (key == 'C')
  {
   if (month == 12)
   {
    month = 1;
    year++;
   }
   else
    month++;
  }
  else if (key == 'D')
  {
   if (month == 1)
   {
    month = 12;
    year--;
   }
   else
    month--;
  }
  else
   break;   
  arr_fill(month, year);
  arr_print(month, year);
  key = getkey();  
 }
 printf("\n");
 return 0;
}
//End of main.c