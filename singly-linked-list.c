#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node {
    int key; // ����� ��
    struct Node* link; // ���� ��带 ����Ű�� ������
} listNode;

typedef struct Head { 
    struct Node* first; // ù��° ��带 ����Ű�� ������
} headNode;

headNode* initialize(headNode* h);  // ����Ʈ �ʱ�ȭ
int freeList(headNode* h); // ����Ʈ �޸� ����
int insertFirst(headNode* h, int key); // ����Ʈ ó���� ��� ����
int insertNode(headNode* h, int key); // ����Ʈ �߰��� ��� ����
int insertLast(headNode* h, int key); // ����Ʈ �������� ��� ����
int deleteFirst(headNode* h); // ����Ʈ ó�� ��� ����
int deleteNode(headNode* h, int key); // ����Ʈ �߰� ��� ����
int deleteLast(headNode* h); // ����Ʈ ������ ��� ����
int invertList(headNode* h); // ����Ʈ ������
void printList(headNode* h); // ����Ʈ ���

int main() {
    char command;
    int key;
    headNode* headnode = NULL; // ��� ��� ����
    
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
            default: // �� ���� ���ڸ� �Է¹����� �й� �̸� ���
                printf("------------ 2023041018 ������ -------------\n");
                break;
        }
        printf("erase screen . . .");
        Sleep(2000); // 2�� ���
        system("cls");
    } while (command != 'q' && command != 'Q'); // q�� Q�� �Է¹����� ����
    return 1;
}

headNode* initialize(headNode* h) { // ����Ʈ �ʱ�ȭ
    if(h != NULL) freeList(h); // ��� ��尡 NULL�� �ƴϸ� �޸� ����
    headNode* temp = (headNode*)malloc(sizeof(headNode)); // ���ο� ��� ��� ����
    temp->first = NULL; // ��� ����� first�� NULL�� ����
    return temp;
}

int freeList(headNode* h) { // ����Ʈ �޸� ����
    listNode* p = h->first; // p�� ��� ����� first�� ����
    listNode* prevnode = NULL; // ���� ��带 ������ prevnode ����
    while(p != NULL) { // p�� NULL�� �ƴҶ����� �ݺ�
        prevnode = p; // prevnode�� p�� ����
        p = p->link; // p�� p�� link�� ����
        free(prevnode);  // prevnode �޸� ����
    }
    free(h); // ��� ��� �޸� ����
    return 0;
}

int insertFirst(headNode* h, int key) { // ����Ʈ ó���� ��� ����
    if (h == NULL) { // ��� ��尡 NULL�̸�
        printf("Initialize first...\n"); // ���� �ʱ�ȭ�϶�� ���
        return 0;
    }
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // ���ο� ��� ����
    insertnode->key = key; // ��忡 key�� ����
    insertnode->link = h->first; // ����� link�� ��� ����� first�� ����
    h->first = insertnode; // ��� ����� first�� ���ο� ��� ���� = ù��° ��尡 ��
    return 0;
}

int insertNode(headNode* h, int key) { // ����Ʈ �߰��� ��� ����
    if (h == NULL) { // ��� ��尡 NULL�̸�
        printf("Initialize first...\n"); // ���� �ʱ�ȭ�϶�� ���
        return 0;
    }
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // ���ο� ��� ����
    insertnode->key = key; // ��忡 key�� ����
    insertnode->link = NULL; // ����� link�� NULL�� ����
    if (h->first == NULL) { // ��� ����� first�� NULL�̸�
        h->first = insertnode; // ��� ����� first�� ������ ��� ����
        return 0;
    }
    listNode* p = h->first; // p�� ��� ����� first�� ����
    listNode* prevnode = NULL; // ���� ��带 ������ prevnode ����
    while (p != NULL && p->key < key) { // p�� NULL�� �ƴϰ�, p�� key���� �Է¹��� key������ ���������� �ݺ�
        prevnode = p; // prevnode�� p�� ����
        p = p->link; // p�� p�� link�� ����
    }
    if (prevnode == NULL) { // prevnode�� NULL�̸� (= ó���� �����Ҷ�)
        insertnode->link = h->first; // ������ ����� link�� ��� ����� first�� ����
        h->first = insertnode; // ��� ����� first�� ������ ��� ����
    } else { // prevnode�� NULL�� �ƴϸ� (= �߰� �Ǵ� �������� �����Ҷ�)
        insertnode->link = prevnode->link; // ������ ����� link�� prevnode�� link�� ����
        prevnode->link = insertnode; // prevnode�� link�� ������ ��� ����
    }
    return 0;
}

