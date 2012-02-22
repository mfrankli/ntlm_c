#ifndef NTLM_ENUM_INCLUDED
#define NTLM_ENUM_INCLUDED

struct NtlmEnum {
  int *piDigits;
  char *charset;
  int mod;
};

struct NtlmEnum *NtlmEnumNew(int numdigits, char *charsetArg);

void ntlm_increment(struct NtlmEnum *this);

void ntlm_get_string(struct NtlmEnum *this, char *dest);

#endif
