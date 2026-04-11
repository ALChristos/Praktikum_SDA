// // #include <iostream>
// // #define MAX 100
// // using namespace std;
// // int stack[MAX];
// // int top = -1;

// // //PUSH
// // void push(int value) {
// // if (top >= MAX - 1) {
// // cout << "Stack overflow" << endl;
// // }
// // else {
// // top++;
// // stack[top] = value;
// // cout << value << " pushed into stack" << endl;
// // }
// // }

// // //POP
// // int pop() {
// // if (top < 0) {
// // cout << "Stack underflow" << endl;
// // return -1;
// // }
// // else {
// // int value = stack[top];
// // top--;
// // return value;
// // }
// // }

// // //PEEK
// // int peek() {
// // if (top < 0) {
// // cout << "Stack is empty" << endl;
// // return -1;
// // }
// // else {
// // return stack[top];
// // }
// // }

// // //IS EMPTY
// // bool isEmpty() {
// // return (top < 0);
// // }

// // int main(){
// //     cout << peek();
// // }

#include <iostream>
#define MAX 100
using namespace std;
int queue[MAX];
int front = -1, rear = -1;
bool isFull() {
// Jika posisi rear sudah di indeks terakhir (MAX-1), maka penuh
return rear == MAX - 1;
}
bool isEmpty() {
// Kosong jika front masih -1 ATAU front sudah melewati
// posisi rear (setelah banyak dequeue)
return front == -1 || front > rear;
}

void enqueue(int value) {
// jika queue full hentikan program
if (isFull()) {
cout << "Queue overflow" << endl;
return;
}
// Jika elemen pertama masuk, set front
// ke indeks 0 agar queue aktif
if (front == -1) {
front = 0;
}
rear++; // Geser posisi rear ke kanan untuk tempat elemen baru
queue[rear] = value; // Masukkan nilai ke posisi rear yang baru
cout << value << " enqueued into queue" << endl;
}


