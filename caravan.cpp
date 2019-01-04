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
#include "stdlib.h"
#include "general.h"
#include "caravan.h"

struct NodeImplementation
{
    PackAnimal animal;
    struct NodeImplementation* next;
};

typedef struct NodeImplementation* Node;

struct CaravanImplementation{
    int length;
    Node head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->length = 0;
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0) {
    Node remove = current;
    current = current->next;
    sfree(remove);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal != 0) {
    Node current = caravan->head;
    Node newNode = (Node)malloc(sizeof(struct NodeImplementation));
    newNode->next = 0;
    newNode->animal = animal;
    if (current == 0) {
      caravan->head = newNode;
    }
    else {
      while (current->next != 0) {
        current = current->next;
      }
      current->next = newNode;
    }
    caravan->length++;
    add_to_caravan(animal, caravan);
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan)
{

}
