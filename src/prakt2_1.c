/* 
Sie spielen ein Würfelspiel mit 5 Würfeln. Schreiben Sie ein C-Programm, das aus 5
eingelesenen Augenpoker ermittelt, ob eine der folgenden Figuren gewürfelt wurde und wenn
ja, welche.
Grand gleiche Augenzahl auf allen 5 Würfeln
Poker gleiche Augenzahl auf 4 Würfeln
Full House 3 gleiche und 2 gleiche Augenzahlen
Marc Cremer 2019
 */

#include <stdio.h>
#include <string.h>

int has_value(int val,int arr[],int size);

int main()
{
	const int wuerfel = 5;
	const int zahlen = 6;
	int ergebnis[wuerfel],poker[zahlen];

	memset(poker, 0, zahlen*sizeof(poker[0]));
	printf("Poker Night !!\n");
	for (int i = 0; i < wuerfel; ++i)
		{
			printf("Würfel %i: ", i+1);
			scanf("%i",&ergebnis[i]);
			if (ergebnis[i] > 0 && ergebnis[i] < 7)
			{
				printf("ok\n");
			}else{
				printf("please enter a valid number(1-6)\n");
				i = i -1;
			}
			poker[ergebnis[i]]+=1;
		}
		if (has_value(5,poker,zahlen))
		{
			printf("you won: Grand\n");
		}
		else if (has_value(4,poker,zahlen))
		{
			printf("you won: Poker\n");
			}
		else if (has_value(3,poker,zahlen) && has_value(2,poker,zahlen)){
			printf("you won: Full House\n");
		}
		else {
			printf("You lost\n");
		}
	


	return 0;
}

int has_value(int val,int arr[],int size){
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == val)
		{
			return 1;
		}
	}
	return 0;

}