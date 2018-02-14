#ifndef UI_H
   #define UI_H

   int checkFlags(int i, char *argv[], int *cChars, int *cWords, int  *cLines);
   void openFile(int argc, FILE *fp); 
   FILE* oFile(char *fname,int* failure,int *std);
   void printResults(int charCount, int wordCount,int lineCount, 
      int cChar, int cWords, int cLines, char *name, int std);
   void printResultsSTD(int charCount, int wordCount,int lineCount, 
      int cChar, int cWords, int cLines);
   void whichPrint(int std, int totals, int tChars, int tWords, 
      int tLines, int cChars, int cWords, int cLines,int charCount, 
      int wordCount,int lineCount);
   int clearFlags(int cChars, int cWords, int cLines);
#endif
