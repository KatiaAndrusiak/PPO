#ifndef intArrayList_h
#define intArrayList_h
void bubbleSort(int arr[], int n);
class IntArrayList{
public:
    IntArrayList(int MaxSize);
    IntArrayList();
    void add(int a);
    void add(int* array, int s);
    void add(const int index, int new_a);
    void add(int a, bool zm);
    void print();
    int find(int b);
    void printFind(int b);
    void remove(int b);
    void remove(int b, int n);
private:
     int size;
     int maxSize;
     int *tab;
};

#endif