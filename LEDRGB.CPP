#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

void mode1(int tictoc)
{
 for (int n=0; n<100; n++) { pwmWrite (6,n);
 delay(tictoc);
                           }
 softPwmWrite (6,0);
 for (int n=0; n<100; n++) { softPwmWrite (10,n);
 delay(tictoc);
                           }
 softPwmWrite (10,0);
 for (int n=0; n<100; n++) { softPwmWrite (11,n);
 delay(tictoc);
                           }
 softPwmWrite (11,0);
 delay(tictoc);
 
}

void mode2(int tictoc)
{
 for (int n=0; n<100; n++) { softPwmWrite (6,n);
 delay(tictoc);
                           }
 for (int n=0; n<100; n++) { softPwmWrite (10,n);
 delay(tictoc);
                           }
 for (int n=100; n>0; n--) { softPwmWrite (6,n);
 delay(tictoc);
                           }
 for (int n=0; n<100; n++) { softPwmWrite (11,n);
 delay(tictoc);
                           }
 for (int n=100; n>0; n--) { softPwmWrite (10,n);
 delay(tictoc);
                           }
 for (int n=0; n<100; n++) { softPwmWrite (6,n);
 delay(tictoc);
                           }
 for (int n=0; n<100; n++) { softPwmWrite (10,n);
 delay(tictoc);
                           }
 for (int n=100; n>-1; n--) { 
 softPwmWrite (11,n);
 softPwmWrite (10,n);
 softPwmWrite (6,n);
 delay(tictoc);
                           } 
}


void
signal_callback_handler(int signum)
{

    		FILE *ptr_file;
    		char buf[100];
              char * pch;
    		ptr_file =fopen("LEDRGB.INI","r");
    	//	if (!ptr_file)
        	//	return 1;
              int x=0,flag,tictoc,red,green,blue;
    		while (fgets(buf,100, ptr_file)!=NULL)
        		{//printf("ee%s",buf);
                      //printf("aa %i",atoi(buf));

                      switch (x){
                           case 0:
                                 //modo
                                flag=atoi(buf);
                                 break;
                           case 1:
                                 //delay ms
                                 tictoc=atoi(buf);                                 break;
                           case 2:
                                 //led red
                                 red=atoi(buf);
                                 break;
                           case 3:
                                 //led green
                                 green=atoi(buf);
                                 break;
                           case 4:
                                 //led blue
                                 blue=atoi(buf);
                                 break;
                                }
                      x++;
                     }
		fclose(ptr_file);
              //printf("modo1 %i zzz",flag);
                       switch (flag){
                           case 0:
                                 printf("%i %i %i",red,blue,green);
                                 softPwmWrite(11,blue);
                                 softPwmWrite(10,green);
                                 softPwmWrite(6,red);
                                 break;
                           case 1:
                                 printf("modo1");
                                 mode1(tictoc);                                 break;
                           case 2:
                                 printf("modo2"); 
                                 mode2(tictoc);
                                 break;
                           }                            } 


int main()
{
  wiringPiSetup();
  softPwmCreate (6,0,100) ;
  softPwmCreate (10,0,100) ;
  softPwmCreate (11,0,100) ;
  softPwmWrite (0, 1) ; 
  softPwmWrite(11,0);
  softPwmWrite(10,0);
  softPwmWrite(6,0);   // Register signal and signal handler
   signal(SIGUSR1, signal_callback_handler);

   while(1)
   {
 //printf ("The current path is: %s",getenv ("PATH"));
   }
   return EXIT_SUCCESS;
}

          
