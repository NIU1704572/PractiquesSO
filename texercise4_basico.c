
#include <stdio.h>    // Standard I/O
#include <stdlib.h>   // Standard library
#include <unistd.h>   // Unix Standard
#include <pthread.h>  // POSIX thread library

#include "util_queue.h"
#include "util_queue.c"

#define NUM_THREADS 50

/*
 * DEFINIR las variables globales necesarias (cola de trabajos, semáforos, etc) 
 */

pthread_mutex_t mutex;
printer_buffer_t buffer;


/*
 * IMPLEMENTAR el código de la función de los threads 'Sender' 
 */
void* pthread_sender_job(int id) {
  
  pthread_mutex_lock(&mutex);
  
  char file_path[100] = "File nº";
  printing_job_t* job = printing_job_create(file_path);
  job->job_id=id;
  printer_buffer_queue(&buffer, job);
  
  
  
  pthread_mutex_unlock(&mutex);
}


/*
 * Main
 */
int main(int argc,char** argv) {
  
  /* DEFINIR las variables locales del main necesarias y el CÓDIGO de la inicialización de la cola de trabajos 
   * y de los semáforos utilizados en el programa  
   */
 printer_buffer_init(&buffer);

  
  /*CÓDIGO para la creación de los threads 'Sender'*/
  pthread_t thread[50];
  for (int i=0; i<50;i++)
  {
  	pthread_create(&thread[i],NULL,(void* (*)(void*))pthread_sender_job,(i+1));
  }
  
  
  
  
  /*CÓDIGO de la espera de la finalización de los threads 'Sender'*/
  for (int i=0; i<50;i++)
  {
  	 pthread_join(thread[i],NULL);
  }
  
  
  
  
  /*CÓDIGO para imprimir todos los trabajos de la cola de impresión*/
  while (printer_buffer_empty(&buffer)==0)
  {
  printing_job_t job=buffer.jobs[buffer.next_job_dequeue];
  printf("%s %d\n",job.file_path,job.job_id);
  printer_buffer_dequeue(&buffer, &job);
  }
  
  
    
  return 0;
}

