#ifndef intLinkedList_h
#define intLinkedList_h

class Element{
public:
    int value;
    Element *next;
};

class IntLinkedList {
public:
    IntLinkedList();
    int size();

private:
    Element *head;
    Element *tail;
};
#endif