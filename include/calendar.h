//Splitting the program to make it look good I guess

#ifndef __CALENDAR_H
 #define __CALENDAR_H
 static const char *nom[12] = {"January", "February", "March",  //Name of month
                               "April", "May", "June", "July",
                               "August", "September", "October",
                               "November", "December"}; 

 //Fills calender[6][7]
 extern void arr_fill(int m, int y);

 //Prints calender[6][7]
 extern void arr_print(int m, int y);                               
#endif 
//End of calendar.h