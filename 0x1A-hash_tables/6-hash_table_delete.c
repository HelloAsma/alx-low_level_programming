#include "hash_tables.h"
/**
 * hash_table_delete - Delete/free hash table with all nodes
 * @ht: pointer to hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *ptr, *node;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		ptr = ht->array[i];
		while (ptr)
		{
			node = ptr;
			ptr = ptr->next;
			if (node->key)
				free(node->key);
			if (node->value)
				free(node->value);
			free(node);
		}
	}
	free(ht->array);
	free(ht);
}
