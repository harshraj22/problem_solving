// https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1

/*
struct node{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
};
*/
struct node*update(struct node*start,int p) {
    struct node* tail = start;
    while(tail->next != nullptr)
        tail = tail->next;
        
    node* head = start;
    head->prev = tail;
    tail->next = head;
    
    while(p--)
        start = start->next;
        
    start->prev->next = nullptr;
    start->prev = nullptr;
    
    return start;
}