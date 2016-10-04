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
  char s[50] = "abcdef";
  char s1[50] = "12345";
  char s2[50];
  char s3[50] = "12345abccf";
  printf("start");
  printf("\ns = %s\ns1 = %s\ns3 = %s", s, s1, s3);
  printf("\nlen of s = %d, len of s1 = %d", myStrlen(s), myStrlen(s1));
  
  printf("\n\ncopy first 3 of %s to s2 -> %s\ns2 = %s", s1, myStrncpy(s2, s1, 3), s2);
  
  printf("\n\ncat first 4 of %s to s1 -> %s\ns1 = %s", s, myStrncat(s1, s, 4), s1);
  printf("\n\n%s cmp %s -> %d\n%s cmp %s -> %d\n%s cmp %s -> %d", s1, s3, myStrcmp(s1, s3), s3, s1, myStrcmp(s3, s1), s2, s2, myStrcmp(s2, s2));
  printf("\n\n%s from d on: %s\n%s from x on: %s\n", s, myStrchr(s, 'd'), s, myStrchr(s, 'x'));
  return 0;
}
