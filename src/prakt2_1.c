/* 
Nimmt 5 Integer und gibt aus ob man 1 von 3 Figuren gewuerfelt hat.

Marc Cremer 2019 */

#include <stdio.h>//printf,scanf
#include <string.h>//memset

int has_value(int val,int arr[],int size);//return 1 ,wenn val im array ist sonst 0

int main()
{
	const int wuerfel = 5;
	const int zahlen = 6;
	int ergebnis[wuerfel],poker[zahlen];//poker ist was gewuerfelt wurde

	memset(poker, 0, zahlen*sizeof(poker[0])); //fuellt den array mit lauter Nullen
	printf("Poker Night !!\n");

	for (int i = 0; i < wuerfel; ++i)
		//nimmt din Input und schreibt ihn(wenn valide) in poker[]
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
			//checkt die verschiedenen figuren
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