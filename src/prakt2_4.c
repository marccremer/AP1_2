/*Bubble sort
Schreiben Sie ein C-Programm, das eine Liste ganzer Zahlen aufsteigend sortiert.
Implementieren sie hierzu den Bubblesort-Algorithmus. Der Algorithmus vergleicht immer
zwei nebeneinander liegende Elemente und vertauscht die beiden, falls das rechte kleiner ist als
das linke. Der Name kommt daher, dass die großen Werte wie Blasen aufsteigen und nach
rechts wandern. Definieren Sie, wie in der Vorlesung gezeigt, die Größe des Arrays als
Konstante. Überlegen Sie sich, welche Komplexität der Algorithmus hat (O-Notation).
Marc Cremer */

#include <stdio.h>
#include <stdlib.h>

void tausche(int array[],int element_a,int element_b);

int main()
{
	//fang links an
	//vergleiche 2
	//if
	//a > b
	//_tausche
	//gehe 1 weiter
	//if ende
	//starte neu und setzte ende -1
	int sorted = 0;
	const int arrgroese = 9;
	int arr[arrgroese];
	int current_bubble;
	/*initialize array with i*i */
	for (int i = 0; i < arrgroese; ++i)
	{
		arr[i] = i* 2*5*7*7;
	}
	for (int i = 0; i < arrgroese; ++i)
	{
		current_bubble = 0;
		for (int j = 0; j < (arrgroese-sorted); ++j)
		{
			if ( arr[current_bubble] > arr[j])
			{
				tausche(arr,current_bubble,j);
			}
		}
	}

	//print
	
	printf("here is the array:");
	for (int i = 0; i < arrgroese; ++i)
	{
		
		printf("%i,",arr[i] );
	}
	printf("\n");
	return 0;
}

/*
void bubblesort(int arr[],int arrgroese){

}
*/

void tausche(int array[],int element_a,int element_b){
	int temp = array[element_a];
	array[element_a] = array[element_b];
	array[element_b] = temp;
}