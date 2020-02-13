/* Programm das die Primzahlen von 2 bis zu maximal 1000 ausgibt.
Da wir hier 3 Schleifen haben wobei 2 eineinander liegen  die schlechter zahlen finden
je mehr zahlen sie gefunden haben gehört das Programmzur O(N log (log N))
Marc Cremer 2019
 */
#include <stdio.h> 	//printf
#include <math.h>	//sqrt
#include <stdlib.h>	//exit()

int eingaben(char* inputname); //handelt korrekt inputs



int main()
{	
	int start = 2;	//wir starten bei 2
	int ende;		//bis wohin	
	int ostatus =0;	//kann man nutzen fuer die Wachstumsermittlung

	ende = eingaben("bis wo hin wir rechnen sollen");
	const int arrsize = ende+1;
	int numbers[arrsize];	
	double nsq = sqrt((double)ende);

	for (int i = 2; i <= ende; ++i)
	{
		numbers[i] = 0;
		ostatus+=1;
	}
	for (int i = 2; i <= nsq; ++i)
	{
		if (numbers[i] == 0)
		{
			numbers[i] = 0;
			for (int j = i*i; j <= ende; j=j+i)
			{
				numbers[j] = 1;
				ostatus+=1;
			}
		}
	}

	for (int i = start; i < ende; ++i)
	{
		if (numbers[i] == 0)
		{
			printf("Die nummer %4i ist eine Primezahl\n",i );
			ostatus+=1;
		}
	}
	return 0;
}


int eingaben(char* inputname){
	/*returns the entered integer or exits with an error*/
	printf("Bitte %s(3-1000) :",inputname );
	int returnvalue;
	int nitems;
	nitems = scanf( "%i",  &returnvalue);
	if (nitems == EOF) {
	    /* no input */
	    printf("End of file was reached while nothing was read\n" );
	} else if (nitems == 0 ) {
	    /* no integers was given */
	    printf("Bitte nur ganze Zahlen\n");
	    exit(1);
	} else if ( returnvalue < 2 | returnvalue > 1000 ) {
	    /* to small or to big*/
	    printf("Bitte eine Zahl zwischen 3 und 1001\n");
	    exit(1);
	} else {
	    return returnvalue;  
	}
}