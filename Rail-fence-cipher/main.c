#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void logo(){
  printf("______      _ _    __                           _       _\n");
  printf("| ___ \\    (_) |  / _|                         (_)     | |\n");
  printf("| |_/ /__ _ _| | | |_ ___ _ __   ___ ___    ___ _ _ __ | |__   ___ _ __\n");
  printf("|    // _` | | | |  _/ _ \\ '_ \\ / __/ _ \\  / __| | '_ \\| '_ \\ / _ \\ '__|\n");
  printf("| |\\ \\ (_| | | | | ||  __/ | | | (_|  __/ | (__| | |_) | | | |  __/ |\n");
  printf("\\_| \\_\\__,_|_|_| |_| \\___|_| |_|\\___\\___|  \\___|_| .__/|_| |_|\\___|_|\n");
  printf("                                                 | |\n");
  printf("                                                 |_|           Made by Black Ghost\n");
}

char* encryptLine(char line[], int key) {
    int length = 0, i,j,k;
    while (line[length] != '\0') {
        length++;
    }

    char tmpArray[key][length];
    char* result = (char*)malloc((length + 1) * sizeof(char));


    for(i = 0; i < key; i++){
      for(j = 0; j < length; j++){
          tmpArray[i][j] = '\0';
      }
    }

    int down = 1;
    int index = 0;
    for( i = 0; i < length; i++){
        tmpArray[index][i] = line[i];
        
        if(down){
          if(index == key - 1){
            down = 0;
            index--;
          } else {
            index++;
          }
        } else if(!down) {
          if(index == 0){
            down = 1;
            index++;
          } else {
            index--;
          }
        }
    }

    k = 0;
    for(i = 0; i < key; i++){
      for(j = 0; j < length; j++){
        if(tmpArray[i][j] != '\0'){
          result[k] = tmpArray[i][j];
          k++;
        }
      }
    }

    result[length] = '\0';
    return result;
}

void encrypt(const char *inputFileName, const int key){
  char c;
  char line[1024];
  FILE *inputFile, *outputFile;

  inputFile = fopen(inputFileName, "r");
  outputFile = fopen("encrypted.txt","w");

  if(inputFile == NULL){
    printf("Error open input file!");
    return;
  }

  while (fgets(line, sizeof(line), inputFile) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    char* encryptedLine = encryptLine(line, key);
    fprintf(outputFile, "%s\n", encryptedLine);
    free(encryptedLine);
  }

  fclose(inputFile);
  fclose(outputFile);

  return;
}

char* decryptLine(char line[], int key){
  int length = 0, N, i,j, index;
  float K;
  while(line[length] != '\0'){
    length++;
  }
  
  N = 2 * (key - 1);
  K = (float)length / N;

  char tmpArray[key][length];
    for(i = 0; i < key; i++){
      for(j = 0; j < length; j++){
          tmpArray[i][j] = '\0';
      }
    }

  index = 0;
  for (i = 0; i < key; i++) {
    int step1 = (key - i - 1) * 2;
    int step2 = i * 2;
    int pos = i;
    if (i == 0 || i == key - 1) {
      while (pos < length) {
        tmpArray[i][pos] = line[index++];
          pos += N;
      }
    } else {
      int toggle = 0;
      while (pos < length) {
        tmpArray[i][pos] = line[index++];
        if (toggle == 0) {
          pos += step1;
          toggle = 1;
        } else {
          pos += step2;
          toggle = 0;
        }
      }
    }
  }

  
  char* result = (char*)malloc((length + 1) * sizeof(char));
  index = 0;
  for (j = 0; j < length; j++) {
      for (i = 0; i < key; i++) {
        if (tmpArray[i][j] != '\0') {
          result[index++] = tmpArray[i][j];
        }
      }
  }



  result[length] = '\0';
  return result;
}

void decrypt(const char *inputFileName, const int key){
  char c;
  char line[1024];
  FILE *inputFile, *outputFile;

  inputFile = fopen(inputFileName, "r");
  outputFile = fopen("decrypted.txt","w");

  if(inputFile == NULL){
    printf("Error open input file!");
    return;
  }

  while (fgets(line, sizeof(line), inputFile) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    char* decryptedLine = decryptLine(line, key);
    fprintf(outputFile, "%s\n", decryptedLine);
    free(decryptedLine);
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
        decrypt(inputFileName, key);
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
