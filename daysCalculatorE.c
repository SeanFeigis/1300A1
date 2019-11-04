#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *   Program name: daysCalculatorE
 *   Author: Sean Feigis
 *   Last Update: September 25, 2019
 *   Function: to find the number of days between 2 dates
 *   Compilation: gcc -ansi -o daysCalculatorE daysCalculatorE.c
 *   Execution: ./daysCalculatorE 23-8-2019 25-9-2019 (include)
 */

int main ( int argc, char *argv[] ) {

   /* The number of days in each month */
   int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   /* Total days of the year up until each month */
   int totalDays1[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
   int totalDays2[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

   /* Information about the dates */
   char strdd1[3] = "";
   char strdd2[3] = "";
   int dd1 = 0;
   int dd2 = 0;
   char strmm1[3] = "";
   char strmm2[3] = "";
   int mm1 = 0;
   int mm2 = 0;
   char stryyyy1[5] = "";
   char stryyyy2[5] = "";
   int yyyy1 = 0;
   int yyyy2 = 0;
   int leap = 0;
   int dayOfYear1 = 0;
   int dayOfYear2 = 0;

   int i = 0;

   /*Time code taken from www.tutorialspoint.com/c_standard_library/c_function_strftime.htm */

   time_t rawtime;
   struct tm *info;
   char today[9];

   time ( &rawtime);

   info = localtime( &rawtime);

   strftime(today, 11,"%m/%d/%Y", info);

   /* Test for correct input */
   if ( argc < 3 ) {
      printf ( "Usage: ./daysCalculatorE dd1-mm1-yyyy1 dd2-mm2-yyyy2 (include)\n" );
      exit ( 1 );
   } else {  
            
      strdd1[0] = argv[1][0];
      strdd1[1] = argv[1][1];
      strdd1[2] = '\0';
      strmm1[0] = argv[1][3];
      strmm1[1] = argv[1][4];
      strmm1[2] = '\0';
      stryyyy1[0] = argv[1][6];
      stryyyy1[1] = argv[1][7];
      stryyyy1[2] = argv[1][8];
      stryyyy1[3] = argv[1][9];
      stryyyy1[4] = '\0';

      strdd2[0] = argv[2][0];
      strdd2[1] = argv[2][1];
      strdd2[2] = '\0';
      strmm2[0] = argv[2][3];
      strmm2[1] = argv[2][4];
      strmm2[2] = '\0';
      stryyyy2[0] = argv[2][6];
      stryyyy2[1] = argv[2][7];
      stryyyy2[2] = argv[2][8];
      stryyyy2[3] = argv[2][9];
      stryyyy2[4] = '\0';
      
   }

   if (strcmp("today", argv[1]) == 0) {
      strdd1[0] = today[3];
      strdd1[1] = today[4];
      strmm1[0] = today[0];
      strmm1[1] = today[1];
      stryyyy1[0] = today[6];
      stryyyy1[1] = today[7];
      stryyyy1[2] = today[8];
      stryyyy1[3] = today[9];
   }

   if (strcmp("today", argv[2]) == 0) {
      strdd2[0] = today[3];
      strdd2[1] = today[4];
      strmm2[0] = today[0];
      strmm2[1] = today[1];
      stryyyy2[0] = today[6];
      stryyyy2[1] = today[7];
      stryyyy2[2] = today[8];
      stryyyy2[3] = today[9];
   }
  
   mm1 = atoi (strmm1);
   mm2 = atoi (strmm2);
   dd1 = atoi (strdd1);
   dd2 = atoi (strdd2);
   yyyy1 = atoi (stryyyy1);
   yyyy2 = atoi (stryyyy2);

   /* Test for the correct month values */
   if ( mm1 < 1 || mm1 > 12 ) {
      printf("Error - The month entered (%d) is not in the proper range (1-12)\n", mm1);
      exit(1);
   }  
   if ( mm2< 1 || mm2 > 12) {
      printf("Error - The month entered (%d) is not in the proper range (1-12)\n", mm2);
      exit(1);
   }  
    
   /*Test for the correct day values */
   if ( dd1 < 0 || dd1 > monthLength[mm1-1] ) {
   printf("Error - The day entered (%d) is not in the proper range (1-%d)\n", dd1, monthLength[mm1-1]); 
   exit(1);
   }

   if ( dd2 < 0 || dd2 > monthLength[mm2-1]) {
   printf("Error - The day entered (%d) is not in the proper range (1-%d)\n", dd2, monthLength[mm2-2]); 
   exit(1);
   }

   if ( yyyy1 % 100 == 0 ) {
      if ( yyyy1 % 400 == 0 && yyyy1 % 4 == 0) {
         for (i = 2; i < 12; i++) 
         {
            totalDays1[i]++;
         }
      }
   }  else if ( yyyy1 % 4 == 0) { 
         for (i = 2; i < 12; i++) 
         {
            totalDays1[i]++;
         }
   } 

    if ( yyyy2 % 100 == 0 ) {
      if ( yyyy2 % 400 == 0 && yyyy2 % 4 == 0) {
         for (i = 2; i < 12; i++) 
         {
            totalDays2[i]++;
         }
      }
   }  else if ( yyyy2 % 4 == 0) { 
         for (i = 2; i < 12; i++) 
         {
            totalDays2[i]++;
         }
   } 
   
   dayOfYear1 = (totalDays1[mm1-1] + dd1);
   dayOfYear2 = (totalDays2[mm2-1] + dd2);

   int yeardifference = 0;
   
   /*Add 365 day for every year difference */
   if (yyyy2 > yyyy1) {
      yeardifference = (yyyy2 - yyyy1);
      dayOfYear2+=(yeardifference * 365);

      for(yyyy1; yyyy1 < yyyy2; yyyy1++) {
      if ( yyyy1 % 100 == 0 ) {
         if ( yyyy1 % 400 == 0 && yyyy1 % 4 == 0) {
            dayOfYear2++;
         }
      }  else if ( yyyy1 % 4 == 0) { 
         dayOfYear2++;
         } 
      }
   }
 
   /* Test for include */
   if (argc == 4 ) {
      if (strcmp("include", argv[3]) == 0 ) {
         dayOfYear2++;
      }
   }

   /*Test for correct input*/
   if (dayOfYear1 > dayOfYear2) {
      printf("Error - The second date must come after the first chronologically\n");
      exit(0);
   }

   printf("%d\n", (dayOfYear2-dayOfYear1));

   return ( 0 );
}
