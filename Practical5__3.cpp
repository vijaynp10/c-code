#include <iostream>
using namespace std;

class GradeStack {
private:
    static const int MAX = 10;
    double grades[MAX];
    int top;
public:
    GradeStack() : top(-1) {}
    
    void push(double grade) {
        if (top < MAX - 1) {
            grades[++top] = grade;
        } else {
            cout << "Stack is full, can’t add " << grade << endl;
        }
    }
    
    double pop() {
        if (top >= 0) {
            return grades[top--];
        }
        cout << "Stack is empty!" << endl;
        return 0.0;
    }
    
    bool isEmpty() const {
        return top == -1;
    }
};

class GradeQueue {
private:
    static const int MAX = 10;
    double grades[MAX];
    int front;
    int rear;
public:
    GradeQueue() : front(0), rear(-1) {}
    
    void enqueue(double grade) {
        if (rear < MAX - 1) {
            grades[++rear] = grade;
        } else {
            cout << "Queue is full, can’t add " << grade << endl;
        }
    }
    
    double dequeue() {
        if (front <= rear) {
            return grades[front++];
        }
        cout << "Queue is empty!" << endl;
        return 0.0;
    }
    
    bool isEmpty() const {
        return front > rear;
    }
};

int main() {
    GradeStack stack;
    GradeQueue queue;
    
    cout << "Adding grades: 85.5, 92.0, 78.5\n";
    stack.push(85.5);
    stack.push(92.0);
    stack.push(78.5);
    
    queue.enqueue(85.5);
    queue.enqueue(92.0);
    queue.enqueue(78.5);
    
    cout << "\nGrades from stack (last in, first out):\n";
    while (!stack.isEmpty()) {
        double grade = stack.pop();
        cout << "Popped: " << grade << endl;
    }
    
    cout << "\nGrades from queue (first in, first out):\n";
    while (!queue.isEmpty()) {
        double grade = queue.dequeue();
        cout << "Dequeued: " << grade << endl;
    }
    
    return 0;
}