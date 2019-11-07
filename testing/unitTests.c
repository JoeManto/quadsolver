#include <stdio.h>
#include <stdlib.h>

int main(int argc,char**argv){
    int func = atoi(argv[0]);
    if(!func){
        if(strcmp(argv[0],"all")){
            //run all the tests
        }
    }else{
        switch (func)
        {
        case 0:
            //run all unit test for a function
            break;
        default:
            break;
        }
    }
}