#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <iostream>
using namespace std;
void *my_thread_function (void *arg);

int i,n,j;

int main()
{
pthread_t my_thread;

pthread_create(&my_thread,NULL,my_thread_function,NULL); //Thread is created
pthread_join(my_thread,NULL); //this waits for the thread to finish

printf("Inside Main Program\n");

for(j=20;j<25;j++)
{
printf("%d\n",j);

sleep(1);}

return 1;
}


void *my_thread_function(void *arg)
{
//cout<<"Inside Thread"<<endl;
printf("Inside Thread\n");

for(i=0;i<5;i++)
{
//cout<<i<<endl;
printf("%d\n",i);
sleep(1);}

pthread_exit(0);
}
