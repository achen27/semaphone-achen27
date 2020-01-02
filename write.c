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
  shmd = shmget(MEMKEY, sizeof(int), 0);
  if (shmd == -1){
    printf("Error Accessing Shared Memory: %s\n", strerror(errno));
    return -1;
  }

  int fd;
  fd = open("story.txt", O_RDWR | O_APPEND);
  if (fd == -1){
    printf("Error Accessing Story File: %s\n", strerror(errno));
    return -1;
  }

  int *data = shmat(shmd, 0, 0);
  char old[1000];
  lseek(fd, -*data, SEEK_END);
  int r = read(fd,old,*data);
  printf("%d size\n", *data);
  printf("Last Addition: %s\n\n", old);
  char new[1000];
  printf("Your Addition: ");
  fgets(new, 1000, stdin);
  printf("\n");
  lseek(fd, 0, SEEK_END);
  write(fd, new, strlen(new));
  close(fd);

  int newlen = strlen(new);
  // printf("%d size\n", newlen);
  *data = newlen;
  // printf("%d data\n", *data);
  shmdt(&data);
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
