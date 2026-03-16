template <typename T>
LinkedListStack<T>::LinkedListStack()
{
    top = nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack

    Node<T>* curr = top;
    while(curr != nullptr) {
        Node<T>* temp = curr; 
        curr = curr->next;    
        delete temp;          
    }
    top = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    this->top = nullptr;
    this->length =0;
    if (copyObj.top == nullptr) return;
    this->top = new Node<T>(copyObj.top->data);
    this->length++;
    Node<T>* sourHead = copyObj.top->next;
    Node<T>* destHead = this->top;
    while (sourHead != nullptr)
    {
        Node* newNode = new Node<T>(sourHead->data);
        destHead->next = newNode;
        sourHead = sourHead->next;
        destHead = destHead->next;
        this->length++;
    }
    destHead->next = nullptr;

    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()) throw string("Stack is empty");
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()) throw string("Stack is empty");
    Node<T>* curr = top;
    top = top->next;
    delete curr;
    curr = nullptr;
    this->length--;

}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (this->length <2)
    {
        throw string("invalid length");
    }

    if (dir == LEFT)
    {
        Node<T>* oldTop = top;
        top = top->next;
        
        Node<T>* curr = top;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = oldTop;
        oldTop->next = nullptr;
    }
    if (dir == RIGHT)
    {
        Node<T>* curr =top;
        Node<T>* prev =top;
        curr = curr->next;
        while(curr->next !=nullptr)
        {
            prev=prev->next;
            curr=curr->next;
        }
        curr->next =top;
        top = curr;
        prev->next=nullptr;

    }

}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
