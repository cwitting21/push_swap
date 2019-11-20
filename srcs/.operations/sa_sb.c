

void		swap_a_b()
{
	stack->head = stack->head->next->next;
	stack->head->next = stack->head;
}
