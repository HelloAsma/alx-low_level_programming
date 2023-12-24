#include "hash_tables.h"
/**
 * key_index - get index for the given key
 * @key: key(string) to hash(get index of)
 * @size: size of the hash table's array
 *
 * Return: index of the key using djb2
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
