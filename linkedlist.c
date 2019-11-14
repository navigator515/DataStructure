#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link; //next Node Pointer
} ListNode;

//add Node at first list
// insert have to distribute first and middle position
ListNode* insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *) malloc(sizeof(ListNode)); //allocate dynamic memory
    p->data = value; //  insert value to data
    p->link = NULL; // insert address of head
    head = p; // link
    return head;
}
//insert function at middle position
    ListNode *insert(ListNode *head, int pos, element value) {

     ListNode *p = (ListNode *) malloc(sizeof(ListNode)); //memory allocation
     ListNode *Temp=head; //Temp Pointer asign
     int count=0; //length of linkedlist
     ListNode *countNode; //count of Node
     countNode=head;
     while(countNode->link!=NULL) // until last Node
     {
       countNode=countNode->link;
         count++;
     }
    printf("%d번째 %d를 삽입합니다.\n", pos, value);
    if(count+2<pos) // exception case
     {
         printf("위치오류\n");
         return head;
     }
     else//normal case
         {
         p->data = value; //insert value
         int i;
         for (i = 0; i < pos - 2; i++)
             Temp = Temp->link; //(3)

         p->link = Temp->link;
         Temp->link = p;
         return head;
     }
    }
//delete_first fuction
    ListNode *delete_first(ListNode *head) {

        ListNode *removed; //Remove Node pointer
        if (head == NULL) return NULL; //zero node//exection case

        removed = head;
        head = removed->link; //delete
        free(removed);

        return head;
    }
// delete at middle
    ListNode *delete(ListNode *head, int pos) {

    ListNode *pre = head;
    ListNode *remove = head;
    int i;
    printf("%d번째를 삭제합니다.\n", pos);
    if (pos == 1) //first node delete case
    {
        ListNode *removed;
        if (head == NULL) return NULL;
        removed = head;
        head = removed->link;
        free(removed);
        return head;
    } else {
        for (i=0; i < pos - 2; i++) {
            pre = pre->link;
            remove = remove->link;
        }
        remove = remove->link;
        pre->link = pre->link->link;
        free(remove); // memory return
        return head;
    }

}

//from front print function
    void print_list(ListNode *head) {
    ListNode *p;
    for (p = head; p != NULL; p = p->link)//until last node
            printf("%d->", p->data);
        printf("NULL \n");
    }

    //find value of position fuction
    void get_entry(ListNode *head, int pos)
    {
    ListNode *entry;
    entry=head;
    int i;
    for(i=0;i<pos-1;i++) {
        entry = entry->link;
    }
    printf("%d번째 값은 %d 입니다.\n",pos, (entry->data));
    }



//whether empty or not  function
    int is_empty(ListNode *head)
    {

      if(head==NULL)
          return 1;
      else
          return 0;
    }

//node init function
ListNode* clear(ListNode *head)
{
printf("리스트를 초기화 합니다\n");
  while(head!=NULL)
  {
      head=delete_first(head);
  }
return head;
}

    int main(void)
    {
        ListNode *head = NULL;
        head = insert_first(head, 10); print_list(head);
        head = insert(head, 2, 20); print_list(head);
        head = insert(head, 3, 30); print_list(head);
        head = insert(head, 4, 40); print_list(head);
        head = insert(head, 5, 50); print_list(head);
        head = insert(head, 8, 60); print_list(head);
        head = delete_first(head); print_list(head);
        head = delete(head, 1); print_list(head);
        get_entry(head, 3);
        head = clear(head);
        if (is_empty(head)) printf("리스트가 비어있습니다.\n");
        return 0;


    }

