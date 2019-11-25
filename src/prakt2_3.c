/*Eine Klausur wurde geschrieben. Prof. Algo Rithmus hat sie bewertet und muss nun noch den
Notenspiegel, die Durchschnittsnote und die Durchfallquote ausgeben. Durchgefallen ist, wer
eine 5 bekommen hat. (Es gibt nur die Noten 1 bis 5).
Schreiben Sie ein C-Programm, das per Benutzereingabe die Anzahl der jeweiligen Noten in
ein Array speichert. Anschließend sollen die Werte aus dem Array gelesen und formatiert in
einer Tabelle ausgegeben werden. 
Marc Cremer 2019*/

#include <stdio.h>
#include <stdlib.h>

int eingaben(char* inputname);
int arr_summe(int arr[],int array_groese);

int main(){	
	int klausurenanzahl;
	int ergebnis[5]=  {0};
	double durchschnittsnote; /* Summe der noten/ Anzahl der Klausuren*/
	double durchfallquote	;/* Anzahl der 5-er / Anzahl der Klausuren mal 100*/
	printf("Wieviel klaus gibt es?\n");
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
	//printf("%i\n", durchschnittsnote);
	//printf("Die Durschnittsnote is %4.2f und die Durchfallquote ist %4.2f %%  \n",durchschnittsnote,durchfallquote );
	printf("Der Notenspiegel sieht dann so aus:\n");
	printf("_______________________________________________\n");
	printf("Noten  |   1   |   2   |   3   |   4   |   5   |\nAnzahl |%4i   |%4i   |%4i   |%4i   |%4i   |\n",ergebnis[0],ergebnis[1],ergebnis[2],ergebnis[3],ergebnis[4]);
	printf("_______________________________________________\n");
	/*Durchschnittsnote: 2.9 (als Beispielwert)
Durchfallquote: 52.5 % (als Beispielwert)*/
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