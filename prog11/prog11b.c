#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Thread function 1 
void *_myNewThread(void* vargp){
  printf("Hello world\n"); 
  return NULL;
}

// Thread function 2
void *_myThreadFun(void* vargp) {

  int* myid = (int*)vargp; 
  
  printf("%p %d", pthread_self(), *myid);
  
  pthread_t maint_id = pthread_self();
  
  if(pthread_equal(maint_id, *myid)) {
    printf("main thread encountered\n");
    
    pthread_t nid;
    int i,j;
    for(i = 0; i < 5; i++) {
      for(j = 0; j < 5; j++) {
        pthread_create(&nid, NULL, _myNewThread, (void*)&nid); 
      }
    }
  }

  return NULL; 
}

int main() {

  pthread_t tid;
  int i;

  for(i = 0; i < 2; i++) {
    pthread_create(&tid, NULL, _myThreadFun, (void*)&tid); 
  }

  pthread_exit(NULL);
  
  return 0;
}