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
            case 'z': case 'Z': // z나 Z를 입력받으면 초기화
                headnode = initialize(headnode);
                break;
            case 'p': case 'P': // p나 P를 입력받으면 출력
                printList(headnode);
                break;
            case 'i': case 'I': // i나 I를 입력받으면 노드 삽입
                printf("Your Key = ");
                scanf("%d", &key);
                insertNode(headnode, key);
                break;
            case 'd': case 'D': // d나 D를 입력받으면 노드 삭제
                printf("Your Key = ");
                scanf("%d", &key);
                deleteNode(headnode, key);
                break;
            case 'n': case 'N': // n나 N를 입력받으면 마지막에 노드 삽입
                printf("Your Key = ");
                scanf("%d", &key);
                insertLast(headnode, key);
                break;
            case 'e': case 'E': // e나 E를 입력받으면 마지막 노드 삭제
                deleteLast(headnode);
                break;
            case 'f': case 'F': // f나 F를 입력받으면 처음에 노드 삽입
                printf("Your Key = ");
                scanf("%d", &key);
                insertFirst(headnode, key);
                break;
            case 't': case 'T': // t나 T를 입력받으면 처음 노드 삭제
                deleteFirst(headnode);
                break;
            case 'r': case 'R': // r나 R를 입력받으면 리스트 뒤집기
                invertList(headnode);
                break;
            case 'q': case 'Q': // q나 Q를 입력받으면 종료
                break;
            default:
                printf("------------ 2023041018 김준후 -------------\n");
                break;
        }
        printf("erase screen . . .");
        Sleep(2000); // 2초 대기
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
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드 생성
    insertnode->key = key; // 노드에 key값 저장
    insertnode->link = h->first; // 노드의 link에 헤드 노드의 first값 저장
    h->first = insertnode; // 헤드 노드의 first에 새로운 노드 저장 = 첫번째 노드가 됨
    return 0;
}

int insertNode(headNode* h, int key) {
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드 생성
    listNode* p; // 현재 노드
    insertnode->key = key; // 노드에 key값 저장
    insertnode->link = NULL; // 노드의 link에 NULL값 저장
    if(h->first == NULL) { // 헤드 노드의 first가 NULL이면
        h->first = insertnode; // 헤드 노드의 first에 새로운 노드 저장
        return 0;
    }
    p = h->first; // 현재 노드에 헤드 노드의 first값 저장
    while(p->link != NULL) { // 현재 노드의 link가 NULL이 아닐 때까지
        p = p->link; // 현재 노드에 현재 노드의 link값 저장
    } // 현재 노드가 마지막 노드가 됨
    p->link = insertnode; // 현재 노드의 link에 새로운 노드 저장
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

