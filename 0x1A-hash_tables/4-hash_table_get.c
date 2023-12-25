#include "hash_tables.h"
/**
 * hash_table_get - func to retrieve the value associeted with key in ht
 * @ht: pointer to the hash table
 * @key: key to retrive the value
 *
 * Return: the value associated with the element.
 *         NULL - if the key cannot be found.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t  *ptr;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	ptr = ht->array[index];

	while (ptr)
	{
		if (!strcmp(key, ptr->key))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}
