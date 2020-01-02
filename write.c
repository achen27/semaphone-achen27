#include "sem.h"

struct sembuf sb;

int wwrite(){

  int semd;
  semd = semget(SEMKEY,1,0);
  if (semd == -1){
    printf("Error Accessing Semaphore: %s\n", strerror(errno));
    return -1;
  } else {
    printf("Trying to get in...\n");
    semop(semd, &sb, 1);
  }

  int shmd;
  shmd = shmget(MEMKEY, SIZE, 0);
  if (shmd == -1){
    printf("Error Accessing Shared Memory: %s\n", strerror(errno));
    return -1;
  }

  int fd;
  fd = open("story.txt", O_WRONLY | O_APPEND);
  if (fd == -1){
    printf("Error Accessing Story File: %s\n", strerror(errno));
    return -1;
  }

  char *old = shmat(shmd, 0, 0);
  printf("Last Addition: %s\n\n", old);
  char new[SIZE];
  printf("Your Addition: ");
  fgets(new, SIZE, stdin);
  printf("\n");

  write(fd, new, strlen(new));
  close(fd);

  strcpy(old, new);
  shmdt(old);
  sb.sem_op = 1;
  semop(semd, &sb, 1);

  return 0;

}

int main(int argc, char * argv[]){
  sb.sem_num = 0;
  sb.sem_flg = SEM_UNDO;
  sb.sem_op = -1;
  wwrite();
  return 0;
}
