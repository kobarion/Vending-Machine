#include <stdio.h>
#include <stdlib.h>
#include <pthresad.h>
#include <iostream>

void *task(void *argument){
    char* msg;
    msg = (char*)argument;
    std::cout<<msg<<std::endl;
}

int main(){
    pthread_t thread1, thread2;
    int i1,i2;
    i1 = pthread_create( &thread1, NULL, task, (void*) "thread 1");
    i2 = pthread_create( &thread2, NULL, task, (void*) "thread 2");

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}