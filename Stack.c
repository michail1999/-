#include <stdio.h>
#define MY_SIZE 10000
int count = 0;
int my_stack[MY_SIZE];
int check_full() {
    if (count == MY_SIZE) return 1;
    else return 0;
}
int check_empty() {
    if (count == 0) return 1;
    else return 0;
}
void push(int n) {
    if (check_full() == 1) return;
    my_stack[count] = n;
    count++;
    return;
}
void pop() {
    if (check_empty() == 1) return;
    my_stack[count - 1] = 0;
    count--;
}
int top() {
    return my_stack[count - 1];
}
int size() {
    return count;
}
int main(){
    push(7);
    push(10);
    push(14);
    push(28);
    printf("Top element = %d\n", top());
    printf("Size = %d\n", size());
    pop();
    printf("Top element = %d\n", top());
    printf("Size = %d\n", size());
    pop();
    pop();
    pop();
    printf("Top element = %d\n", top());
    printf("Size = %d\n", size());
    return 0;
}
