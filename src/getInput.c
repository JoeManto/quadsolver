#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getInput.h"


int input(void (*f)(double *),int size){
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

      if(!convertTokensToDouble(doubleTokens,stringTokenizedBuffer,3)) return 1;

      printf("%.14g\n",doubleTokens[0]);
      printf("%.14g\n",doubleTokens[1]);
      printf("%.14g\n",doubleTokens[2]);

      (*f)(doubleTokens);
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

//if this function returns 0, it will exit the input function and prompt for new input
int convertTokensToDouble(double * doubleTokens,char ** tokenizeInputBuffer,int numTokens){
  int res = 1;
  for(int i = 0; i<numTokens; i++){
    sscanf(tokenizeInputBuffer[i], "%lf", &doubleTokens[i]);
    //run fpclassify to check for an inf, nan, 
    //a == 0
    if(i == 0 && fpclassify(doubleTokens[0]) == FP_ZERO){ //make sure a is not 0
      printf("%s\n","Input Error: first argument can't be zero");
      return 0;
    }
    res = classifyDouble(doubleTokens[i]);
  }
  return res;
}

int classifyDouble(double input){
  switch(fpclassify(input)) {
        case FP_INFINITE:  printf("%.14lf %s\n",input,"classified as inf"); return 0;
        case FP_NAN:       printf("%.14lf %s\n",input,"classified as NAN"); return 0;
        case FP_NORMAL:    return 1;
        case FP_SUBNORMAL: printf("%.14lf %s\n",input,"warning: classified as subnormal and number was rounded up"); return 1;
        case FP_ZERO:      return 1;
        default:           printf("%.14lf %s\n",input,"classified as unknown"); return 1;
    }
}

void showHelp(){
  printf("%s\n",
  "QuadSolver v1 [HELP] \n Input -\nInput is a collection of floating point numbers (a,b,c) of the polynomial separated by spaces all floating pointing numbers should be with in the max min ranges\n\n\t<float> _space <float> _space <float>\n\nEnter your input:"
  );
}

int checkForFlag(char flag , char * buffer){
  return (*buffer == flag && *(buffer+1) == '\n');
}
