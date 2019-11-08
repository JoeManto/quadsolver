/**
 * Part of Quadsolver program
 * Software created by Jared Teller and Joe Manto
 * Licensed under GNU General Public License. See LICENSE.txt for more information.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 

#include "../../src/getInput.h"

int checkFlagTest();

/**
 * Main function, program starts here
 * @param [int argc] number of arguments
 * @param [char const *argv[]] array of char arrays
 */ 
int main(int argc,char *argv[]){
    int func = atoi(argv[1]); //returns 0 if cannot convert to an integer
    
    setUpErrLogging(); //sets stderr redirecting to cerr.log

    char * string = "joe";
    double * convert = malloc(sizeof(double));
    sscanf(string, "%lf\n", convert);

    printf("%.14g",*convert);
    
  
    //if argv[1] is a string
    if(func == 0){
        if(strcmp(argv[1],"all") == 0){
        //run all the tests
      
        }
    }else{
        switch (func){
        case 1:
            checkFlagTest();
            break;
        default:
            break;
        }
    }

    printf("%s\n","✅🤖ALL TESTS PASSED🤖✅");
    return 0;
}

/**
 *
 * ----- function Definition 
 * int checkForFlag(char flag , char * buffer) 
*/
int checkFlagTest(){

    assert(checkForFlag('q',"q\n") == 0);
    assert(checkForFlag('q',"q\0") == 0);

    assert(checkForFlag('h',"h\n") == 0);
    assert(checkForFlag('h',"h\0") == 0);

    assert(checkForFlag('l',"l\0\n") == 0);
    assert(checkForFlag('l',"l\0\0\0\0") == 0);
    assert(checkForFlag('l',"l\n\0\0\0") == 0);

    return 0;
}
