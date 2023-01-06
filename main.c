/********************************************************************************
* main.c: Program f�r att skriva ut bilmodeller och annan viktig information
*         om dessa.
********************************************************************************/
#include "car.h"
#include "file_read.h"

int main(void)
{
	/* Definition av 3 car-objekt */
	car_t car1, car2, car3;

	/* Initiering av car-objekt */
	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia", "White", 2003, MANUAL);

	/* Array inneh�llande samtliga car-objekt */
	car_t* cars[] = { &car1, &car2, &car3 };

	/* Byter f�rg p� car1 till gul och v�xell�da till automat. */
	car1.vptr->change_color(&car1, "Yellow");
	car1.vptr->change_transmission(&car1, AUTOMATIC);
	
	/* �ppnar/skapar en textfil d�pt "cars.txt" */
	FILE* ostream = fopen("cars.txt", "a");

	/* Samtliga car-objekt skrivs till angiven fil */
	for (int i = 0; i < NUM_CARS; i++)
	{
		car_print(cars[i], ostream);
	}

	/* Filen st�ngs */
	fclose(ostream);

	/* Inneh�llet ur filen "cars.txt" l�ses och skrivs ut i terminalen. */
	file_read("cars.txt");

	return 0;
}