#include <stdio.h>    // Standard I/O
#include <stdlib.h>   // Standard library
#include <unistd.h>   // Unix Standard
#include <pthread.h>  // POSIX thread library

#include "util_queue.h"

#define NUM_THREADS 50

/*
 * DEFINIR las variables globales necesarias (cola de trabajos, semáforos, etc) 
 */





/*
 * IMPLEMENTAR el código de la función de los threads 'Sender' 
 */
void* pthread_sender_job(int id) {
 
  
  
  
  
  
}


/*
 * IMPLEMENTAR el código de la función del thread 'Printer' 
 */
void* pthread_printer_job(int id) {
  
  
  
  
  
  
  
  
}

/*
 * Main
 */
int main(int argc,char** argv) {
  
 /* DEFINIR las variables locales del main necesarias y el CÓDIGO de la inicialización de la cola de trabajos 
   * y de los semáforos utilizados en el programa  
   */
 
 
 
 
  /*CÓDIGO para la creación del thread 'Printer'*/
 
  
  
  
  /*CÓDIGO para la creación de los threads 'Sender'*/
 
    
  
  
  
   /*CÓDIGO de la espera de la finalización de los threads 'Sender'*/
  
  
   .
  /*CÓDIGO envío a la cola de impresión del trabajo que identifica el fin de impresión'*/
      
    
   
   /*CÓDIGO de la espera de la finalización del thread 'Printer'*/
   
   
   
 
  return 0;
}

