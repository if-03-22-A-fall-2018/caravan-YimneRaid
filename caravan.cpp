/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include "stdlib.h"
#include "general.h"
typedef struct Node{
  PackAnimal pack_animal;
  struct Node* next;
}Node;

struct CaravanImplementation{
  Node* head;
};

struct PackAnimalImplementation {
	AnimalType type;
	const char *name;
	int max_speed;
	int load;
	Caravan caravan;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count=0;
  Node* currentnode=caravan->head;
  while(currentnode!=0){
    currentnode=currentnode->next;
    count ++;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  int caravanLength=get_length(caravan);
  for ( int i = 0; i < caravanLength; i++) {
    Node* head=caravan->head;
    caravan->head=head->next;
    sfree(caravan->head);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (animal==0) {
    return;
  }
  else
  {
    if (get_caravan(animal)!=0) {
      remove_from_caravan(animal,get_caravan(animal));
    }
    
  }

  return;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  return;
}

int get_caravan_load(Caravan caravan)
{
  return get_length(caravan);
}

void unload(Caravan caravan)
{
  return;
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}
