#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
#include <unistd.h>
#include <syslog.h>

//#include <stdlib.h>

#define	Lamp	26

int main (void)
{
  printf ("Banana Pi blink\n") ;
	//struct timespec spec;
  time_t t = time(NULL);
  struct tm *tm_struct = localtime(&t);
  int hour = tm_struct->tm_hour;
	//hour = 23;
	typedef struct {
  	int start_hour;
  	int close_hour;
	}SITE;
	SITE PJU;
	PJU.start_hour = 6;
	PJU.close_hour = 18;
	
	printf("%d\n",hour);

  //wiringPiSetupGpio () ;
  wiringPiSetup () ;
  pinMode (Lamp, OUTPUT) ;

	openlog("Lamp_io", LOG_PID|LOG_CONS, LOG_USER);
  while(1)
	{
		/*if(hour < PJU.start_hour || hour > PJU.close_hour){
    	digitalWrite (Lamp, HIGH) ;	// On
			printf("Turn on lamp\n");
			syslog(LOG_INFO, "Turn on lamp\n");
		}*/
    //delay (500) ;		// mS
		if(hour > PJU.start_hour && hour < PJU.close_hour){
 	  	digitalWrite (Lamp, LOW) ;	// Off
			printf("Turn off lamp\n");
			syslog(LOG_INFO, "Turn off lamp\n");
		}
		else{
    	digitalWrite (Lamp, HIGH) ;	// On
			printf("Turn on lamp\n");
			syslog(LOG_INFO, "Turn on lamp\n");
		}
		sleep(60);
   // delay (500) ;
  }
	closelog();
  return 0 ;
}
