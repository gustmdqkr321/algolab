#include <iostream>
using namespace std;


struct node
{
 int data; // 노드에 저장되는 정수 데이터
 struct node* left; // 왼쪽 서브트리
 struct node* right; // 오른쪽 서브트리
 node(int data) : data(data), left(NULL), right(NULL) {}
};

void insert(struct node** root, int data)
{
    if(*root == NULL) // 처음이거나 리프노드일때(인서트 반복해서 계속 리프쪽으로 내려가는 구조 마지막엔 새로 만들어서 리프에 다는방식임)
    {
        *root = new node(data); // 새로 생성
        return;
    }
    if((*root)->data > data) // 데이터가 루트보다 작으면 왼쪽
    {
        insert(&(*root)->left, data); // 왼쪽으로 루트를 바꿔서 인서트
    }
    else if((*root)->data < data) // 데이터가 루트보다 클떈 오른쪽
    {
        insert(&(*root)->right, data); // 오른쪽으로 루트를 바꿔서 인서트
    }
}
void preOrder(struct node* root)
{
    if(root == NULL) // 리프에서 끝내는 코드 pre, in, post동일
    {
        return;
    }
    cout << root->data << " ";  // 루트, 왼,오
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left); // 왼, 루트, 오
    cout << root->data << " ";
    inOrder(root->right);
}
void postOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left); // 왼, 오, 루트
    postOrder(root->right);
    cout << root->data << " ";
}
int size(struct node* root) // 노드의 개수
{
    if(root == NULL) // 리프에서 더 내려가면 종료
    {
        return 0; // 더 내려가면 null이므로 0을 더함
    }
    else
    {
        return size(root->left) + size(root->right) + 1; // 리프부터 1씩더해서 위로 쌓아올리고 올라가면 왼,오의 합에 본인값 1을 더함
    }
}
int height(struct node* root) // 높이
{
    if(root == NULL)
    {
        return -1; // 관점에 따라 0이될수도 있음 루트일때의 높이 밑에서 1이 더해지므로 0이거나 1로 시작
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1; // 왼, 오중 더 높은 높이에 본인 1을 더함
    }
}
int sumOfWeight(struct node* root) // 순회하면서 데이터 값 더하는 방식
{
    if(root == NULL)
    {
        return 0; // 순회와 동일
    }
    else
    {
        return sumOfWeight(root->left) + sumOfWeight(root->right) + root->data; // 왼,오,본인 더하기
    }
}
int maxPathWeight(struct node* root) // 가장 큰 데이터를 가지는 루트
{
    if(root == NULL)
    {
        return 0; // 여기서 root->data가 아닌 이유 null이면 data값이 없고 밑에서 더하기 때문
    }
    else
    {
        return max(maxPathWeight(root->left),maxPathWeight(root->right)) + root->data; //왼,오중 더 큰 값에 본인 값을 더해서 위로 올림
    }
}
void mirror(struct node** root) // 뒤집기
{
    if(*root == nullptr)
    {
        return;
    }
    else
    {
        node* temp = (*root)->left; // 순서는 상관없이 순회와 동일한 방법으로 본인의 왼,오만 바꾸면 됨
        (*root)->left = (*root)->right;
        (*root)->right = temp;
        mirror(&(*root)->left);
        mirror(&(*root)->right);
    }
}
void destruct(struct node** root)
{
    if(*root == nullptr)
    {
        return;
    }
    else
    {
        destruct(&(*root)->left); // 순회하면서 다 삭제 반드시 post의 순서로 해야 밑에서부터 다 해제 가능
        destruct(&(*root)->right);  // post가 아니면 루트만 헤제되고 리프는 남아있을 수 있음
        delete(*root);
        *root = nullptr;
    }
}


int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력
    int num; // 트리에 입력할 수의 개수
    int data; // 트리에 입력할 수
    for (int i=0; i<t; i++)
    {
        struct node* root = NULL;
        cin >> num;
        for(int j=0; j<num; j++)
        {
            cin >> data;
            insert(&root, data);
        }
        cout << size(root) << endl;
        cout << height(root) << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root) << endl;
        mirror(&root);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        destruct(&root);
        if (root == NULL)
        {
        printf("0\n");
        }
        else
        {
        printf("1\n");
        }
    }

	return 0;
}