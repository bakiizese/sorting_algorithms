#include "sort.h"
/**
 * swap - entry
 * @cr: var
 * @cro: var
 * @list: var
 */
void swap(listint_t *cr, listint_t *cro, listint_t **list)
{
	listint_t *tmp1 = cr->next, *tmp2 = cro->prev;

	if (tmp1 != NULL)
		tmp1->prev = cro;
	if (tmp2 != NULL)
		tmp2->next = cr;
	cr->prev = tmp2;
	cro->next = tmp1;
	cr->next = cro;
	cro->prev = cr;
	if (*list == cro)
		*list = cr;
	print_list(*list);
}
/**
 * cocktail_sort_list - entry
 * @list: var
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ck = *list;
	listint_t *fs, *ls;

	fs = NULL;
	ls = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (fs != ls)
	{
		while (ck->next)
		{
			if (ck->n > ck->next->n)
				swap(ck->next, ck, list);
			else
				ck = ck->next;
		}
		ls = ck;
		while (ck->prev != fs)
		{
			if (ck->n < ck->prev->n)
				swap(ck, ck->prev, list);
			else
				ck = ck->prev;
		}
		fs = ck;
	}
}
