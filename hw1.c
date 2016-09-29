#include <stdio.h>
#include <stdlib.h>
// don't import string.h

int myStrlen(const char* str) {
  int len = 0;
  while (str[len] != 0) {
    len++;
  }
  return len;
}

char *myStrncpy(char* dest, const char* src, int n) {
  int i;
  int stop = myStrlen(src);
  for(i = 0; i < n; i++) {
    if(i < stop) {
      dest[i] = src[i];
    }
    else {
      dest[i] = 0;
    }
  }
  dest[n] = 0;
  return dest;
}

char *myStrncat(char* dest, const char* src, int n) {
  int start = myStrlen(dest);
  myStrncpy(dest + start, src, n);
  return dest;
}

int myStrcmp(const char* str1, const char* str2) {
  int l1 = myStrlen(str1);
  int l2 = myStrlen(str2);
  int minLen = l1 < l2 ? l1 : l2;
  int i = 0;
  while(i < minLen && str1[i] == str2[i]) {
    i++;
  }
  if(i == minLen) {
    return l1 < l2 ? -1 : l1 > l2 ? 1 : 0;
  }
  else {
    return str1[i] < str2[i] ? -1 : 1;
  }
}

char *myStrchr(char *str, char c) {
  int i = 0;
  while (str[i] != 0) {
    if (str[i] == c) {
      return str + i;
    }
    i++;
  }
  return NULL;
}

int main() {
  char str[50] = "abcdef";
  char str1[50] = "12345";
  char str2[50];
  char str3[50] = "12345abccf";
  printf("start");
  printf("\nlen:: str:%d, str1:%d", myStrlen(str), myStrlen(str1));
  fflush(stdout);
  myStrncpy(str2, str1, 3);
  printf("\ncopy first 3 of str1: %s", str2);
  myStrncat(str1, str, 4);
  printf("\napp first 4 of str to str1: %s", str1);
  printf("\n%s cmp %s -> %d", str1, str3, myStrcmp(str1, str3));
  printf("\nstr from d on: %s\n", myStrchr(str, 'd'));
  return 0;
}
