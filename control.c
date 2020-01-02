#include "sem.h"

int main(int argc, char * argv[]){
  if (argc == 2) {
    if (strcmp(argv[1],"-c") == 0) {
      //create();
      printf("Create\n");
    }
    else if (strcmp(argv[1],"-r") == 0) {
      //remove();
      printf("remove\n");
    }
    else if (strcmp(argv[1],"-v") == 0) {
      //view();
      printf("view\n");
    }
    else {
      printf("Invalid input.\n-c: Create Story\n-r: Remove Story\n-v: View Entire Story\n");
    }
  } else {
    printf("Invalid input.\n-c: Create Story\n-r: Remove Story\n-v: View Entire Story\n");
  }
}
