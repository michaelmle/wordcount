#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ui.h"

void incStuff(int c,int *d,int *charCount,int *wordCount,int *lineCount){
   if(isspace(c)){
      if(c == '\n'){
         ++*lineCount;
      }
      if(*d > 0){
         ++*wordCount;
      }
      *d = 0;
   }   
   else{
      if(isprint(c)){
         ++*d;
      }
   }
}

void pFile(FILE *fp ,int *charCount, int *wordCount,int *lineCount){
   int c,d=0;
   
   *charCount = 0;
   *wordCount = 0;
   *lineCount = 0;

   while((c=getc(fp)) != EOF){
      ++*charCount;
      incStuff(c,&d,charCount,wordCount,lineCount);
   }
   if(d > 0){
      ++*wordCount;
   }
}

void addTotals(int charCount,int wordCount,int lineCount,int *tChars, 
   int* tWords, int *tLines){
   *tChars += charCount;
   *tWords += wordCount;
   *tLines += lineCount;
}

void goThru(FILE *file,int  *charCount, int *wordCount, 
   int *lineCount){
   pFile(file,charCount,wordCount,lineCount);
}

void addPrint(int charCount,int wordCount,int lineCount,int *tChars,
   int *tWords,int *tLines,int cChars,int cWords,int cLines,char *name,
   int *totals){
   addTotals(charCount,wordCount,lineCount,tChars,tWords,tLines);
   printResults(charCount,wordCount,lineCount, cChars,cWords,cLines,name,1);
   ++*totals;
}
