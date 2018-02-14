#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "wordCount.h"

int main(int argc, char *argv[]){
   FILE *file;
   int lineCount = 0, wordCount = 0, charCount = 0, i,cChars = 0;
   int cWords = 0,cLines = 0,std = 1, failure = 0, totals = 0;
   int tChars = 0, tWords = 0, tLines = 0;
   
   checkFlags(argc,argv,&cChars,&cWords,&cLines);
   
   for(i = 1; i < argc; i++){
      file = oFile(argv[i],&failure,&std);
      if(file != NULL){
         goThru(file,&charCount,&wordCount,&lineCount);
         addPrint(charCount,wordCount,lineCount,&tChars,&tWords,
            &tLines,cChars,cWords,cLines,argv[i],&totals);
      }
      
   }
   
   if(std == 1){
      pFile(stdin,&charCount, &wordCount, &lineCount);
   }
   
   whichPrint(std,totals,tChars,tWords,tLines,cChars,cWords,
      cLines,charCount,wordCount,lineCount);
   
   return failure ? EXIT_FAILURE : EXIT_SUCCESS;
}
