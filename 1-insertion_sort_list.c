#include "sort.h"
/**
 * insertion_sort_list - entry
 * @list: var
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *hol;
	int h;

	if (!list)
		return;
	hol = *list;

	while (hol)
	{
		while (hol)
		{
			if (hol->next)
			{
				if (hol->n > hol->next->n)
				{
					h = hol->n;
					*(int *)&hol->n = hol->next->n;
					*(int *)&hol->next->n = h;
					hol = *list;
					print_list(*list);
					break;
				}
			}
			hol = hol->next;
		}
	}
}
