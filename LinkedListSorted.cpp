typedef struct NODE {
    int data;
    struct NODE *next;
}NODE;

class List
{
private:
    NODE *head,*tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value);
    void push(int value);
    void insertAt(int pos, int value);
    void display();
    int pop();
    int delete_last();
    int deleteAt(int pos);
    int peek();
    bool isEmpty();
    int getSize();
    void reverse();
    void quickSort();

    NODE *getHead() const;

    void setHead(NODE *head);

    NODE *getTail() const;

    void setTail(NODE *tail);
};

void List::display() {
    NODE *temp = new NODE;
    temp=head;
    while(temp!= nullptr) {
        std::cout << temp->data << std::endl;
        temp=temp->next;
    }
}
// Insert a node at the end of the list
void List::insert(int value) {
    NODE *temp = new NODE; // Create new temporary NODE pointer
    temp->data=value; // Assign the data to the temp node
    temp->next= nullptr; // next is null
    if(head == nullptr) { // if this is first node, point head and tail to it
        head=temp; // head points to temp if temp is first node
        tail=temp; // move tail pointer on the end node, being inserted at the end, it's the last one
        temp = nullptr; // temp does not point anywhere
    }
    else
    {
         // next link of tail pointer (last element in list) points to the new node
        tail->next = temp; // move tail pointer to the newly created node, as that's the last node now
        tail=temp;
    }
}
// Push a node at the front of the list
void List::push(int value) {
    NODE *temp = new NODE;
    temp->data = value; // assign data
    temp->next = nullptr;
    if(head == 0) {
        head = temp;
        tail = temp;

    }
    else {
        temp->next = head;
        head = temp;
    }
}

void List::insertAt(int pos, int value) {
    NODE *pre = new NODE;
    NODE *cur = new NODE;
    NODE *temp = new NODE;
    cur = head; // current node is the first node in list
    for(int i=1; i<pos;i++) { // reach the node at the position we want
        pre=cur; // move previous to current
        cur=cur->next; // move current pointer to next node
    }
    temp->data = value; // assign value
    pre->next = temp; // point last node pointer to the newly created node
    temp->next = cur; // point the newly created node to current node (which is the node at the position after the position we inserted in)
}

int List::pop() {
    int data;
    NODE *temp = new NODE;
    temp = head; // Move temp pointer on head (first element)
    data = temp->data; // extract data from first node
    head=head->next; // move head pointer to the next node so we can delete temp(which is the original first node)
    delete temp; // delete original first node
    return data;
}

int List::peek() {
    int data;
    NODE *temp = new NODE;
    temp = head; // Move temp pointer on head (first element)
    if(head != nullptr) {
        data = temp->data; // extract data from first node
    }
    else {
        data = -1;
    }
    temp= nullptr;
    delete temp;
    return data;
}

int List::delete_last() {
    int data;
    NODE *current = new NODE;
    NODE *previous = new NODE;
    current = head; // current pointer is on the head node (first node)
    while(current->next != nullptr) { // iterate through the list until we reach the node before last
        previous = current; // assign previous as current, so we can move current to last node
        current = current->next; // move current to last node
    }
    data = current->data;
    tail=previous; // tail is now moved on previous, which is the node before last originally (we're deleting the last so newly last node will be the node before last)
    previous->next = nullptr; // the new previous points to null as it's the last element and this is not a circular list
    delete current; // delete node
    return data;
}

int List::deleteAt(int pos) {
    int data;
    NODE *previous = new NODE;
    NODE *current = new NODE;
    current=head;
    for(int i=0; i<pos; i++) {
        previous = current;
        current=current->next;
    }
    data = current->data;
    previous->next = current->next;
    delete current;
    return data;
}

bool List::isEmpty() {
    if(head == nullptr) {
        return true;
    }
    return false;
}

int List::getSize() {
    int size = 0;
    NODE *temp = new NODE;
    temp = head;
    while(temp != nullptr) {
        size++;
        temp = temp->next;
    }
    temp = nullptr;
    delete temp;
    return size;
}

void List::reverse() {
    List *reversed = new List;
    NODE *temp = new NODE;
    temp = head;
    while(temp != nullptr) {
        reversed->push(temp->data);
        temp = temp->next;
    }
    head = reversed->getHead();
    temp = nullptr;
    delete temp;
}

NODE *List::getHead() const {
    return head;
}

void List::setHead(NODE *head) {
    List::head = head;
}

NODE *List::getTail() const {
    return tail;
}

void List::setTail(NODE *tail) {
    List::tail = tail;
}

void swap(int*a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

NODE *Partition(NODE *head, NODE *end, NODE **newHead, NODE **newEnd) {
    NODE *pivot = end;
    NODE *prev = nullptr;
    NODE *cur = head;
    NODE *tail = pivot;
    while(cur != pivot) {
        if(cur->data <pivot->data) {
            if((*newHead) == nullptr) {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if(prev) {
                prev->next = cur->next;
            }
            NODE *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if((*newHead) == nullptr) {
        (*newHead) = pivot;
    }
    (*newEnd) = tail;
    return pivot;
}
NODE *getTailLIST(struct NODE *cur)
{
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}
NODE *quickSortR(NODE *head, NODE *end) {
    if(!head || head == end) {
        return head;
    }
    NODE *newHead = nullptr;
    NODE *newEnd = nullptr;

    NODE *pivot = Partition(head,end,&newHead,&newEnd);

    if (newHead != pivot) {
        NODE *tmp = newHead;
        while(tmp->next != pivot) {
            tmp=tmp->next;
        }
        tmp->next= nullptr;

        newHead = quickSortR(newHead,tmp);
        tmp = getTailLIST(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortR(pivot->next, newEnd);
    return newHead;
}

void List::quickSort() {
        this->head = quickSortR(this->head, getTailLIST(this->head));
        return;
}
