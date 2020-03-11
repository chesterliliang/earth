#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/sem.h>
#include "config.h"
#include "def.h"
#include "io.h"


sem_t sem;
UINT8 init_done = 0;
pthread_t thread1;
pthread_t thread2;

void reading(void)
{
    UINT8 *str = "READY";
    UINT8* done = "OK";
    UINT8 response[256] = { 0 };
    UINT8 phrase = 0;
     while(1)
     {
        memset(response,0,256);
        if(prime_read(response, 256)<0)
            return;
        if(phrase==0){
            if(strstr(response,str)){
                sem_post(&sem); //为信号量加1
                phrase++;
            }
        }else if(phrase==1){
            if(strstr(response,done)){
                sem_post(&sem); //为信号量加1
            }
        }
        
    }
}

void exe_task(char* cmd){
    prime_write(cmd, strlen(cmd));
}

int main(void)
{
    UINT32 rv = 0;
    UINT16 l = 0;
    UINT8* cmd = "AT+RST=1\r\n";
    UINT8* cmd1 = "AT+CGATT=1\r\n";
    UINT8* cmd2 = "AT+CGDCONT=1,\"IP\",\"CMNET\"\r\n";
    UINT8* cmd3 = "AT+CGACT=1,1\r\n";
    UINT8* cmd4 = "AT+MQTTCONN=\"39.96.86.85\",1883,\"/clientid\",600,0\r\n";
    UINT8* cmd5 = "AT+HTTPGET=\"http://api.m.taobao.com/rest/api3.do?api=mtop.common.getTimestamp\"\r\n";
    UINT8* cmd6 = "AT+MQTTCONN=\"121.36.3.243\",61613,\"testid12113\",600,0,\"admin\",\"password\"\r\n";
    UINT8* cmd7 = "AT+MQTTPUB=\"/up/post_machine/0x59f252d69712a4261a3eef3cd5fb122911a90254\", \"OK OK OK\", 1,0,0\r\n";
    UINT8* cmd8 ="AT+MQTTSUB=\"/up/post_machine/0x59f252d69712a4261a3eef3cd5fb122911a90254\",1,0\r\n";
    UINT32 th1 = 0;
    UINT32 th2 = 0;
    int i =0;
    sem_init(&sem, 0, 0); //信号量初始化
    // prime_write(cmd, strlen(cmd));
    // usleep(1000000);
    
    
    th1 = pthread_create(&thread1, NULL, (void *)&reading, NULL);
    sem_wait(&sem);
    prime_write(cmd1, strlen(cmd1));
    sem_wait(&sem);
    prime_write(cmd2, strlen(cmd2));
    sem_wait(&sem);
    prime_write(cmd3, strlen(cmd3));
    // sem_wait(&sem);
    // prime_write(cmd4, strlen(cmd4));
    // sem_wait(&sem);
    // prime_write(cmd5, strlen(cmd5));
    sem_wait(&sem);
    prime_write(cmd6, strlen(cmd6));
    sem_wait(&sem);
    prime_write(cmd8, strlen(cmd8));
    while(1){
        i++;
        printf("-----test count %d ------\n",i);
        sem_wait(&sem);
        prime_write(cmd7, strlen(cmd7));
        usleep(5000000);
    }
    

    while(1);
    // int taskNum;
    // while (scanf("%d", &taskNum) != EOF) {
    //     switch (taskNum)
	// 	{
    //         case 1:
    //              rv = prime_write(cmd, cmd_len);
    //         break;
    //         case 2:
    //         break;
    //         default:
    //         break;
    //     }
    // }

    return 0;
}
