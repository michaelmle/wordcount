#ifndef WORDCOUNT_H   
   #define WORDCOUNT_H
   
   void addTotals(int charCount,int wordCount,int lineCount,int *tChars, 
      int* tWords, int *tLines);
   void pFile(FILE* fp, int *charCount,int *wordCount, int *lineCount);
   void goThru(FILE *file,int *charCount,int *wordCount, 
      int *lineCount);
   void incStuff(int c,int *d,int *charCount,int *wordCount,int *lineCount);
   void addPrint(int charCount,int wordCount,int lineCount,int *tChars,
      int *tWords,int *tLines,int cChars,int cWords,int cLines,
      char *name,int *totals);

#endif
