//
// Created by 권한길 on 2019/11/05.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

//순환적인 탐색 함수
TreeNode  *search(TreeNode  *node,  int  key)
{
    if ( node == NULL )  return NULL;
    if ( key == node->key ) return node;   //  (1)
    else if ( key < node->key )
        return  search(node->left, key);    // (2)
    else
    return  search(node->right, key); // (3)
}

TreeNode * new_node(int item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
TreeNode * insert_node(TreeNode * node, int key)
{
    // 트리가 공백이면 새로운 노드를 반환한다.
    if (node == NULL) return new_node(key);

    // 그렇지 않으면 순환적으로 트리를 내려간다.
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    // 변경된 루트 포인터를 반환한다.
    return node;
}

TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;

    // 맨 왼쪽 단말 노드를 찾으러 내려감
    while (current->left != NULL)
        current = current->left;

    return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
// 새로운 루트 노드를 반환한다.
TreeNode * delete_node(TreeNode * root, int key)
{
    if (root == NULL) return root;

    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
    if (key < root->key)
        root->left = delete_node(root->left, key);
        // 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    // 키가 루트와 같으면 이 노드를 삭제하면 됨
    else {
        // 첫 번째나 두 번째 경우
        if (root->left == NULL) {
            TreeNode * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        // 세 번째 경우
        TreeNode * temp = min_value_node(root->right);

        // 중외 순회시 후계 노드를 복사한다.
        root->key = temp->key;
        // 중외 순회시 후계 노드를 삭제한다.
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}


// 중위 순회
void inorder( TreeNode *root ){
if ( root ){
inorder( root->left );	// 왼쪽서브트리 순회
printf("%d\t", root->key ); 	// 노드 방문
inorder( root->right );	// 오른쪽서브트리 순회
}
}
// 전위 순회
void preorder( TreeNode *root ){
if ( root ){
printf("%d\t", root->key ); 	// 노드 방문
preorder( root->left );	// 왼쪽서브트리 순회
preorder( root->right );	// 오른쪽서브트리 순회
}
}

// 후위 순회
void postorder( TreeNode *root ){
if ( root ){
postorder( root->left );	// 왼쪽 서브 트리 순회
postorder( root->right );	// 오른쪽 서브 트리 순회
printf("%d\t", root->key ); 	// 노드 방문
}
}



void menu()
{
    printf("\n");
    printf("------------------------------------\n");
    printf("1. 삽입\n");
    printf("2. 삭제\n");
    printf("3. 중위순회\n");
    printf("4. 전위순회\n");
    printf("5. 후위순회\n");
    printf("6. 레벨순회\n");
    printf("7. 탐색\n");
    printf("8. 종료\n");
    printf("------------------------------------\n");

}

// ================ 원형큐 코드 시작 =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode * element;
typedef struct { // 큐 타입
    element  data[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
// 공백 상태 검출 함수
void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
void level_order(TreeNode *ptr)
{
    QueueType q;

    init_queue(&q);	 // 큐 초기화

    if (ptr == NULL) return;
    enqueue(&q, ptr);
    while (!is_empty(&q)) {
        ptr = dequeue(&q);
        printf(" [%d] ", ptr->key);
        if (ptr->left)
            enqueue(&q, ptr->left);
        if (ptr->right)
            enqueue(&q, ptr->right);
    }
}



int main() {
int num;
    TreeNode * root = NULL;
    TreeNode * tmp = NULL;


int value;
while(num!=8) {
    menu();
    scanf("%d",&num);
    switch (num) {
        case 1:
            printf(">>");
            scanf("%d", &value);
            root = insert_node(root, value);

            break;
        case 2:
            printf(">>");
            scanf("%d",&value);
            root=delete_node(root,value);
            break;
        case 3:
            printf("중위순회\n");
            inorder(root);
            break;
        case 4:
            printf("전위순회\n");
            preorder(root);
            break;
        case 5:
            printf("후위순회\n");
            postorder(root);
            break;
        case 6:
            printf("탐색\n");
            level_order(root);
            break;
        case 7:
            printf(">>");
            scanf("%d",&value);

            if (search(root, value) != NULL)
                printf("이진 탐색 트리에서 %d을 발견함 \n",value);
            else
                printf("이진 탐색 트리에서 %d을 발견못함 \n",value);
            break;



        default:
            break;


    }
}




    printf("종료 \n");

    return 0;

}