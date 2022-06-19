#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<unistd.h>
void main(){
struct{
int type;
char text[100];
}msgs;
int msqId,sent;
key_t ipcKey;
ipcKey=ftok("/tmp/foo",42);
printf("The ipc key: %d\n",ipcKey);
msqId=msgget(ipcKey,IPC_CREAT|0777);
printf("The message id is: %d\n",msqId);
strcpy(msgs.text,"hello world");
msgs.type=1;
sent=msgsnd(msqId,&msgs,sizeof(msgs),0);
if(sent==0){
printf("The message queue has contents\n");
}
}
