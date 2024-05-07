#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
int main(){
	key_t key = ftok("shm", 65);
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);
	char *ar = (char*)shmat(shmid, (void*)0, 0);
	puts(ar);
	shmdt(ar);
	shmctl(shmid, IPC_RMID, 0);
}
