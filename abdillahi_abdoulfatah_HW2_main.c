/**************************************************************
* Class:  CSC-415-02 Summer 2022
* Name: Abdoulfatah Abdillahi
* Student ID: 921623492
* GitHub UserID: abdoul1996
* Project: Assignment 2 – Stucture in Memory and Buffering
*
* File: <abdillahi_abdoulfatah_HW2_main.c>
*
* Description: In this program we are focusing data structures, buffers and pointers. 
                Writing this program gives me a experences using structures, pointers, character strings etc...
**************************************************************/

#include "assignment2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>



int main(int argc, char *argv[]){
                                
char buffer[BLOCK_SIZE];                                 // Maximimum size of the input the us 
int index = 0;                                          //index
                                // get nextLine
const char *nextString;                                   // next string

    

    personalInfo * personalData = (personalInfo *) malloc(sizeof(personalInfo));     // I want personalData to store the sizeof(personalInfo)data

    personalData->firstName = argv[1];
    personalData->lastName = argv[2];
    personalData->studentID = 921623492;
    personalData->level = SENIOR;
    personalData->languages = KNOWLEDGE_OF_C + KNOWLEDGE_OF_JAVA + KNOWLEDGE_OF_HTML + KNOWLEDGE_OF_JAVASCRIPT ;

    /*
        copying string to string, the string has to be less 100 character between 0 to 99
    */
    for( int i=0; argv[i]!= NULL && i<100; i++){        
       strcpy(personalData->message, argv[i]);
    }


    // This function is all about personal information but if the function return 0 the data
    // is success otherwise it's not 
    writePersonalInfo(personalData);   
    if( writePersonalInfo(personalData) == 0)
    {
        printf("The function is succeed");
    }
    else{
        printf("The function is not succeed");
    }



    
    /* I called getNext function, then we keep looking until the return value is NULL
        Then it will copy all the string into buffer(block). if the buffer is filled the code
        is commit the buffer by calling commitBlock*/

    nextString = getNext(); 
    while(nextString != 0){
        for(int i=0; i < strlen(nextString); i++){
            buffer[index++] = nextString[i];
            if(index == 256){
                commitBlock(buffer);
                strcpy(buffer, "");
                index = 0;
            }
        }
        nextString = getNext();         // get Next Line of the string 
    }
    if(index != 0){
        commitBlock(buffer);          // 256 byte buffer
    }

                                
    int check = checkIt();              // calling the function checkIt, it's checking the result 

    return check;
    
}

