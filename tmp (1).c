#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void *func(void* arg) // fun execute by all thread.
{
    //sleep(10); // all thread sleep for 10 sec
    int* new = (int*) arg; // stored the value agu passed to the tread.
    printf("Thread Running %d\n",*new); // print
    free(new); // to free memory
    return NULL;
}

int main()
{
    pthread_t shivani[5];

    int a  = 10;
    for(int i=0;i<5;++i) // create 5 thraed.
    {
        int* tmp = malloc(sizeof(int)); //intialize the memory 
        *tmp = i;                
        pthread_create(&shivani[i], NULL, func, tmp); // create thread
    }
    for(int i=0;i<5;++i)
    {
        pthread_join(shivani[i], NULL); // wait untill all thread execute.
    }

    return
}