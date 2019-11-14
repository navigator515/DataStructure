
//
// Created by 권한길 on 2019/10/17.
//

#include <stdio.h>
#include <stdlib.h>



typedef int element;
//type definition Node
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;
void print_list(ListNode* head);
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//add node at first
ListNode* insert_first(ListNode* head, element value)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = value;//insert value

    if(head==NULL)//노드가 0개인 경
    {
    head=node;
    node->link=node;
    }
    else
    {
        node->link=head->link;
        head->link=node;

    }
printf("첫번째에 %d를 삽입합니다.\n",value);
   // print_list(head);
    return head; // 변경된 헤드 포인터를 반환한다.
}


//insert function at last position
ListNode* insert_last(ListNode* head, element value)
{
    ListNode *node = (ListNode *) malloc(sizeof(ListNode)); //memory allocation
    ListNode *first=head;
    first=first->link;
    node->data=value;

    node->link=first;
    head->link=node;
    head=node;
printf("마지막에 %d를 삽입합니다.\n",value);
    return head;	// 변경된 헤드 포인터를 반환한다.
}

//insert at middle
ListNode *insert(ListNode *head, int pos, element value) {

    ListNode *node = (ListNode *) malloc(sizeof(ListNode)); //memory allocation
    node->data=value;
    ListNode *Temp=head;//Temp Pointer asign
ListNode *cp=head;
    int count=0;
    int i;

    do{
        cp=cp->link;
        count++;
    }
   while(cp!=head);


       if(count>pos) //노드 중간에 삽입하는 경
       {
           int i;

           for (i = 0; i < pos - 1; i++)// 삽입할 노드의 전노드로 간
           {
               Temp = Temp->link;
           }
           //이것도 마지막
           node->link = Temp->link;
           Temp->link = node;
           head = node;
           printf("%d번쨰에 %d를 삽입합니다.\n", pos, value);
       }
       else
           {
           printf("%d번쨰에 %d를 삽입합니다.\n", pos, value);
           printf("마지막에 %d를 삽입합니다.\n",value);
         // head=insert_last(head,value);
               ListNode *first=head;
               first=head->link;

               head->link=node;
               node->link=first;
               head=node;
       }
return head;
}


//delete at first
ListNode* delete_first(ListNode *head)
{
    ListNode *p;

    p=head->link;
    head->link=p->link;
    free(p);
    printf("첫번째에 노드를 삭제합니다.\n");



    return head;
}
// delete at middle function
ListNode *delete(ListNode *head, int pos) {
  ListNode *pre=head;
  int i;
  printf("%d번를 삭제합니다.\n",pos);
  for(i=0;i<pos-1;i++)
  {
      pre=pre->link;
  }

  pre->link=pre->link->link;

  return head;
}

//print fuction from first Node
void print_list(ListNode* head)
{
    ListNode *p=head;


  do{

        p = p->link; //push head to first
      printf("%d->",p->data);
    }while(p!=head);//  출력
    printf("\n");// 마지막 노드
}


//find this(x) value
void search(ListNode* head,element x) {
    ListNode *p = head;
    p=p->link;

    while (p != head) {
        if (p->data == x) {
            printf("%d를 찾았습니다.\n", x);
        break;
        }
        p = p->link;

    }
}

//find and print especially value
void get_entry(ListNode *head, int pos)
{

    ListNode *entry;
    entry=head;
    entry=entry->link;
    int i;
    for(i=0;i<pos-1;i++) {
        entry = entry->link;

    }

    printf("%d번째 값은 %d 입니다.\n",pos, (entry->data));

}

//clear Node
ListNode* clear(ListNode *head)
{
    printf("리스트를 초기화 합니다.\n");

    ListNode *p=head;

while(p->link!=p)
{
    p=head->link;
    head->link=p->link;
    free(p);
}
head=NULL;
    return head;

}

//whether empty or not  function
int is_empty(ListNode *head)
{

    if(head==NULL)
        return 1;
    else
        return 0;
}


int main(void) {
    ListNode *head = NULL;
    head = insert_first(head, 10);print_list(head);
    head = insert(head, 2, 20); print_list(head);
    head = insert(head, 3, 30); print_list(head);
    head = insert(head, 4, 40); print_list(head);
    head = insert(head, 5, 50); print_list(head);
    head = insert(head, 8, 60); print_list(head);
    head = insert_last(head, 70); print_list(head);
    head = delete_first(head); print_list(head);
    head = delete(head, 1); print_list(head);
    search(head, 30);
    get_entry(head, 3);
    head = clear(head);
    if (is_empty(head)) printf("리스트가 비어있습니다.\n");
    return 0;
}



