/********************************************************************************
* car.c: Innehåller diverse funktionsdefinitioner.
********************************************************************************/

/* Inkluderingsdirektiv */
#include "car.h"

/* Funktionsdeklaration */
static struct car_vtable* car_vptr_get(void);

/********************************************************************************
* car_init: Initierar ett nytt car-objekt samt sätter vptr till att peka på
*            vtablet.
*
*
*           -self:           Pekare till bilen som skall initieras.
*
*           -brand:          BilMärke
*
*           -color:          Bilens Färg
*
*           -model:          Bilens Modell
*
*           -year_of_launch: Bilens Lanseringsår.
*
*           -transmission:   Bilens Växellåda.
********************************************************************************/
void car_init(car_t* self,
	          char* brand,
	          char* color,
	          char* model,
	          int year_of_launch,
	          enum car_transmission transmission)
{
	self->brand = brand;
	self->color = color;
	self->model = model;
	self->year_of_launch = year_of_launch;
	self->transmission = transmission;
	self->vptr = car_vptr_get();

	return;
}

/********************************************************************************
* car_clear: Rensar/nollställer car-objekt.
*
*
*            -self: Pekare till car-objekt som skall nollställas.
********************************************************************************/
void car_clear(car_t* self)
{
	self->brand = NULL;
	self->model = NULL;
	self->color = NULL;
	self->year_of_launch = 0;
	self->transmission = NONE;
	return;
}

/********************************************************************************
* car_new: Skapar och frigör minne för ett nytt car-objekt, returnerar 1 vid
*          misslyckad minnesallokering och returnerar skapat car-objekt vid
*          lyckad minnesallokering.
*
*
*           -self:           Pekare till det nya car-objektet.
*
*           -brand:          BilMärke
*
*           -color:          Bilens Färg
*
*           -model:          Bilens Modell
*
*           -year_of_launch: Bilens lLanseringsår.
*
*           -transmission:   Bilens Växellåda.
********************************************************************************/
car_t* car_new(car_t* self,
	           char* brand,
	           char* color,
	           char* model,
	           int year_of_launch,
	           enum car_transmission transmission)
{
	car_t* car = (car_t*)malloc(sizeof(car_t));
	if (self == NULL) return 1;
	car_init(car, brand, model, color, year_of_launch, transmission);
	return car;
}

/********************************************************************************
* car_delete: Tar bort/raderar valt car-objektet och frigör minnet.
*
*
*             -self: Perkare till car-objektet.
********************************************************************************/
void car_delete(car_t* self)
{
	car_clear(self);
	free(self);
	self = NULL;
	return;
}

/********************************************************************************
* car_print: Skriver ut car-objekt.
*
*
*             -self: Perkare till car-objektet.
*
*             -FILE: Filpekare
********************************************************************************/
void car_print(car_t* self,
	           FILE* ostream)
{
	if (ostream == NULL) ostream = stdout;

	fprintf(ostream, "------------------------------------------------------------------\n");
	fprintf(ostream, "Brand: %s\n", self->brand);
	fprintf(ostream, "Model: %s\n", self->model);
	fprintf(ostream, "Color: %s\n", self->color);
	fprintf(ostream, "Year of launch: %d\n", self->year_of_launch);
	switch (self->transmission)
	{
	case MANUAL:
		fprintf(ostream, "Transmission: Manual\n");
		break;
	case AUTOMATIC:
		fprintf(ostream, "Transmission: Automatic\n");
		break;
	}
	fprintf(ostream, "------------------------------------------------------------------\n");
	fprintf(ostream, "\n");

	return;
}

/********************************************************************************
* car_change_color: Ändrar färg på angivet car-objekt.
*
*
*                   -self: Perkare till car-objektet.
*
*                   -color: Angiven ny färg.
********************************************************************************/
static void car_change_color(car_t* self,
	                         char* color)
{
	self->color = color;
	return;
}

/********************************************************************************
* car_change_transmission: Ändrar växellåda på angivet car-objekt.
*
*
*                          -self: Perkare till car-objektet.
*
*                          -transmission: Angiven ny växellåda.
********************************************************************************/
static void car_change_transmission(car_t* self,
	                                enum car_transmission transmission)
{
	if (self->transmission == MANUAL)
	{
		self->transmission = AUTOMATIC;
	}
	else
	{
		self->transmission = MANUAL;
	}
	return;
}

/********************************************************************************
* car_vptr_get: Sätter funktionspekarna att peka på respektive funktioner.
********************************************************************************/
static struct car_vtable* car_vptr_get(void)
{
	static struct car_vtable self =
	{
		.change_color = &car_change_color,
		.change_transmission = &car_change_transmission,
		.print = &car_print
	};
	return &self;
}