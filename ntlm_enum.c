#include "ntlm_enum.h"
#include <stdlib.h>
#include <string.h>

struct NtlmEnum *NtlmEnumNew(int numdigits, char *charsetArg) {
  struct NtlmEnum *newEnum = (struct NtlmEnum *) malloc(sizeof(struct NtlmEnum));
  newEnum->piDigits = (int *) malloc(sizeof(int)*(numdigits + 1));
  newEnum->charset = (char *) malloc(sizeof(char)*(strlen(charsetArg) + 1));
  strcpy(newEnum->charset, charsetArg);
  int i = 0;
  for (i = 0; i < numdigits; i++) {
    newEnum->piDigits[i] = 0;
  }
  newEnum->piDigits[i] = -1;
  newEnum->mod = strlen(newEnum->charset);
}

void ntlm_increment(struct NtlmEnum *this) {
  int *current = this->piDigits;
  while (*current != -1) {
    *current = (*current + 1)%this->mod;
    if (*current != 0) {
      return;
    }
    current++;
  }
}

void ntlm_get_string(struct NtlmEnum *this, char *dest) {
  int *current = this->piDigits;
  int index = 0;
  while (*current != -1) {
    index = current - this->piDigits;
    dest[index] = this->charset[this->piDigits[index]];
    current++;
  }
}
