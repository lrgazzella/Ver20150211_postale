#include <stdio.h>
#include <stdlib.h>

#include "intLinkedList.h"


/*
 * Restituisce la lunghezza della lista.
 */
int size(intLinkedList list) {
    int r=0;

    while(list != NULL){
        r++;
        list = list->next;
    }
    
    return r;
} //-1


/*
 * Aggiunge un nuovo elemento all'inizio della lista.
 * Restituisce il puntatore aggiornato al primo elemento.
 * Restituisce NULL in caso di errore.
 */
intLinkedList insertAtBeginning(intLinkedList list, int newKey) {
    
    intLinkedList  nuovo;
    nuovo = (intLinkedList)malloc(sizeof(intLinkedList));
    
    intLinkedList returnValue;
    
    if(nuovo != NULL){
        nuovo->next = list;
        nuovo->key = newKey;
        list = nuovo; 
        returnValue = list;
    }else{
        returnValue=NULL;
    }
    
    return returnValue;
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
    int totale=0;
    totale = size(list);
    
    int i=0;
    
    for(i=0; i<totale; i++){
        printf("%d; ", list->key);
        list = list->next;
    }
    
    
    return;
} //-1


/*
 * Svuota la lista.
 * Restituisce sempre NULL.
 */
intLinkedList empty(intLinkedList list) {
    
    intLinkedList elimina;
    while(list != NULL) {
        elimina = list;
        list = list->next;
        free(elimina);
    }
    
    return NULL;
} //-1