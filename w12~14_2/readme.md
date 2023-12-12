# 이진 탐색 트리
* 탐색 작업을 효율적으로 하기 위한 자료구조
* key(왼쪽서브트리)$<=$ key(루트노드)$<=$ key(오른쪽서브트리)
* 이진탐색을 중위순회하면 오름차순으로 정렬된 값을 얻을 수 있음
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/99c5a0e5-37a3-4471-92b1-b8657a28ce9a)

## 정의
> 모든 원소의 키는 유일한 키를 가짐
> 왼쪽 서브트리 키들은 루트 키보다 작음
> 오른쪽 서브트리 키들은 루트의 키보다 작음
> 왼쪽과 오른쪽 서브트리도 이진트리

* 따라서 찾고자 하는 키값이 이진트리의 루트노드의 킷값과 비교하여 루트노드보다 작으면 원하는 킷값은 왼쪽 서브트리에 존재, 루트노드보다 크면 오른쪽 서브트리에 존재

## 탐색 연산
* 비교한 결과가 같으면 탐색이 성공적으로 끝난다.
* 비교한 결과가, 주어진 키 값이 루트 노드의 키값보다 작으면 탐색은 이 루트 노드의 왼쪽 자식을 기준으로 다시 시작
* 비교한 결과가, 주어진 키 값이 루트 노드의 키값보다 크면 탐색은 이 루트 노드의 오른쪽 자식을 기준으로 다시 시작
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/3ec088d7-473f-4d84-9e0a-1784118d0406)

### 탐색 연산 알고리즘
```
search(root key):
if root==NULL
    return NULL;
if key==KEY(root)
    return root;
    else if key<KEY(root)
        return search(LEFT(root), k);
    else return search(RIGHT(root), k);
```

## 탐색 구현 방법- 순환적 방법
```c
TreeNode *search(TreeNode *node, int key){
    if(node==NULL) return NULL;
    if(key==node->key)return node;
    else if(key<node->key) return search(node->left, key);
    else return search(node->right, key);
}
```

## 탐색 구현 방법- 반복적 방법
```c
TreeNode *search(TreeNode *node, int key){
    while(node!=NULL){
    if(key==node->key) node=node->left;
    else node=node->right;
    }
    return NULL;//탐색 실패
}
```

## 삽입 연산
* 이진 탐색 트리에 원소를 삽입하기 위해서는 먼저 탐색을 수행하는 것이 필요
* 이진 탐색 트리에서는 같은 키값을 갖는 노드가 없어야 하기 때문이고 또한 탐색에 실패한 위치로 새로운 노드를 삽입하는 위치가 됨
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/39dad331-7be8-4f9b-9ab6-cf23e2ae1753)
```c
TreeNode* insert_node(TreeNode* node, int key) {
    //트리가 공백이면 새로운 노드 반환
    if (node == NULL)return new_node(key);

    //그렇지 않으면 순환적으로 트리 내려가기
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
 }
```

### 노드 생성 함수
* 트리가 공백일때 새로운 노드를 반환해주는 함수. 삽입 연산의 유틸리티 함수
```c
TreeNode* new_node(int item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
```

## 노드 삭제연산
* 노드를 삭제하려면 노드를 탐색해야함-> 3가지 경우 발생
1. 삭제하려는 노드가 단말 노드인 경우
2. 삭제하려는 노드가 하나의 왼쪽이나 오른쪽 서브트리 중 하나만 가지고 있는 경우
3. 삭제하려는 노드가 두 개의 서브트리 모두 가지고 있는 경우

### 1. 삭제하려는 노드가 단말 노드인 경우
* 단말 노드 아래에 더이상 노드가 없으므로 단말노드만 지우면 됨
* 즉, 단말노드의 부모노드를 찾아서 부모노드 안의 링크필드를 NULL로 만들어서 연결을 끊으면 됨
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/95ee1f51-71d6-438b-8b54-d946e6a99659)

### 2. 삭제하려는 노드가 하나의 서브트리만 가지고 있는 경우
* 삭제되는 노드가 왼쪽이나 오른쪽 서브트리 중 하나만 가지고 있는 경우에는 자기 노드는 삭제하고 서브트리는 자기 노드의 부모 노드에 붙여주면 됨

### 3. 삭제하려는 노드가 두 개의 서브트리를 가지고 있는 경우
* 삭제 노드와 가장 비슷한 값을 가진 노드를 삭제 노드 위치로 가져옴
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/3b359603-2d62-4282-834f-993f615d5548)
![image](https://github.com/qlkdkd/DataStructure/assets/71871927/75d490fe-447e-441c-917a-b535fd2923c0)
```c
TreeNode* delete_node(TreeNode* root, int key) {
    if (root == NULL)return root;

    //만약 키가 루트보다 작으면 왼쪽 서브트리에 존재
    if (key < root->key)
        root->left = delete_node(root->left, key);

    //만약 키가 루트보다 크면 오른쪽 서브트리에 존재
    else if (key > root->key)
        root->right = delete_node(root->right, key);

    //키가 루트와 같으면 이 노드를 삭제
    else{
        //첫번째나 두번째 경우
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            TreeNode* temp = root->left; 
            free(root);
            return temp;
        }

        //세 번째 경우
        TreeNode* temp = min_value_node(root->right);
        //중위 순회시 후계 노드를 복사
        root->key = temp->key;
        //중위 순회시 후계 노드를 삭제
        root->right = delete_node(root->right, temp->key);
    }
    return root;
```

## 테스트 프로그램
```c
#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct TreeNode {
    element key;
    struct TreeNode* left, * right;
}TreeNode;

//탐색 연산
TreeNode* search(TreeNode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key)return node;
    else if (key < node->key) return search(node->left, key);
    else return search(node->right, key);
}

//노드 생성 연산
TreeNode* new_node(int item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//삽입 연산
TreeNode* insert_node(TreeNode* node, int key) {
    //트리가 공백이면 새로운 노드 반환
    if (node == NULL)return new_node(key);

    //그렇지 않으면 순환적으로 트리 내려가기
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
 }

//최솟값 찾는 함수
TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node;

    //맨 왼쪽 단말 노드 찾으러 내려감
    while (current->left != NULL)
        current = current->left;

    return current;
}

//삭제노드
TreeNode* delete_node(TreeNode* root, int key) {
    if (root == NULL)return root;

    //만약 키가 루트보다 작으면 왼쪽 서브트리에 존재
    if (key < root->key)
        root->left = delete_node(root->left, key);

    //만약 키가 루트보다 크면 오른쪽 서브트리에 존재
    else if (key > root->key)
        root->right = delete_node(root->right, key);

    //키가 루트와 같으면 이 노드를 삭제
    else{
        //첫번째나 두번째 경우
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            TreeNode* temp = root->left; 
            free(root);
            return temp;
        }

        //세 번째 경우
        TreeNode* temp = min_value_node(root->right);
        //중위 순회시 후계 노드를 복사
        root->key = temp->key;
        //중위 순회시 후계 노드를 삭제
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

//중위순회
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("이진 탐색 트리 중위순회 결과\n");
    inorder(root);
    printf("\n\n");
    if (search(root, 30) != NULL)
        printf("이진 탐색 트리에서 30을 발견함\n");
    else printf("이진 탐색 트리에서 30을 발견 못함\n");
    return 0;
}
```
