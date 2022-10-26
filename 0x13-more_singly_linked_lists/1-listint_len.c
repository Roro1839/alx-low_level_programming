#include "lists.h"



/**
 * listint_len - finds number of elems in a linked list
 * @h: pointers to listin_t list
 *
 * Return: number of elements
 */



size_t listint_len(const listint_t *h)

{



	size_t num = 0;



	while (h)

	{

		num++;

		h = h->next;

	}

	return (num);

}
