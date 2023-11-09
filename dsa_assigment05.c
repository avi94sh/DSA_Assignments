#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VERTICES 6

struct adjacency_list_node
{
    char node_name;
    struct adjacency_list_node* next_node;
};

struct graph_node
{
    char node_name;
    struct graph_node** ptr;
};

struct vertex_array_node
{
    char node_name;
    struct adjacency_list_node* list_base_addr;
    struct graph_node* node_addr;
    struct vertex_array_node* next_node;
};

struct adjacency_list_node* al_head = NULL;
struct adjacency_list_node* al_tail = NULL;

struct vertex_array_node* va_head = NULL;
struct vertex_array_node* va_tail = NULL;
struct vertex_array_node* temp_va_tail = NULL;

void create_vertex_array(struct vertex_array_node* new_node)
{
    if (va_head == va_tail)
    {
        va_tail = new_node;
        temp_va_tail = va_tail;
    }
    else
    {
        temp_va_tail->next_node = new_node;
        temp_va_tail = new_node;
    }
}

void create_adjacency_linked_list(struct adjacency_list_node* new_node, struct vertex_array_node* vertex_node_addr)
{
    if (al_head == al_tail)
    {
        vertex_node_addr->list_base_addr = new_node;
        al_tail = new_node;
    }
    else
    {
        al_tail->next_node = new_node;
        al_tail = new_node;
    }
}

void traverse_adjacency_list(struct adjacency_list_node* base_addr)
{
    while (base_addr != NULL)
    {
        printf("%c -> ", base_addr->node_name);
        base_addr = base_addr->next_node;
    }

    printf("NULL");
}

void add_edge(struct graph_node* src_node, struct graph_node* dst_node)
{
}

int main()
{
    srand(time(NULL));
    int is_edge;
    struct adjacency_list_node* new_al_node = NULL;
    struct graph_node* new_graph_node = NULL;
    struct vertex_array_node* new_va_node = NULL;

    temp_va_tail = va_tail;

    for (size_t i = 0; i < NUM_VERTICES; i++)
    {
        new_va_node = (struct vertex_array_node*)calloc(1, sizeof(struct vertex_array_node));
        new_va_node->node_name = (65 + i);
        new_graph_node = (struct graph_node*)calloc(1, sizeof(struct graph_node));
        new_graph_node->node_name = (65 + i);
        new_va_node->node_addr = new_graph_node;
        create_vertex_array(new_va_node);

        al_head = NULL;
        al_tail = NULL;

        for (size_t j = 0; j < NUM_VERTICES; j++)
        {
            if (i == j)
                continue;
            else
            {
                is_edge = rand() % 2;

                if (is_edge == 1)
                {
                    new_al_node = (struct adjacency_list_node*)calloc(1, sizeof(struct adjacency_list_node));
                    new_al_node->node_name = (65 + j);
                    create_adjacency_linked_list(new_al_node, new_va_node);
                }
            }
        }
    }

    printf("Following is the information about the graph to be constructed\n\n");

    temp_va_tail = va_tail;
    while (temp_va_tail != NULL)
    {
        printf("Adjacency List of Node %c is: ", temp_va_tail->node_name);
        traverse_adjacency_list(temp_va_tail->list_base_addr);
        printf("\n");
        temp_va_tail = temp_va_tail->next_node;
    }

    temp_va_tail = va_tail;

    for (size_t i = 0; i < NUM_VERTICES; i++)
    {
        al_tail = temp_va_tail->list_base_addr;

        printf("Edges of Node %c are: ", temp_va_tail->node_name);

        while (al_tail != NULL)
        {
            printf("%c ", al_tail->node_name);
            al_tail = al_tail->next_node;
        }

        printf("\n");

        temp_va_tail = temp_va_tail->next_node;
    }

    return 0;
}
