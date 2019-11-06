#include <stdio.h>
#include "getInput.h"

void inputCallBack(char * buffer);
void showDetails();


int main(int argc, char const *argv[]) {

  showDetails();
  int status = 1;
  //200 should be the max number of character for 3 floats.
  while(input(inputCallBack,200)){

  }
  //printf("%d",status);


  return 0;
}

void showDetails(){
  printf("%s\n","QuadSolver v1 written by Joe Manto & Jared Teller");
  printf("%s\n","[Help] 'h' for the help details");
  printf("%s\n","[Exit] 'q' to quit the program");
}

void inputCallBack(char * buffer){
  printf(":::%s\n",buffer);
}
