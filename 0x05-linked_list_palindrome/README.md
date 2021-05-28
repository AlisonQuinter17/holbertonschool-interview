## Linked_list_palindrome

int r, c;
    
    if (!head)
		return (1);
		
    r = recursive(head->next, aux) ? 1 : 0;
		
	c = ((head->n == (*aux)->n ? ((*aux) = (*aux)->next), 1 : 0));
		
	return (r && c ? 1 : 0);
