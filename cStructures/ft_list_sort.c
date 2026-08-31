#include "st_list.h"
#include <unistd.h>

int	*ft_cmp(int a, int b)
{
	if (a == b)
		return (0);
	return (a - b);
}

struct	st_list	*ft_list_sort(t_list *lst, int (*cmp)(int, int))
{
	t_list	*current;
	t_list	*head;
	t_list	*tmp;

	current = lst;
	head = lst;

	while (current)
	{
		if (cmp(current->data, head->data) == 0)
			current = current->next;
		if (cmp(current->data, head->data) != 0)
		{
			tmp = &head;
			head = &current;
			current = &tmp;
		}
	}
	return (lst);
}

int	main()
{
	t_list	*alist;
	t_list	*blist;
	t_list	*clist;
	t_list	*dlist;
	t_list	*elist;
	t_list	*flist;

	alist->next = blist;
	blist->next = clist;
	clist->next = dlist;
	dlist->next = elist;
	elist->next = flist;

	alist->data = 15;
	blist->data = 6;
	clist->data = 2;
	dlist->data = 10;
	elist->data = 20;
	flist->data = 1;
//f - c - b - d - a - e (ascending)
	ft_list_sort(alist, *ft_cmp(int, int));
}
