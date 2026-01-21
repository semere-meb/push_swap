#include "push_swap.h"

t_stack	*stack_new(void *content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->content = content;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack **lst, t_stack *new_node)
{
	t_stack	*temp;

	if (!lst || !new_node)
		return ;
	temp = *lst;
	if (!*lst)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = temp;
		new_node->prev = temp->prev;
		(temp->prev)->next = new_node;
		temp->prev = new_node;
	}
	*lst = new_node;
}

t_stack	*stack_pop(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return (NULL);
	temp = *lst;
	if (temp->prev == temp->next)
		*lst = NULL;
	else
	{
		(temp->next)->prev = temp->prev;
		(temp->prev)->next = temp->next;
		*lst = temp->next;
	}
	return (temp);
}

size_t	stack_size(t_stack **stack)
{
	size_t	size;
	t_stack	*node;

	size = 0;
	if (!stack)
		return (size);
	node = *stack;
	while (node)
	{
		size++;
		if (node == node->next)
			return (size);
		node = node->next;
	}
	return (size);
}

void	stack_iter(t_stack **stack, void (*f)(void *))
{
	t_stack	*node;

	if (!stack || !f)
		return ;
	node = *stack;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
