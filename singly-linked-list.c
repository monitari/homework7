#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node {
    int key;
    struct Node* link;
} listNode;

typedef struct Head { 
    struct Node* first;
} headNode;

headNode* initialize(headNode* h); 
int freeList(headNode* h);
int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);
void printList(headNode* h);

int main() {
    char command;
    int key;
    headNode* headnode = NULL;
    
    do {
        printf("--------------------------------------------\n");
        printf("            Singly Linked List              \n");
        printf("--------------------------------------------\n");
        printf("Initialize = \tz \t Print = \tp\n");
        printf("Insert Node = \ti \t Delete Node = \td\n");
        printf("Insert Last = \tn \t Delete Last = \te\n");
        printf("Insert First = \tf \t Delete First = t\n");
        printf("Invert List = \tr \t Quit = \tq\n");
        printf("--------------------------------------------\n");
        printf("Command = ");
        scanf(" %c", &command);

        switch (command) {
            case 'z': case 'Z': // z�� Z�� �Է¹����� �ʱ�ȭ
                headnode = initialize(headnode);
                break;
            case 'p': case 'P': // p�� P�� �Է¹����� ���
                printList(headnode);
                break;
            case 'i': case 'I': // i�� I�� �Է¹����� ��� ����
                printf("Your Key = ");
                scanf("%d", &key);
                insertNode(headnode, key);
                break;
            case 'd': case 'D': // d�� D�� �Է¹����� ��� ����
                printf("Your Key = ");
                scanf("%d", &key);
                deleteNode(headnode, key);
                break;
            case 'n': case 'N': // n�� N�� �Է¹����� �������� ��� ����
                printf("Your Key = ");
                scanf("%d", &key);
                insertLast(headnode, key);
                break;
            case 'e': case 'E': // e�� E�� �Է¹����� ������ ��� ����
                deleteLast(headnode);
                break;
            case 'f': case 'F': // f�� F�� �Է¹����� ó���� ��� ����
                printf("Your Key = ");
                scanf("%d", &key);
                insertFirst(headnode, key);
                break;
            case 't': case 'T': // t�� T�� �Է¹����� ó�� ��� ����
                deleteFirst(headnode);
                break;
            case 'r': case 'R': // r�� R�� �Է¹����� ����Ʈ ������
                invertList(headnode);
                break;
            case 'q': case 'Q': // q�� Q�� �Է¹����� ����
                break;
            default:
                printf("------------ 2023041018 ������ -------------\n");
                break;
        }
        printf("erase screen . . .");
        Sleep(2000); // 2�� ���
        system("cls");
    } while (command != 'q' && command != 'Q');
    return 1;
}

headNode* initialize(headNode* h) {
    if(h != NULL) freeList(h);
    headNode* temp = (headNode*)malloc(sizeof(headNode));
    temp->first = NULL;
    return temp;
}

int freeList(headNode* h) {
    listNode* p = h->first;
    listNode* prev = NULL;
    while(p != NULL) {
        prev = p;
        p = p->link;
        free(prev);
    }
    free(h);
    return 0;
}

int insertFirst(headNode* h, int key) {
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // ���ο� ��� ����
    insertnode->key = key; // ��忡 key�� ����
    insertnode->link = h->first; // ����� link�� ��� ����� first�� ����
    h->first = insertnode; // ��� ����� first�� ���ο� ��� ���� = ù��° ��尡 ��
    return 0;
}

int insertNode(headNode* h, int key) {
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // ���ο� ��� ����
    listNode* p; // ���� ���
    insertnode->key = key; // ��忡 key�� ����
    insertnode->link = NULL; // ����� link�� NULL�� ����
    if(h->first == NULL) { // ��� ����� first�� NULL�̸�
        h->first = insertnode; // ��� ����� first�� ���ο� ��� ����
        return 0;
    }
    p = h->first; // ���� ��忡 ��� ����� first�� ����
    while(p->link != NULL) { // ���� ����� link�� NULL�� �ƴ� ������
        p = p->link; // ���� ��忡 ���� ����� link�� ����
    } // ���� ��尡 ������ ��尡 ��
    p->link = insertnode; // ���� ����� link�� ���ο� ��� ����
    return 0;
}


int insertLast(headNode* h, int key) {
    insertNode(h, key);
    return 0;
}

int deleteFirst(headNode* h) {
    return 0;
}

int deleteNode(headNode* h, int key) {
    return 0;
}

int deleteLast(headNode* h) {
    return 0;
}

int invertList(headNode* h) {
    return 0;
}


void printList(headNode* h) {
    int i = 0;
    listNode* p;
    printf("\nPRINT\n");
    if(h == NULL) {
        printf("Nothing to print....\n");
        return;
    }
    p = h->first;
    while(p != NULL) {
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->link;
        i++;
    }
    printf("  items = %d\n", i);
}

