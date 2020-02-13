/*Berechnet Durchschnitsnote und Durchfallquote für eine Klausur mit beliebig vielen Arbeiten.
Anschließend werde die Werte aus dem Array gelesen und formatiert in
einer Tabelle ausgegeben werden. 
Marc Cremer 2019*/

#include <stdio.h>	//printf
#include <stdlib.h>	//exit()

int eingaben(char* inputname);
int arr_summe(int arr[],int array_groese);

int main(){	
	int klausurenanzahl;
	int ergebnis[5]=  {0}; /*initialisiert mit 0 */
	double durchschnittsnote; /* Summe der noten/ Anzahl der Klausuren*/
	double durchfallquote	;/* Anzahl der 5-er / Anzahl der Klausuren mal 100*/
	printf("Wieviel Klausuren gibt es?\n");
	klausurenanzahl = eingaben("die Anzahl der Klausuren");
	int klausurergebnis[klausurenanzahl];
	for (int i = 0; i < klausurenanzahl; ++i)
	{

		klausurergebnis[i] = eingaben("die nächste note");
		switch(klausurergebnis[i]){
			case 1: ergebnis[0] +=1;break;
			case 2: ergebnis[1] +=1;break;
			case 3: ergebnis[2] +=1;break;
			case 4: ergebnis[3] +=1;break;
			case 5: ergebnis[4] +=1;break;
			default:printf("Das ist keine valide Note\n");--i;break;/*kann zur endlosschleife werden*/
		}
	}
	durchschnittsnote = arr_summe(klausurergebnis,klausurenanzahl)/klausurenanzahl;
	durchfallquote = ((double)ergebnis[4]/klausurenanzahl) * 100;
	//der finale output. Mit %4i kann ich gleichmaessiges spacing haben
	printf("Der Notenspiegel sieht dann so aus:\n");
	printf("_______________________________________________\n");
	printf("Noten  |   1   |   2   |   3   |   4   |   5   |\nAnzahl |%4i   |%4i   |%4i   |%4i   |%4i   |\n",ergebnis[0],ergebnis[1],ergebnis[2],ergebnis[3],ergebnis[4]);
	printf("_______________________________________________\n");
	printf("Durchschnittsnote:%*.1f\n",4,durchschnittsnote);
	printf("Durchfallquote:%*.2f%%\n", 8,durchfallquote);
	return 0;		
}

int arr_summe(int arr[],int array_groese){
	int sum = 0;
	for (int i = 0; i < array_groese; ++i)
	{
		sum+= arr[i];
	}
	return sum;
}

int eingaben(char* inputname){
	/*returns the entered integer or exits with an error*/
	printf("Bitte %s :",inputname );
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
	} else if ( returnvalue >= 32767 | returnvalue < 1 ) {
	    /* to small */
	    printf("Bitte eine Zahl zwischen 1 und 32767\n");
	    exit(1);
	} else {
	    return returnvalue;  }
}