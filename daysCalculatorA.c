#include <stdio.h>
#include <stdlib.h>

/*
 *   Program name: daysCalculatorA
 *   Author: Sean Feigis
 *   Last Update: September 17, 2019
 *   Function: to find the number of days between 2 dates
 *   Compilation: gcc -ansi -o daysCalculatorA daysCalculatorA.c
 *   Execution: ./daysCalculator 23 8 2019 25 9 2019
 */

int main ( int argc, char *argv[] ) {

   /* The number of days in each month */
   int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    /* Total days of the year up until each month */
   int totalDays[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

   /* Information about the dates */
   int dd1 = 0;
   int dd2 = 0;
   int mm1 = 0;
   int mm2 =0;
   int yyyy1 = 0;
   int yyyy2 = 0;
   int leap = 0;
   int dayOfYear1 = 0;
   int dayOfYear2 = 0;

   /* Test for correct input */
   if ( argc < 7 ) {
      printf ( "Usage: ./daysCalculatorA dd1 mm1 yyyy1 dd2 mm2 yyyy2 \n" );
      exit ( 1 );
   } else {
      dd1 = atoi ( argv[1] );
      mm1 = atoi ( argv[2] );
      yyyy1 = atoi ( argv[3] );
      dd2 = atoi ( argv[4] );
      mm2 = atoi ( argv[5] );
      yyyy2 = atoi ( argv[6] );
   }

   
   /* Test for the correct month values */
   if ( mm1 < 1 || mm1 > 12 ) {
      printf("Error - The month entered (%02d) is not in the proper range (1-12)\n", mm1);
      exit(1);
   }  
   if ( mm2< 1 || mm2 > 12) {
      printf("Error - The month entered (%02d) is not in the proper range (1-12)\n", mm2);
      exit(1);
   }  
    
   /* Test for the correct day values */
   if ( dd1 < 0 || dd1 > monthLength[mm1-1] ) {
   printf("Error - The day entered (%02d) is not in the proper range (1-%d)\n", dd1, monthLength[mm1-1]); 
   exit(1);
   }

   if ( dd2 < 0 || dd2 > monthLength[mm2-1]) {
   printf("Error - The day entered (%02d) is not in the proper range (1-%d)\n", dd2, monthLength[mm2-2]); 
   exit(1);
   }

   dayOfYear1 = (totalDays[mm1-1] + dd1);
   dayOfYear2 = (totalDays[mm2-1] + dd2);

   if (dayOfYear1 > dayOfYear2) {
      printf("Error - The second date must come after the first chronologically\n");
      exit(0);
   }

   printf("%d\n", (dayOfYear2-dayOfYear1));

   return ( 0 );
}
