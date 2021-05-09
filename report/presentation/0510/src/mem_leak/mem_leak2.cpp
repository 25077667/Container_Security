#include <cstdlib>
#include <iostream>
struct List
{
    int value;
    List *next;
    List(int val = 0, List *ptr = nullptr) : value(val), next(ptr) {}
    void append(int val);
    void del(List *entry);
    List *find(int val);
};

void List::append(int val)
{
    List *me = this;
    List **indirect = &me;
    auto new_node = new List(val);

    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

List *List::find(int value)
{
    List *current = this;
    while (current && current->value != value)
        current = current->next;
    return current;
}

void print_list(List *head)
{
    List *current = head;
    while (current)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void List::del(List *entry)
{
    List *head = this;
    List **indirect = &head;
    while ((*indirect) != entry)
        indirect = &(*indirect)->next;
    *indirect = entry->next;
    delete entry;
}

int main(int argc, char const *argv[])
{
    List *head = new List;
    print_list(head);

    head->append(4);
    head->append(3);
    head->append(10);
    head->append(2);
    head->append(7);
    print_list(head);

    head->del(head->find(2));
    head->del(head->find(4));
    print_list(head);
    return 0;
}