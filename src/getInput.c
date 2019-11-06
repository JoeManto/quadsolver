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
      if(!tokenizeInput(stringTokenizedBuffer,bufferPointer,3)) return 1;

      double * doubleTokens = malloc(sizeof(float)*3);

      convertTokensToDouble(doubleTokens,stringTokenizedBuffer,3);

      printf("%.15lf\n",doubleTokens[0]);
      printf("%.16lf\n",doubleTokens[1]);
      printf("%.16lf\n",doubleTokens[2]);

      (*f)(bufferPointer);
      printf("%s\n","Enter another input | [q] : quit");
      return 1;
    }
  }else{
    perror("Input Error: ");
    exit(errno);
  }
  return 0;
}

int tokenizeInput(char ** tokenizedInputBuffer,char * buffer,int numTokens){

  char bufferCopy[strlen(buffer)];
  strcpy(bufferCopy,buffer);

	char delim[] = " \t\n";
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
  return (i == 3);
}

double * convertTokensToDouble(double * doubleTokens,char ** tokenizeInputBuffer,int numTokens){
  for(int i = 0; i<numTokens; i++) sscanf(tokenizeInputBuffer[i], "%lf", &doubleTokens[i]);
}

void showHelp(){
  printf("%s\n",
  "QuadSolver v1 [HELP] \n Input -\nInput is a collection of floating point numbers (a,b,c) of the polynomial separated by spaces all floating pointing numbers should be with in the max min ranges\n\n\t<float> _space <float> _space <float>\n\nEnter your input:"
  );
}

int checkForFlag(char flag , char * buffer){
  return (*buffer == flag && *(buffer+1) == '\n');
}
