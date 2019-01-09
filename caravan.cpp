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
    if(get_caravan(animal) != 0 && get_caravan(animal) != caravan){
        remove_pack_animal(get_caravan(animal), animal);
    }
    Node current = caravan->head;
    Node newNode = (Node)malloc(sizeof(struct NodeImplementation));
    newNode->next = 0;
    newNode->animal = animal;
    if(caravan->head == 0)
    {
      caravan->head = newNode;
    }
    else
    {
      while(current->next != 0) {
        if(current->animal == animal) {
          return;
        }
        current = current->next;
      }
      if(current->animal == animal) {
        return;
      }
      current->next = newNode;
    }
    caravan->length++;
    add_to_caravan(animal, caravan);
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  bool found = false;
  Node current = caravan->head;
  Node toRemove = (Node)malloc(sizeof(NodeImplementation));
  toRemove->next = 0;

  if (caravan->head != 0 && caravan->head->animal == animal) {
    caravan->head = caravan->head->next;
    remove_from_caravan(animal, caravan);
    caravan->length--;
    sfree(current);
    return;
  }

  while (current->next != 0 && !found) {
    if (current->next->animal == animal) {
      found = true;
      toRemove = current->next;
      current->next = toRemove->next;
      remove_from_caravan(animal, caravan);
      caravan->length--;
      sfree(toRemove);
    }
    else {
      current = current->next;
    }
  }
}

int get_caravan_load(Caravan caravan)
{
  int load = 0;
  Node current = caravan->head;
  while(current!=0)
  {
    load += get_load(current->animal);
    current = current->next;
  }
  return load;
}

void unload(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0) {
    unload(current->animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan)
{

}

bool animal_unique(Caravan caravan, PackAnimal animal)
{
  if (caravan->head == 0) {
    return false;
  }
  bool isUnique = true;
  Node current = caravan->head;

  while (current->next != 0 && isUnique) {
    if (current->animal == animal) {
      isUnique = false;
    }
    else {
      current = current->next;
    }
  }
  return isUnique;
}
