/********************************************************************************
* car.h: Inneh�ller strukt f�r car-objekt och diverse funktionsdeklarationer.
********************************************************************************/
#ifndef CAR_H_
#define CAR_H_

/* Inkluderingsdirektiv */
#include <stdio.h>
#include <stdlib.h> 

/* Antalet Bliobjekt */
#define NUM_CARS 3

/* Enumerationer */
enum car_transmission { NONE, MANUAL, AUTOMATIC };

/********************************************************************************
* car_t: Strukt inneh�llande M�rke, Modell, F�rg, Lanserings�r och V�xell�da
*        samt pekare till ett vtable.
********************************************************************************/
typedef struct
{
    char* brand;
    char* model;
    char* color;
    int year_of_launch;
    enum car_transmission transmission;
    struct car_vtable* vptr;
}car_t;

/********************************************************************************
* car_vtable: Vtable f�r funktionspekare.
********************************************************************************/
struct car_vtable
{
    void (*print)(car_t* self, FILE* ostream);
    void (*change_color)(car_t* self, char* color);
    void (*change_transmission)(car_t* self);
};

/********************************************************************************
* car_init: Initierar ett nytt car-objekt samt s�tter vptr till att peka p�
*           vtablet.
*
*
*           -self:           Pekare till bilen som skall initieras.
*
*           -brand:          BilM�rke
*
*           -color:          Bilens F�rg
*
*           -model:          Bilens Modell
*
*           -year_of_launch: Bilens Lanserings�r.
*
*           -transmission:   Bilens V�xell�da.
********************************************************************************/
void car_init(car_t * self,
              char* brand,
              char* color,
              char* model,
              int year_of_launch,
              enum car_transmission transmission);

/********************************************************************************
* car_clear: Rensar/nollst�ller car-objekt.
*
*
*            -self: Pekare till car-objekt som skall nollst�llas.
********************************************************************************/
void car_clear(car_t* self);

/********************************************************************************
* car_new: Skapar och frig�r minne f�r ett nytt car-objekt, returnerar 1 vid
*          misslyckad minnesallokering och returnerar skapat car-objekt vid
*          lyckad minnesallokering.
*
*
*           -self:           Pekare till det nya car-objektet.
*
*           -brand:          BilM�rke
*
*           -color:          Bilens F�rg
*
*           -model:          Bilens Modell
*
*           -year_of_launch: Bilens lLanserings�r.
*
*           -transmission:   Bilens V�xell�da.
********************************************************************************/
car_t* car_new(car_t* self,
               char* brand,
               char* color,
               char* model,
               int year_of_launch,
               enum car_transmission transmission);

/********************************************************************************
* car_delete: Tar bort/raderar valt car-objektet och frig�r minnet.
*
*
*             -self: Perkare till car-objektet.
********************************************************************************/
void car_delete(car_t* self);

/********************************************************************************
* car_print: Skriver ut car-objekt.
*
*
*             -self: Perkare till car-objektet.
*
*             -FILE: Filpekare
********************************************************************************/
void car_print(car_t* self,
               FILE* ostream);

/********************************************************************************
* car_change_color: �ndrar f�rg p� angivet car-objekt.
*
*
*                   -self: Perkare till car-objektet.
*
*                   -color: Angiven ny f�rg.
********************************************************************************/
static void car_change_color(car_t* self,
                             char* color);

/********************************************************************************
* car_change_transmission: �ndrar v�xell�da p� angivet car-objekt.
*
*
*                          -self: Perkare till car-objektet.
*
*                          -transmission: Angiven ny v�xell�da.
********************************************************************************/
static void car_change_transmission(car_t* self,
                                    enum car_transmission transmission);

#endif // !CAR_H_

