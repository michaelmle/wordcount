#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printError(char *argv){
   fprintf(stderr,"swc: invalid option: '%s'\n", argv);
   fprintf(stderr,"Usage: swc [-l|-w|-c]... [file]...\n");
   exit(EXIT_FAILURE);
}

void whichFlag(char *flag, int*cChars,int *cWords,int *cLines){
   if(flag[0] == '-'){
      if(strcmp(flag, "-c") == 0){
         *cChars = 1;
      }
      else if(strcmp(flag, "-w") == 0){
         *cWords = 1;
      }
      else if(strcmp(flag, "-l") == 0){
         *cLines = 1;
      }
      else{
         printError(flag);
      }	
   }
}

void checkFlags(int argc, char *argv[], int *cChars, int *cWords, int *cLines){
   int i;
   for(i = 1; i < argc; i++){
      whichFlag(argv[i],cChars,cWords,cLines);
   }
}

FILE* oFile(char *fname,int *failure,int *std){
   FILE *fp;
   fp = fopen(fname,"r");
   if(fname[0] == '-'){
      return NULL;
   }
   if(fp == NULL){
      fprintf(stderr,"swc: ");
      perror(fname);
      *std = 0;
      *failure = 1;
      return NULL;
   }
   else{
      *std = 0;
      return fp;
   }
}
void printResults(int charCount, int wordCount,int lineCount, 
   int cChars, int cWords, int cLines, char *name, int std){
   int count = 0;
   if(cLines == 1){
      printf("%10u",lineCount);
      count++;
   }
   if(cWords == 1){
      if(count == 1){
         printf(" ");
      }
      count++;
      printf("%10u",wordCount);
   }
   if(cChars == 1){
      if(count > 0){
         printf(" ");
      }
      printf("%10u",charCount);
   }
   if(cChars == 0 && cWords == 0 && cLines == 0){
      printf("%10u %10u %10u",lineCount,wordCount,charCount);   
   }
   if(std == 1){
      printf(" %s",name);
   }
   printf("\n");
}
   
void whichPrint(int std, int totals, int tChars, int tWords, 
   int tLines, int cChars, int cWords, int cLines, 
   int charCount, int wordCount, int lineCount){
   char total[] = "total";
   if(std == 1){
      printResults(charCount,wordCount,lineCount,cChars,cWords,cLines,total,0);
   }
   if(totals > 1){
      printResults(tChars,tWords,tLines,cChars,cWords,cLines,total,1);
   }
}
