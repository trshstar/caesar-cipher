#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#include <ctype.h>
// this program implements Caesar Cipher encoding and decoding

// input text max length
#define MAX_LENGTH 251

size_t find(char* str, char c) {

  for(size_t i = 0; i < strlen(str); i++) {
    if (c == str[i]) {
      return i;
    }
  }
  return 0;
}
char * caesarCipherEncoder(char text[], int off) {
  char letters[] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4' ,'5', '6' ,'7', '8', '9', ':', ';', '<', '=', '>', '?', '@','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'x', 'z', '{', '|', '}', '~'};
  int size = 95;
  char *encoded = malloc(sizeof(char) * MAX_LENGTH);
  size_t length = strlen(text);
  size_t diff = 0;
  for(size_t i = 0; i < length - 1; i++) {
    diff = (find(letters, text[i]) + off) % size;
    encoded[i] = letters[diff];
  }
  return encoded;
}

char * caesarCipherDecoder(char text[], int off) {
  char letters[] = {' ', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4' ,'5', '6' ,'7', '8', '9', ':', ';', '<', '=', '>', '?', '@','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'x', 'z', '{', '|', '}', '~'};
  int size = 95;
  char *decoded = malloc(sizeof(char) * MAX_LENGTH);
  size_t length = strlen(text);
  size_t diff = 0;
  for(size_t i = 0; i < length - 1; i++) {
    diff = (find(letters, text[i]) - off) % size;
    decoded[i] = letters[diff];
  }
  return decoded;
}

int main(void) {

  //variables
  char input[MAX_LENGTH];
  int offset;
  char opt = '0';
  const char *esc = "^[";
  // inital input
  printf("CAESAR CIPHER\n");
  printf("-------------\n");
  printf("*************\n\n");
  printf("**options\n");
  while(opt != '9') {
    printf("1 = encode\n");
    printf("2 = decode\n");
    printf("9 = quit\n\n");
    scanf("%c", &opt);
    getchar();
    //encode
    if(opt == '1') {
      printf("enter text encoding: (up to 250 chars) ");
      fgets(input, MAX_LENGTH, stdin);
      printf("enter offset for encoding: (0 - 25) ");
      scanf("%d", &offset);
      getchar();
      char *newEncoding = caesarCipherEncoder(input, offset);
      printf("%s\n\n", newEncoding);
      free(newEncoding);
    }

    //decode
    if(opt == '2') {
      printf("enter text decoding: (up to 250 chars) ");
      fgets(input, MAX_LENGTH, stdin);
      printf("enter offset for decoding: (0 - 25) ");
      scanf("%d", &offset);
      getchar();
      char *newDecoding = caesarCipherDecoder(input, offset);
      printf("%s\n\n", newDecoding);
      free(newDecoding);
    }
    if(opt == '9') {
      break;
    }
    
  }
    
  printf("shutting down...");
  return 0;
}