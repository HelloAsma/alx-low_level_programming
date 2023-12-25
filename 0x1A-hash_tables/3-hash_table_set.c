#include "hash_tables.h"
/**
 * hash_table_set - func to add an element in the hash table
 * @ht: pointer to hash table
 * @key: the key to add - cannot be an empty string
 * @value: the value associated with the key
 *
 * Return: 1 if succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *pkg, *new_node;
	char *valuecopy, *keycopy;

	if (!ht || !key || !*key || !value)
		return (0);

	valuecopy = strdup(value);
	if (!valuecopy)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	pkg = ht->array[index];

	while (pkg)
	{
		if (!strcmp(key, pkg->key))
		{
			free(pkg->value);
			pkg->value = valuecopy;
			return (1);
		}
		pkg = pkg->next;
	}
	new_node = calloc(1, sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(valuecopy);
		return (0);
	}
	keycopy = strdup(key);
	if (!keycopy)
		return (0);
	new_node->key = keycopy;
	new_node->value = valuecopy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
