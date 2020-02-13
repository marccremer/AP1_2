/*Bubble sort
Sortierd einen random integer array der größe arraygroese aufsteigend nach größe.
Hierzu wird ein bubble-sort Algoritmus verwendet.
Eine kleine Animation spielt um die Sortierung zu zeigen.

Man kann 'anmiationspeed' veraendern um die Geschwindigkeit der Animation zu verändern
Durch die 2 for schleife hat man eine O-notation for O(n^2)
Marc Cremer */

#include <stdio.h>		//printf,scanf
#include <stdlib.h>		//exit()
#include <time.h>		//time() fuer rand()
#include <unistd.h>		//usleep


void tausche(int array[],int element_a,int element_b);									//tausche 2 array elemente
void bubbleanimation(int arr[],int arrgroese,int bubble,int sorted,int animationspeed);	//Animiere das sorting
void printarray(int array[],int arrgroese);												//Ausgabe des Ergebnisses

int main()
{
	srand(time(NULL)); /*initialize a random seed */
	int sorted = 0;
	const int arrgroese = 50;
	int arr[arrgroese];
	int current_bubble;
	int sortedarr[arrgroese];
	int animationspeed = 70000; //how fast in ms the animation is gonna play

	/*initialize array with random numbers */
	for (int i = 0; i < arrgroese; ++i)
	{
		arr[i] = rand() % 100;

	}
	printf("here is the array unsorted:");
	printarray(arr,arrgroese);
	printf(" \n");
	for (int i = 0; i < arrgroese; ++i)
	{
		current_bubble = 0;
		for (int j = 1; j < (arrgroese-sorted); ++j)
		{
			if ( arr[current_bubble] > arr[j])
			{
				tausche(arr,current_bubble,j);
			}
			current_bubble+=1;
			bubbleanimation(arr,arrgroese,current_bubble,sorted,animationspeed);//print next frame of the animation

		}
		sorted+=1;
	}
	/*print result */
	printf("here is the array sorted:");
	printarray(arr,arrgroese);
	printf("\n");

	return 0;
}


void tausche(int array[],int element_a,int element_b){
	int temp = array[element_a];
	array[element_a] = array[element_b];
	array[element_b] = temp;
}

void bubbleanimation(int arr[],int arrgroese,int bubble,int sorted,int speedms){
	//prints 3 columns with the numbers in the middle and filler to the sides
	char filler[]  = " ";
	char filler2[] = "{(";
	char filler3[] = ")}";
	char filler4[] = "><";
	for (int i = arrgroese; i > 0; --i)
	{
		if (i== bubble)
			printf("%*s|%*i|%*s\n",3,filler2,4,arr[i-1],3,filler3 );
		else{
			if (i >= (arrgroese-sorted+1))
			{
				printf("%*s|%*i|%*s\n",3,filler,4,arr[i-1],3,filler4);
			}
			else{
				printf("%*s|%*i|%*s\n",3,filler,4,arr[i-1],3,filler);
			}
		}
	}
	printf("\n");

	for (int i = 0; i < 10; ++i) /*clear screen */
	{
		printf(" \n");
	}
		usleep(speedms);
}

void printarray(int array[],int arrgroese){
	for (int i = 0; i < arrgroese; ++i)
	{

		printf("%i,",array[i] );
	}
}
