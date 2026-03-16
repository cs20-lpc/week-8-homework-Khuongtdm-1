#include <iostream>
#include "StackFactory.hpp"

int main()
{
    Stack<int> * mystack = StackFactory<int>::GetStack();
    mystack->push(1);
    mystack->push(2);
    mystack->push(3);
    mystack->push(4);
    mystack->push(5);
    mystack->pop();
    mystack->pop();
    mystack->pop();
    mystack->push(6);
    mystack->push(7);
    cout << mystack->getLength();
 

    Stack<int> * shouldCreateArraystack = StackFactory<int>::GetStack(5);
    shouldCreateArraystack->push(1);
    shouldCreateArraystack->push(2);
    shouldCreateArraystack->push(3);
    shouldCreateArraystack->push(4);
    shouldCreateArraystack->push(5);
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->pop();
    shouldCreateArraystack->push(6);
    shouldCreateArraystack->push(7);
    cout << " " << shouldCreateArraystack->getLength();
    //shouldCreateArraystack->print();

    //cout << "\n=========== Basic operator (including copy constructor) and some edge case ===========" << endl;
    //Stack<int> * s1 = StackFactory<int>::GetStack(); // Linked stacks don't need a fixed size

    //cout << "Is empty? " << (s1->isEmpty() ? "Yes" : "No") << endl;
    //s1->push(10);
    //s1->push(20);
    //s1->push(30);
    //cout << "Stack 1 after 3 pushes:" << endl;
    //s1->print();

    //Stack<int> * s2 = s1; // Copy constructor
    //cout << "Stack 2 after copy by construction:" << endl;
    //s2->print();

    //cout << "Clear stack 2:" << endl;
    //s2->clear();
    //cout << "Stack 2 after clear: ";
    //s2->print();

    //cout << "\n================================ Peek and Pop ================================" << endl;
    //try {
    //    cout << "Top element (peek): " << s1->peek() << endl;
    //    s1->pop();
    //    cout << "After 1 pop, top is: " << s1->peek() << endl;

    //    s1->pop();
    //    s1->pop();

    //    cout << "Attempting underflow pop..." << endl;
    //    s1->pop(); // This should trigger the catch block
    //}
    //catch (string e) {
    //    cout << "Caught expected error: " << e << endl;
    //}

    //cout << "\n=========================== Rotational function ===========================" << endl;
    //Stack<int>* s3 = StackFactory<int>::GetStack();
    //Stack<int>* s4 = StackFactory<int>::GetStack();
    //s3->push(1);
    //s3->push(2);
    //s3->push(3);
    //s3->push(4);
    //s3->push(5);

    //s3->print();
    //s3->rotate(Stack<int>::RIGHT);

    //s3->print();

    //s4->push(1);
    //s4->push(2);
    //s4->push(3);
    //s4->push(4);
    //s4->push(5);

    //s4->print();
    //s4->rotate(Stack<int>::LEFT);
    //s4->print();


    return 0;

}