#include "hash_tables.h"
/**
 * hash_table_print - print the key/value from ht in order
 * @ht: pointer to the printable hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t  *ptr;
	int comma = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		ptr = ht->array[i];
		while (ptr)
		{
			if (comma)
				printf(", ");
			printf("'%s': '%s'", ptr->key, ptr->value);
			comma = 1;
			ptr = ptr->next;
		}
	}
	printf("}\n");
}
