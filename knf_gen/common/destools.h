#ifndef __DESTOOLS_H__
#define __DESTOOLS_H__

#include <stdint.h>

#include "minunit.h"

uint64_t initial_permutation(uint64_t plaintext);
uint64_t initial_permutation_reverse(uint64_t intermediate_text);

uint64_t final_permutation(uint64_t intermediate_text);
uint64_t final_permutation_reverse(uint64_t ciphertext);

uint64_t key_initial_permutation(uint64_t key);
uint64_t key_initial_permutation_reverse(uint64_t key_without_paritybits);

uint64_t key_set_parity_bits(uint64_t key_with_wrong_paritybits);

uint64_t str_to_int(const char str[8]);
void int_to_str(char* str, uint64_t value);

#endif //__DESTOOLS_H__
