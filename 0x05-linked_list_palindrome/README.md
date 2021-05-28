## Linked_list_palindrome

#### More detail

    int is_palindrome(listint_t **head)  
    {
    		return (detection(head, *head));  
    }

    int detection(listint_t **head, listint_t *aux)  
    {  
    		int left, right;
    
    		if (!aux)  
    			return (1);
    	
    		right = detection(head, aux->next) ? 1 : 0;  
    		left = ((*head)->n == aux->n ? ((*head) = (*head)->next), 1 : 0);
    	
    		return (left && right ? 1 : 0);  
    }
