#include "hash_tables.h"
/**
 * sorted_list - function to insert new sorted node
 * @ht: pointer to sorted hash table
 * @new_node: new node to insert
 *
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *spkg = ht->shead;
	if (spkg == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, spkg->key) < 0)
		{
			new_node->snext = spkg;
			new_node->sprev = spkg->sprev;

			if (!spkg->sprev)
				ht->shead = new_node;
			else
				spkg->sprev->snext = new_node;
			spkg->sprev = new_node;
			return;
		}
		spkg = spkg->snext;
	} while (spkg);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

/**
 * shash_table_create - create a sorted hash table
 * @size: size of the new sorted hash table
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;

	if (size == 0)
		return (NULL);

	table = calloc(1, sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
}

/**
 * shash_table_set - func to add an element to the sorted hash table
 * @ht: pointer to sorted hash table
 * @key: The key to add - cannot be an empty string
 * @value: The value associated with key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *valuecopy, *keycopy;
	shash_node_t  *pkg, *new_node;

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
	new_node = calloc(1, sizeof(shash_node_t));
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
	sorted_list(ht, new_node);
	return (1);
}
/**
 * shash_table_get - func to retrieve the value associeted with key in ht
 * @ht: pointer to hash table
 * @key: the key to retrive value
 *
 * Return: the value associated with the element.
 *         NULL - if the key cannot be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t  *ptr;

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

/**
 * shash_table_print - print the key/value from ht in order
 * @ht: pointer to the printable hash table
 *
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *ptr;
	int comma = 0;

	if (!ht)
		return;
	ptr = ht->shead;
	printf("{");
	while (ptr)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", ptr->key, ptr->value);
		comma = 1;
		ptr = ptr->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - print the key/value from ht in reverse
 * @ht: pointer to hash table
 *
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *pkg;
	int comma = 0;

	if (!ht)
		return;
	pkg = ht->stail;
	printf("{");
	while (pkg)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", pkg->key, pkg->value);
		comma = 1;
		pkg = pkg->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - Delete/free hash table with all nodes
 * @ht: pointer to hash table
 *
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *ptr, *node;
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
