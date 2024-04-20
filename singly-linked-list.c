#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node {
    int key; // 노드의 값
    struct Node* link; // 다음 노드를 가리키는 포인터
} listNode;

typedef struct Head { 
    struct Node* first; // 첫번째 노드를 가리키는 포인터
} headNode;

headNode* initialize(headNode* h);  // 리스트 초기화
int freeList(headNode* h); // 리스트 메모리 해제
int insertFirst(headNode* h, int key); // 리스트 처음에 노드 삽입
int insertNode(headNode* h, int key); // 리스트 중간에 노드 삽입
int insertLast(headNode* h, int key); // 리스트 마지막에 노드 삽입
int deleteFirst(headNode* h); // 리스트 처음 노드 삭제
int deleteNode(headNode* h, int key); // 리스트 중간 노드 삭제
int deleteLast(headNode* h); // 리스트 마지막 노드 삭제
int invertList(headNode* h); // 리스트 뒤집기
void printList(headNode* h); // 리스트 출력

int main() {
    char command;
    int key;
    headNode* headnode = NULL; // 헤드 노드 선언
    
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
            default: // 그 외의 문자를 입력받으면 학번 이름 출력
                printf("------------ 2023041018 김준후 -------------\n");
                break;
        }
        printf("erase screen . . .");
        Sleep(2000); // 2초 대기
        system("cls");
    } while (command != 'q' && command != 'Q'); // q나 Q를 입력받으면 종료
    return 1;
}

headNode* initialize(headNode* h) { // 리스트 초기화
    if(h != NULL) freeList(h); // 헤드 노드가 NULL이 아니면 메모리 해제
    headNode* temp = (headNode*)malloc(sizeof(headNode)); // 새로운 헤드 노드 생성
    temp->first = NULL; // 헤드 노드의 first에 NULL값 저장
    return temp;
}

int freeList(headNode* h) { // 리스트 메모리 해제
    listNode* p = h->first; // p에 헤드 노드의 first값 저장
    listNode* prevnode = NULL; // 이전 노드를 저장할 prevnode 선언
    while(p != NULL) { // p가 NULL이 아닐때까지 반복
        prevnode = p; // prevnode에 p값 저장
        p = p->link; // p에 p의 link값 저장
        free(prevnode);  // prevnode 메모리 해제
    }
    free(h); // 헤드 노드 메모리 해제
    return 0;
}

int insertFirst(headNode* h, int key) { // 리스트 처음에 노드 삽입
    if (h == NULL) { // 헤드 노드가 NULL이면
        printf("Initialize first...\n"); // 먼저 초기화하라고 출력
        return 0;
    }
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드 생성
    insertnode->key = key; // 노드에 key값 저장
    insertnode->link = h->first; // 노드의 link에 헤드 노드의 first값 저장
    h->first = insertnode; // 헤드 노드의 first에 새로운 노드 저장 = 첫번째 노드가 됨
    return 0;
}

int insertNode(headNode* h, int key) { // 리스트 중간에 노드 삽입
    if (h == NULL) { // 헤드 노드가 NULL이면
        printf("Initialize first...\n"); // 먼저 초기화하라고 출력
        return 0;
    }
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드 생성
    insertnode->key = key; // 노드에 key값 저장
    insertnode->link = NULL; // 노드의 link에 NULL값 저장
    if (h->first == NULL) { // 헤드 노드의 first가 NULL이면
        h->first = insertnode; // 헤드 노드의 first에 삽입할 노드 저장
        return 0;
    }
    listNode* p = h->first; // p에 헤드 노드의 first값 저장
    listNode* prevnode = NULL; // 이전 노드를 저장할 prevnode 선언
    while (p != NULL && p->key < key) { // p가 NULL이 아니고, p의 key값이 입력받은 key값보다 작을때까지 반복
        prevnode = p; // prevnode에 p값 저장
        p = p->link; // p에 p의 link값 저장
    }
    if (prevnode == NULL) { // prevnode가 NULL이면 (= 처음에 삽입할때)
        insertnode->link = h->first; // 삽입할 노드의 link에 헤드 노드의 first값 저장
        h->first = insertnode; // 헤드 노드의 first에 삽입할 노드 저장
    } else { // prevnode가 NULL이 아니면 (= 중간 또는 마지막에 삽입할때)
        insertnode->link = prevnode->link; // 삽입할 노드의 link에 prevnode의 link값 저장
        prevnode->link = insertnode; // prevnode의 link에 삽입할 노드 저장
    }
    return 0;
}

int insertLast(headNode* h, int key) { // 리스트 마지막에 노드 삽입
    if(h == NULL) { // 헤드 노드가 NULL이면
        printf("Initialize first...\n"); // 먼저 초기화하라고 출력
        return 0;
    }
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // 새로운 노드 생성
    insertnode->key = key; // 노드에 key값 저장
    insertnode->link = NULL; // 노드의 link에 NULL값 저장
    if(h->first == NULL) { // 헤드 노드의 first가 NULL이면 (= 처음에 삽입할때)
        h->first = insertnode; // 헤드 노드의 first에 삽입할 노드 저장
    } else { // 헤드 노드의 first가 NULL이 아니면 (= 이미 노드가 있을때)
        listNode* p = h->first; // p에 헤드 노드의 first값 저장
        while(p->link != NULL) { // p의 link가 NULL이 아닐때까지 반복
            p = p->link; // p에 p의 link값 저장
        }
        p->link = insertnode; // p의 link에 삽입할 노드 저장
    }
    return 0;
}

int deleteFirst(headNode* h) { // 리스트 처음 노드 삭제
    if(h == NULL || h->first == NULL) { // 헤드 노드가 NULL이거나 헤드 노드의 first가 NULL이면
        printf("Nothing to delete...\n"); // 삭제할 노드가 없다고 출력
        return 0;
    }
    listNode* deletenode = h->first; // 삭제할 노드에 헤드 노드의 first값 저장
    h->first = deletenode->link; // 헤드 노드의 first에 삭제할 노드의 link값 저장
    free(deletenode); // 삭제할 노드 메모리 해제
    return 0;
}

int deleteNode(headNode* h, int key) { // 리스트 중간 노드 삭제
    if(h == NULL || h->first == NULL) { // 헤드 노드가 NULL이거나 헤드 노드의 first가 NULL이면
        printf("Nothing to delete...\n"); // 삭제할 노드가 없다고 출력
        return 0;
    }
    listNode* deletenode = h->first; // 삭제할 노드에 헤드 노드의 first값 저장
    listNode* prevnode = NULL; // 이전 노드를 저장할 prevnode 선언
    if(deletenode->key == key) { // 삭제할 노드의 key값이 입력받은 key값과 같으면
        h->first = deletenode->link; // 헤드 노드의 first에 삭제할 노드의 link값 저장
        free(deletenode); // 삭제할 노드 메모리 해제
        return 0;
    }
    while(deletenode != NULL && deletenode->key != key) { // 삭제할 노드가 NULL이 아니고, 삭제할 노드의 key값이 입력받은 key값과 같지 않을때까지 반복
        prevnode = deletenode; // prevnode에 삭제할 노드값 저장
        deletenode = deletenode->link; // 삭제할 노드에 삭제할 노드의 link값 저장
    }
    if(deletenode == NULL) { // 삭제할 노드가 NULL이면
        printf("There is no key %d\n", key); // 입력받은 key값이 없다고 출력
        return 0;
    }
    prevnode->link = deletenode->link; // prevnode의 link에 삭제할 노드의 link값 저장
    free(deletenode); // 삭제할 노드 메모리 해제
}

int deleteLast(headNode* h) { // 리스트 마지막 노드 삭제
    if(h == NULL || h->first == NULL) { // 헤드 노드가 NULL이거나 헤드 노드의 first가 NULL이면
        printf("Nothing to delete...\n"); // 삭제할 노드가 없다고 출력
        return 0;
    }
    listNode* deletenode = h->first; // 삭제할 노드에 헤드 노드의 first값 저장
    listNode* prevnode = NULL; // 이전 노드를 저장할 prevnode 선언
    if(deletenode->link == NULL) { // 삭제할 노드의 link가 NULL이면
        h->first = NULL; // 헤드 노드의 first에 NULL값 저장
        free(deletenode); // 삭제할 노드 메모리 해제
        return 0;
    }
    while(deletenode->link != NULL) { // 삭제할 노드의 link가 NULL이 아닐때까지 반복
        prevnode = deletenode; // prevnode에 삭제할 노드값 저장
        deletenode = deletenode->link; // 삭제할 노드에 삭제할 노드의 link값 저장W
    }
    prevnode->link = NULL; // prevnode의 link에 NULL값 저장
    free(deletenode); // 삭제할 노드 메모리 해제
}

int invertList(headNode* h) { // 리스트 뒤집기
    if(h == NULL || h->first == NULL) { // 헤드 노드가 NULL이거나 헤드 노드의 first가 NULL이면
        printf("Nothing to invert...\n"); // 뒤집을 노드가 없다고 출력
        return 0;
    }
    listNode* p = h->first; // p에 헤드 노드의 first값 저장
    listNode* q = NULL; // q에 NULL값 저장
    listNode* r = NULL; // r에 NULL값 저장
    while(p != NULL) { // p가 NULL이 아닐때까지 반복
        r = q; // r에 q값 저장
        q = p; // q에 p값 저장
        p = p->link; // p에 p의 link값 저장
        q->link = r; // q의 link에 r값 저장
    }
    h->first = q; // 헤드 노드의 first에 q값 저장
    return 0;
}


void printList(headNode* h) { // 리스트 출력
    int i = 0;
    listNode* p; // 노드를 저장할 p 선언
    printf("\nPRINT\n");
    if(h == NULL) { // 헤드 노드가 NULL이면
        printf("Nothing to print...\n");
        return;
    }
    p = h->first; // p에 헤드 노드의 first값 저장
    while(p != NULL) { // p가 NULL이 아닐때까지 반복
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->link;
        i++;
    }
    printf("  items = %d\n", i);
}

