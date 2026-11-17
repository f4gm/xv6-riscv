#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
  for(int i = 0; i < 3; i++){
    int pid = fork();
    if(pid == 0){
      for(int k = 0; k < 10; k++){
        volatile int x = 0;
        for(int j = 0; j < 3000000; j++)
          x++;
        printf("proceso %d: vuelta %d, x = %d\n", getpid(), k, x);
      }
      exit(0);
    }
  }
  for(int i = 0; i < 3; i++)
    wait(0);
  exit(0);
}