int insertLast(headNode* h, int key) { // ����Ʈ �������� ��� ����
    if(h == NULL) { // ��� ��尡 NULL�̸�
        printf("Initialize first...\n"); // ���� �ʱ�ȭ�϶�� ���
        return 0;
    }
    listNode* insertnode = (listNode*)malloc(sizeof(listNode)); // ���ο� ��� ����
    insertnode->key = key; // ��忡 key�� ����
    insertnode->link = NULL; // ����� link�� NULL�� ����
    if(h->first == NULL) { // ��� ����� first�� NULL�̸� (= ó���� �����Ҷ�)
        h->first = insertnode; // ��� ����� first�� ������ ��� ����
    } else { // ��� ����� first�� NULL�� �ƴϸ� (= �̹� ��尡 ������)
        listNode* p = h->first; // p�� ��� ����� first�� ����
        while(p->link != NULL) { // p�� link�� NULL�� �ƴҶ����� �ݺ�
            p = p->link; // p�� p�� link�� ����
        }
        p->link = insertnode; // p�� link�� ������ ��� ����
    }
    return 0;
}

int deleteFirst(headNode* h) { // ����Ʈ ó�� ��� ����
    if(h == NULL || h->first == NULL) { // ��� ��尡 NULL�̰ų� ��� ����� first�� NULL�̸�
        printf("Nothing to delete...\n"); // ������ ��尡 ���ٰ� ���
        return 0;
    }
    listNode* deletenode = h->first; // ������ ��忡 ��� ����� first�� ����
    h->first = deletenode->link; // ��� ����� first�� ������ ����� link�� ����
    free(deletenode); // ������ ��� �޸� ����
    return 0;
}

int deleteNode(headNode* h, int key) { // ����Ʈ �߰� ��� ����
    if(h == NULL || h->first == NULL) { // ��� ��尡 NULL�̰ų� ��� ����� first�� NULL�̸�
        printf("Nothing to delete...\n"); // ������ ��尡 ���ٰ� ���
        return 0;
    }
    listNode* deletenode = h->first; // ������ ��忡 ��� ����� first�� ����
    listNode* prevnode = NULL; // ���� ��带 ������ prevnode ����
    if(deletenode->key == key) { // ������ ����� key���� �Է¹��� key���� ������
        h->first = deletenode->link; // ��� ����� first�� ������ ����� link�� ����
        free(deletenode); // ������ ��� �޸� ����
        return 0;
    }
    while(deletenode != NULL && deletenode->key != key) { // ������ ��尡 NULL�� �ƴϰ�, ������ ����� key���� �Է¹��� key���� ���� ���������� �ݺ�
        prevnode = deletenode; // prevnode�� ������ ��尪 ����
        deletenode = deletenode->link; // ������ ��忡 ������ ����� link�� ����
    }
    if(deletenode == NULL) { // ������ ��尡 NULL�̸�
        printf("There is no key %d\n", key); // �Է¹��� key���� ���ٰ� ���
        return 0;
    }
    prevnode->link = deletenode->link; // prevnode�� link�� ������ ����� link�� ����
    free(deletenode); // ������ ��� �޸� ����
}

int deleteLast(headNode* h) { // ����Ʈ ������ ��� ����
    if(h == NULL || h->first == NULL) { // ��� ��尡 NULL�̰ų� ��� ����� first�� NULL�̸�
        printf("Nothing to delete...\n"); // ������ ��尡 ���ٰ� ���
        return 0;
    }
    listNode* deletenode = h->first; // ������ ��忡 ��� ����� first�� ����
    listNode* prevnode = NULL; // ���� ��带 ������ prevnode ����
    if(deletenode->link == NULL) { // ������ ����� link�� NULL�̸�
        h->first = NULL; // ��� ����� first�� NULL�� ����
        free(deletenode); // ������ ��� �޸� ����
        return 0;
    }
    while(deletenode->link != NULL) { // ������ ����� link�� NULL�� �ƴҶ����� �ݺ�
        prevnode = deletenode; // prevnode�� ������ ��尪 ����
        deletenode = deletenode->link; // ������ ��忡 ������ ����� link�� ����W
    }
    prevnode->link = NULL; // prevnode�� link�� NULL�� ����
    free(deletenode); // ������ ��� �޸� ����
}

int invertList(headNode* h) { // ����Ʈ ������
    if(h == NULL || h->first == NULL) { // ��� ��尡 NULL�̰ų� ��� ����� first�� NULL�̸�
        printf("Nothing to invert...\n"); // ������ ��尡 ���ٰ� ���
        return 0;
    }
    listNode* p = h->first; // p�� ��� ����� first�� ����
    listNode* q = NULL; // q�� NULL�� ����
    listNode* r = NULL; // r�� NULL�� ����
    while(p != NULL) { // p�� NULL�� �ƴҶ����� �ݺ�
        r = q; // r�� q�� ����
        q = p; // q�� p�� ����
        p = p->link; // p�� p�� link�� ����
        q->link = r; // q�� link�� r�� ����
    }
    h->first = q; // ��� ����� first�� q�� ����
    return 0;
}


void printList(headNode* h) { // ����Ʈ ���
    int i = 0;
    listNode* p; // ��带 ������ p ����
    printf("\nPRINT\n");
    if(h == NULL) { // ��� ��尡 NULL�̸�
        printf("Nothing to print...\n");
        return;
    }
    p = h->first; // p�� ��� ����� first�� ����
    while(p != NULL) { // p�� NULL�� �ƴҶ����� �ݺ�
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->link;
        i++;
    }
    printf("  items = %d\n", i);
}

