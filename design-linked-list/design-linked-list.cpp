struct Node
{
    int val;
    Node *prev, *next;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node *prev, Node *next) : val(x), prev(prev), next(next) {}
};

class MyLinkedList
{
public:
    Node *head;
    int size = -1;

    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = nullptr;
    }
    
    ~MyLinkedList(){
        if (head) delete head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index > size) return -1;
        Node *it = head;
        for (int i = 0; i < index; i++){
            it = it->next;
        }
        return it->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (head)
        {
            Node *newHead = new Node(val, nullptr, head);
            head->prev = newHead;
            head = newHead;
        }
        else
        {
            head = new Node(val);
        }
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (!head)
        {
            addAtHead(val);
            return;
        }
        else{
            Node *it = head;
            while (it->next){
                it = it->next;  
            } 
            Node *newTail = new Node(val, it, nullptr);
            it->next = newTail;
        }
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if(index == size + 1){
            addAtTail(val);
        }
        else if (index > size)
            return;
        else if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            Node *it = head;
            for (int i = 0; i < index; i++) it = it->next;
            Node *newNode = new Node(val, it->prev, it);
            it->prev->next = newNode;
            it->prev = newNode;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index > size)
            return;

        if (index == 0)
        {
            head = head->next;
        }
        else
        {
            Node *it = head;

            for (int i = 0; i < index; i++)
            {
                it = it->next;
            }

            Node *temp = it;

            if (index == size)
            {
                it->prev->next = nullptr;
            }
            else
            {
                it->prev->next = it->next;
                it->next->prev = it->prev;
            }
            delete temp;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */