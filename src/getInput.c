#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"


int input(void (*f)(char *),int size){
  char buffer[size];
  char * bufferPointer = fgets(buffer, size, stdin);

  if(bufferPointer != NULL){
    if(*(bufferPointer+1) == '\0'){
      input((*f),size);
    }else if(checkForFlag('q',bufferPointer)){
      printf("%s\n","quiting...");
      return 0;
    }else if(checkForFlag('h',bufferPointer)){
      showHelp();
      return 1;
    }else{
      //define token buffer pointer
      char ** stringTokenizedBuffer = malloc(sizeof(char*)*3);

      //tokenize bufferPointer on " " -> stringTokenizedBuffer
      tokenizeInput(stringTokenizedBuffer,bufferPointer,3);

      printf("%s\n",stringTokenizedBuffer[0]);
      printf("%s\n",stringTokenizedBuffer[1]);
      printf("%s\n",stringTokenizedBuffer[2]);


      (*f)(bufferPointer);
      printf("%s\n","Enter another input | [q] : quit");
      return 1;
    }
  }else{
    perror("Input Error: ");
    exit(errno);
  }
}

int tokenizeInput(char ** tokenizedInputBuffer,char * buffer,int numTokens){

  char bufferCopy[strlen(buffer)];
  strcpy(bufferCopy,buffer);

	char delim[] = ",";
	char *ptr = strtok(bufferCopy, delim);

  int i = 0;
	for(; ptr != NULL; i++)
	{
    tokenizedInputBuffer[i] = malloc(sizeof(char)*strlen(ptr));
    strcpy(tokenizedInputBuffer[i],ptr);
		ptr = strtok(NULL, delim);
	}
  if(i > numTokens){
    printf("\n%s\n","Invaild Input: number of arguments greater than 3");
  }
  if(i < numTokens){
    printf("\n%s\n","Invaild Input: number of arguments less than 3");
  }

  return 1;
}

void showHelp(){
  printf("%s\n",
  "QuadSolver v1 [HELP] \n Input -\nInput is a collection of floating point numbers (a,b,c) of the polynomial separated by spaces all floating pointing numbers should be with in the max min ranges\n\n\t<float> _space <float> _space <float>\n\nEnter your input:"
  );
}

int checkForFlag(char flag , char * buffer){
  return (*buffer == flag && *(buffer+1) == '\n');
}
