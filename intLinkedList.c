#include <stdio.h>
#include <stdlib.h>

#include "intLinkedList.h"


/*
 * Restituisce la lunghezza della lista.
 */
int size(intLinkedList list) {
    int r=0;
    while(list != NULL) {
        r++;
        list = list->next;
    }
    return r;
}


/*
 * Aggiunge un nuovo elemento all'inizio della lista.
 * Restituisce il puntatore aggiornato al primo elemento.
 * Restituisce NULL in caso di errore.
 */
intLinkedList insertAtBeginning(intLinkedList list, int newKey) {
    intLLElement *temp;
    temp = (intLLElement *)malloc(sizeof(intLLElement));
    if(temp != NULL) {
        temp->key = newKey;
        temp->next = list;
        list = temp;
    }
    else
        list = NULL;
    return list;
}


/*
 * Stampa tutti gli elementi della lista a schermo, in un'unica linea, 
 * separandoli con punto e virgola e uno spazio.
 * 
 * Esempio:
 * 1; -2; 3; 4;  
 * 
 */
void printList(intLinkedList list) {
    while(list != NULL) {
        printf("%d; ", list->key);
        list = list->next;
    }
    return;
}


/*
 * Svuota la lista.
 * Restituisce sempre NULL.
 */
intLinkedList empty(intLinkedList list) {
    intLLElement *temp;
    while(list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    return NULL;
}