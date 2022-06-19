#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
void main(){
key_t ipckey;
int msqid;
ssize_t rcv;
struct{
int type;
char text[100];
}msgr;
ipckey=ftok("/tmp/foo",42);
printf("The reciever ipc key is: %d\n",ipckey);
msqid=msgget(ipckey,IPC_CREAT|0777);
printf("The reciever msqid is: %d\n",msqid);
rcv=msgrcv(msqid,&msgr,sizeof(msgr),0,0);
if(rcv>0){
printf("The message is recieved\n");
printf("The message is %s\n",msgr.text);
}
}
