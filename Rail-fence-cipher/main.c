#include <stdio.h>

void logo(){
  printf("______      _ _    __                           _       _\n");
  printf("| ___ \\    (_) |  / _|                         (_)     | |\n");
  printf("| |_/ /__ _ _| | | |_ ___ _ __   ___ ___    ___ _ _ __ | |__   ___ _ __\n");
  printf("|    // _` | | | |  _/ _ \\ '_ \\ / __/ _ \\  / __| | '_ \\| '_ \\ / _ \\ '__|\n");
  printf("| |\\ \\ (_| | | | | ||  __/ | | | (_|  __/ | (__| | |_) | | | |  __/ |\n");
  printf("\\_| \\_\\__,_|_|_| |_| \\___|_| |_|\\___\\___|  \\___|_| .__/|_| |_|\\___|_|\n");
  printf("                                                 | |\n");
  printf("                                                 |_|\n");
}

void encrypt(const char *inputFileName, const int key){
  char c;
  int startLine = 0, endLine;
  char line[];
  FILE *inputFile, *outputFile;

  inputFile = fopen(inputFileName, "r");
  outputFile = fopen("encrypted.txt","w");

  if(inputFile == NULL){
    printf("Error open input file!");
    return;
  }

  while((c = fgetc(inputFile)) != EOF){
    if( c == '\n' ){

    }
  }
  

  fclose(inputFile);
  fclose(outputFile);

  return;
}

void decrypt(const char *inputFileName, const int key){
  char c;
  FILE *inputFile, *outputFile;

  inputFile = fopen(inputFileName, "r");
  outputFile = fopen("decrypted.txt","w");

  if(inputFile == NULL){
    printf("Error open input file!");
    return;
  }

  while((c = fgetc(inputFile)) != EOF){
    
  }


  fclose(inputFile);
  fclose(outputFile);

  return;
}

int main(){
  logo();

  int start = 1;
  int key;
  int value;
  char inputFileName[] = "input.txt";

  while(start){
    printf("\n| MENU |\n");
    printf(" 1 -> Encrypt\n");
    printf(" 2 -> Decrypt\n");
    printf(" 0 -> Exit\n\n");

    printf("Enter value : ");
    scanf("%d", &value);

    switch(value){
      case 1:
        printf("key = ");
        scanf("%d", &key);
        encrypt(inputFileName, key);
        break;
      case 2:
        printf("key = ");
        scanf("%d", &key);
        encrypt(inputFileName, key);
        break;
      case 0:
        start = 0;
        break;
      default: 
        printf("Enter 1 , 2 or 0 !!!\n");
        break;
    }
  }

  return 0;
}
