#include <iostream>
#include <stdlib.h>

#define MAX 20

using namespace std;

int n, arr[100];
int op, cont;
int top = -1, *stack1;
int queue_array[MAX], rear = -1, front = -1;

struct node {
    int info;
    node* link;
};

node* start = NULL;

void traverse() {
    node* temp;
    if (start == NULL)
        cout << "\nList is empty\n";
    else {
        temp = start;
        while (temp != NULL) {
            cout << "Data = " << temp->info << endl;
            temp = temp->link;
        }
    }
}

void insertAtFront() {
    int data;
    node* temp;
    temp = new node;
    cout << "\nEnter number to be inserted: ";
    cin >> data;
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd() {
    int data;
    node* temp, *head;
    temp = new node;
    cout << "\nEnter number to be inserted: ";
    cin >> data;
    temp->link = NULL;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition() {
    node* temp, *newnode;
    int pos, data, i = 1;
    newnode = new node;
    cout << "\nEnter position and data: ";
    cin >> pos >> data;
    temp = start;
    newnode->info = data;
    newnode->link = NULL;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deleteFirst() {
    node* temp;
    if (start == NULL)
        cout << "\nList is empty\n";
    else {
        temp = start;
        start = start->link;
        delete temp;
    }
}

void deleteEnd() {
    node* temp, *prevnode;
    if (start == NULL)
        cout << "\nList is Empty\n";
    else {
        temp = start;
        while (temp->link != NULL) {
            prevnode = temp;
            temp = temp->link;
        }
        delete temp;
        prevnode->link = NULL;
    }
}

void deletePosition() {
    node* temp, *position;
    int i = 1, pos;
    if (start == NULL)
        cout << "\nList is empty\n";
    else {
        cout << "\nEnter index: ";
        cin >> pos;
        position = new node;
        temp = start;
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        delete position;
    }
}

void maximum() {
    int a[10];
    int i;
    node* temp;
    if (start == NULL)
        cout << "\nList is empty\n";
    else {
        temp = start;
        int max = temp->info;
        while (temp != NULL) {
            if (max < temp->info)
                max = temp->info;
            temp = temp->link;
        }
        cout << "\nMaximum number is: " << max << " ";
    }
}





void mean() {
    node* temp;
    node* start = NULL;
    // If LL is empty
    if (start == NULL)
        cout << "\nList is empty\n";

    // Otherwise
    else {
        temp = start;
        
        // Stores the sum and count of elements in the LL
        int sum = 0, count = 0;
        float m;

        // Traverse the LL
        while (temp != NULL) {
            // Update the sum
            sum = sum + temp->info;
            temp = temp->link;
            count++;
        }

        // Find the mean
        m = static_cast<float>(sum) / count;

        // Print the mean value
        cout << "\nMean is " << m << endl;
    }
}

void sort() {
    node* current = start;
    node* index = NULL;
    int temp;

    // If LL is empty
    if (start == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            index = current->link;
            while (index != NULL) {
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
            current = current->link;
        }
    }
}

void reverseLL() {
    node *t1, *t2, *temp;
    t1 = t2 = NULL;
    if (start == NULL)
        cout << "List is empty\n";
    else {
        while (start != NULL) {
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        temp = start;

        cout << "Reversed linked list is: ";
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->link;
        }
        cout << endl;
    }
}

void llmu() {
    int choice;

    cout << "\n\t1  To see list\n";
    cout << "\t2  For insertion at starting\n";
    cout << "\t3  For insertion at end\n";
    cout << "\t4  For insertion at any position\n";
    cout << "\t5  For deletion of first element\n";
    cout << "\t6  For deletion of last element\n";
    cout << "\t7  For deletion of element at any position\n";
    cout << "\t8  To find maximum among the elements\n";
    cout << "\t9  To find mean of the elements\n";
    cout << "\t10 To sort element\n";
    cout << "\t11 To reverse the linked list\n";
    cout << "\t12 To exit\n";
    
label2:
    cout << "\nEnter Choice :\n";
    cin >> choice;
    
    switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            maximum();
            break;
        case 9:
            mean();
            break;
        case 10:
            sort();
            break;
        case 11:
            reverseLL();
            break;
        case 12:
            return;
        default:
            cout << "Incorrect Choice\n";
    }
    goto label2;
}

void queuemenu() {
    cout << "Perform operations on queue\n";
    cout << "------------------------------\n";
    cout << "\tMenu";
    cout << "\n------------------------------\n";
    cout << "1. Insert element \n";
    cout << "2. Delete element \n";
    cout << "3. Display queue\n";
    cout << "4. Exit\n";
    cout << "------------------------------\n";
    
    int ch;
    while (true) {
        cout << "Choose operation: ";
        cin >> ch;
        
        switch (ch) {
            case 1:
                insert1();
                break;
            case 2:
                delete1();
                break;
            case 3:
                display1();
                break;
            case 4:
                return;
            default:
                cout << "Invalid operation \n";
        }
    }
}

void insert1() {
    int add_item;
    if (rear == MAX - 1)
        cout << "Queue Overflow \n";
    else {
        if (front == -1) {
            /* If queue is initially empty */
            front = 0;
        }
        cout << "\nEnter element: ";
        cin >> add_item;
        cout << "\n" << add_item << " is inserted in queue\n";
        cout << "------------------------------\n";
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void delete1() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow \n";
        return;
    } else {
        cout << "\nElement deleted from queue is: " << queue_array[front] << "\n";
        cout << "------------------------------\n";
        front = front + 1;
    }
}

void display1() {
    if (front == -1)
        cout << "Queue is empty \n";
    else {
        cout << "\nQueue is: ";
        for (int i = front; i <= rear; i++)
            cout << queue_array[i] << " ";
        cout << "\n------------------------------";
        cout << "\n";
    }
}

int SSmenu() {
    do {
        int n;
        int i=0;
        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter values of array:\n";
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Enter sorting algorithm to use:\n1: Bubble\n2: Insertion\n3: Quick sort\n4: Merge sort\n";
        cin >> op;

        switch (op) {
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                break;
            case 3:
                quickSort(arr, 0, n - 1);
                break;
            case 4:
                mergeSort(arr, 0, n - 1);
                break;
            default:
                cout << "Invalid option!";
        }
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nContinue? 1/0: ";
        cin >> cont;
    } while (cont == 1);

    return 0;
}

void push(int x) {
    if (top == n - 1)
        return;
    stack1[++top] = x;
}

int pop() {
    if (top == -1)
        return -1;
    return stack1[top--];
}

int peek() {
    if (top == -1)
        return -1;
    return stack1[top];
}

void display() {
    for (int i = top; i > -1; i--)
        cout << stack1[i] << " ";
    cout << "\n\n";
}

void stam() {
    n = 10;
    cout << "-------------------------------------\n\n";
    cout << "Initializing the stack with size 10\n\n";

    stack1 = (int *)malloc(n * sizeof(int));

    cout << "Pushing elements into the stack\n1\n2\n3\n\n";

    push(1);
    push(2);
    push(3);

    cout << "Displaying elements of the stack -\n";

    display();

    cout << "The top of the stack = " << peek() << "\n\n";

    cout << "Pop the top of the stack = " << pop() << "\n\n";
    cout << "Pop the top of the stack = " << pop() << "\n\n";

    cout << "Displaying elements of the stack -\n";

    display();
    cout << "-------------------------------------\n\n";
}

int partition(int arr[], int offset, int size) {
    int x = arr[size];
    int i = offset - 1;
    int j;
    int temp;
    for (j = offset; j < size; j++) {
        if (arr[j] <= x) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[size];
    arr[size] = temp;
    return i + 1;
}

void merge(int arr[], int offset, int mid, int size) {
    int n1 = mid - offset + 1;
    int n2 = size - mid;
    int *l = (int *)calloc(n1 + 1, sizeof(int));
    int *r = (int *)calloc(n2 + 1, sizeof(int));
    int i, j, k;
    for (i = 0; i < n1; i++) {
        l[i] = arr[offset + i];
    }
    for (j = 0; j < n2; j++) {
        r[j] = arr[mid + j + 1];
    }
    l[n1] = 32767;
    r[n2] = 32767;
    i = j = 0;
    for (k = offset; k <= size; k++) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
    }
    free(l);
    free(r);
}

void mergeSort(int arr[], int offset, int size) {
    if (offset < size) {
        int mid = (offset + size) / 2;
        mergeSort(arr, offset, mid);
        mergeSort(arr, mid + 1, size);
        merge(arr, offset, mid, size);
    }
}

void quickSort(int arr[], int offset, int size) {
    int pivot;
    if (offset < size) {
        pivot = partition(arr, offset, size);
        quickSort(arr, offset, pivot - 1);
        quickSort(arr, pivot + 1, size);
    }
}

void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        for (j = i; j > 0 && arr[j - 1] > key; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = key;
    }
}

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int SandS() {
    cout << "\n**********************\n";
    cout << "SEARCHING AND SORTING";
    cout << "\n**********************\n";
    cout << "Searching Algorithms are designed to check for an element or \nretrieve an element from any data structure where it is used.\nBased on the type of operations these algorithms are generally \nclassified into two categories: ";
    cout << "\n\n1. Sequential Search: In this, the list or array is traversed \nsequentially and every element is checked. For example: Linear Search.\n";
    cout << "\n2. Interval Search: These algorithms are specifically designed for \nsearching in sorted data-structures. These type of searching algorithms \nare much more efficient than Linear Search as they repeatedly target the center \nof the search structure and divide the search space in half.\nFor Example: Binary Search.";
    cout << "\n\nA Sorting Algorithm is used to rearrange a given array or list \nelements according to a comparison operator on the elements. The comparison \noperator is used to decide the new order of element in the respective data \nstructure.";
    cout << "Basic types of sorting algorithms are: 1. Selection Sort \n2. Bubble Sort \t3. Recursive Bubble Sort \t4. Insertion Sort \t5. Recursive Insertion Sort \n6. Merge Sort \t7. Iterative Merge Sort \t8. Quick Sort" << endl;
    cin.get();  // waits for user input
}

int stack() {
    cout << "\n\n\n*******************\n";
    cout << "Stack Data Structure";
    cout << "\n*******************\n";
    cout << "Stack is a linear data structure which follows a particular order in \nwhich the operations are performed. The order may be LIFO(Last In First Out) \nor FILO(First In Last Out).";
    cout << "\nBasic stack operations are: 1. createStack \n2. push \t3. pop \t4. peek \t5. isEmpty \t6. size ";
    cout << "\n\nWorking of Stack Data Structure The operations work as follows:\n1. A pointer called TOP is used to keep track of the top element \nin the stack.\n2. When initializing the stack, we set its value to -1 so that we \ncan check if the stack is empty by comparing TOP == -1.\n3. On pushing an element, we increase the value of TOP and place \nthe new element in the position pointed to by TOP.\n4. On popping an element, we return the element pointed to by TOP \nand reduce its value.\n5. Before pushing, we check if the stack is already full\n6. Before popping, we check if the stack is already empty\n";
    cin.get();  // waits for user input
}

int queue() {
    cout << "\n\n\n*******************\n";
    cout << "Queue Data Structure";
    cout << "\n*******************\n";
    cout << "Like Stack, Queue is a linear structure which follows a particular order \nin which the operations are performed. The order is First In First Out (FIFO).  \nA good example of queue is any queue of consumers for a resource where the consumer \nthat came first is served first.";
    cout << "The difference between stacks and queues is in removing. \n\nIn a stack we remove the item the most recently added; in a queue, \nwe remove the item the least recently added.";
    cout << "A queue is open at both ends. One end is provided for the \ninsertion of data and the other end for the deletion of data.\n";
    cout << "\nA queue can be implemented with any programming language \nsuch as C, Java, Python, etc.\n";
    cout << "In order to insert the element (enqueue), we need to check \nwhether the queue is already full i.e. check the condition \nfor Overflow. If the queue is not full, we have to increment the value of the Rear \nindex by 1 and place the element at the position of the Rear pointer variable.\n";
    cin.get();  // waits for user input
}
int ll() {
    cout << "\n**********************\n";
    cout << "LINKED LIST DATA STRUCTURE";
    cout << "\n**********************\n";
    cout << "Like arrays, Linked List is a linear data structure. \nUnlike arrays, linked list elements are not stored at a \ncontiguous location; the elements are linked using pointers.";
    cout << "\n\nAdvantages over arrays: \n1) Dynamic size \n2) Ease of insertion/deletion \n\nDrawbacks: \nRandom access is not allowed. \nExtra memory space for a pointer is required with each element of the list.\n";
    cout << "Not cache friendly. Since array elements are contiguous locations, \nthere is locality of reference which is not there in case of linked lists.";
    cout << "Representation: \nA linked list is represented by a pointer to the first node of the linked list. \n\nThe first node is called the head. If the linked list is empty, \nthen the value of the head is NULL. ";
    cout << "\nEach node in a list consists of at least two parts: \n1) data \t2) Pointer (Or Reference) to the next node ";
    cin.get();  // waits for user input
}

int tree() {
    cout << "\n\n\n*******************\n";
    cout << "TREE DATA STRUCTURE";
    cout << "\n*******************\n";
    cout << "A tree is a nonlinear hierarchical data structure that consists of nodes connected by edges.\n";
    cout << "Other data structures such as arrays, linked list, stack, and queue are linear data \nstructures that store data sequentially. \n\nIn order to perform any operation in a linear \ndata structure, the time complexity increases with the increase in the data size. But, it \nis not acceptable in today's computational world.";
    cout << "Different tree data structures allow quicker \nand easier access to the data as it is a non-linear data structure. \n\nTree Terminologies: \n1. Node-A node contains a key or value and pointers to its child nodes.\n";
    cout << "2. Edge: It is the link between any two nodes. \n3. Root: It is the topmost node of a tree. \n4. Height of a Node: The number of edges from the node to the deepest leaf \n";
    cin.get();  // waits for user input
}

int main() {
    int a;
label:
    cout << "\n\n______________________________________\n\n";
    cout << "ENTER YOUR CHOICE(Enter just number): \n";
    cout << "______________________________________\n\n";
    cout << "*******\n";
    cout << "THEORY: \n";
    cout << "*******\n";
    cout << "\n1. Searching and sorting \n2. Stacks \n3. Queue\n4. Linked List \n5. Trees\nChoice-";
    cout << "\n\n*********\n";
    cout << "PRACTICAL: \n";
    cout << "*********\n";
    cout << "\n6. Searching and sorting \n7. Stacks \n8. Queue\n9. Linked List \n10. Exit\nChoice-";
    cin >> a;
    switch (a) {
        case 1:
            SandS();
            break;
        case 2:
            stack();
            break;
        case 3:
            queue();
            break;
        case 4:
            ll();
            break;
        case 5:
            tree();
            break;
        case 6:
            // Implement Searching and Sorting practical menu
            break;
        case 10:
            return 0;
            break;
        case 7:
            // Implement Stacks practical menu
            break;
        case 8:
            // Implement Queue practical menu
            break;
        case 9:
            // Implement Linked List practical menu
            break;
        default:
            break;
    }
    goto label;  // it is generally better to use loops instead of goto
}