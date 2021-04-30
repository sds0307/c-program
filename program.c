#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char *string;
    struct list *next;
};

typedef struct list LIST;

int main(int argc, char* argv[]) {
    char fileName[100];
    char number[100];
    char line[256];

    LIST *current, *head, *prev, *tail;
    head = current = prev = tail = NULL;

    printf( "File Name: ");
    gets( fileName );

    FILE* file = fopen(fileName, "r");

    while (fgets(line, sizeof(line), file)) {
        
        LIST *node = malloc(sizeof(LIST));

        line[strcspn(line, "\n")] = 0;
        node->string = strdup(line);
        node->next =NULL;

        if(head == NULL){
            current = head = tail = node;
        } else {
            tail = current = current->next = node;
        }
    }

    fclose(file);

    for(current = head; current ; current=current->next){
        printf("%s -> ", current->string);
    }
    printf("NULL\n");

    printf( "Enter a number: "); 
    gets( number );

    prev= tail;

    for(current = head; current ; current=current->next){
        if(strcmp(current->string, number) == 0) {
            break;
        }
        prev = current;
    }

    if(current == NULL) {
        printf("Number not found");
        return 0;
    }

    
    tail->next = head;
    head = current;
    tail = prev;
    tail->next = NULL;

    for(current = head; current ; current=current->next){
        printf("%s -> ", current->string);
    }
    printf("NULL\n");

    return 0;
}
