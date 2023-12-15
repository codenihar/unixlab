#include<stdio.h> 
#include<unistd.h> 
#include<pthread.h> 
#include<stdlib.h>
void* myturn(void *arg)
{
for(int i=1;i<=20;i++)
{
sleep(1);
printf("process 1: i=%d\n",i); }
return NULL; }
void yourturn() {
for(int i=1;i<=10;i++)
{
sleep(2);
printf("process 2: j=%d\n",i); }
}
int main()
{
pthread_t newthread;
pthread_create(&newthread,NULL,myturn,NULL); yourturn();
pthread_join(newthread,NULL);
return 0;
}