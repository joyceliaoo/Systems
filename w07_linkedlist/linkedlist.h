struct node {char cargo[20]; struct node *next;};
void print_list(struct node *target);
struct node * insert_front(struct node * head, char * new_cargo);
struct node * free_list(struct node * head);
