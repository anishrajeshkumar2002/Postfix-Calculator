#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

int is_space(char c){
  int x;	
  if((c == ' ')||(c == '\f')||(c == '\r')||(c == '\t')||(c == '\v')){
      x = 1;
  } else{
      x = 0;
  }
  return x;
}

int main(int argc, char * argv[]) {
  FILE *fin, *fout;
  char str[MAX_LEN];

  fin = fopen( argv[1],"r" );
  fout = fopen(argv[2],"w" );

  //Read the file one line at a time
  while(fgets(str,MAX_LEN,fin)!= NULL) {
    // Replace multiple whitespace chars with a single space ' '
    int i = 0;
    char ch = str[i];
    printf("%d",i);
    while(str[i] != '\0'){
       ch = str[i];
       if(is_space(ch) == 0){
         fputc(ch,fout);
	 i++;
       }
       else{
         int j = i;
	 int count = 0;
	 while(is_space(str[j])){
	    ++count;
            ++j;   
	 }
	 if(str[j] == '\n'){
	   i = j;
	   continue;
	 }
	 if((count == 1)){
	    fputc(' ',fout);
	    i = j;
	 }
	 else{
	    fputc(' ',fout);
	    i = j;  
	 }
	  
       }
    }
  }
  
  //Clean up gracefully
  fclose(fin);
  fclose(fout);
  return 0;
}
