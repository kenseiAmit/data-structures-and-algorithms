# include <iostream>

using namespace std;

template<class t>
class stack {
private:
  t *values;
  int size;
  int top;
public:
  stack() { size = 10; top = -1; values = new t[size];}
  stack(int size) {this->size = size; top = -1, values = new t[size];}
  void push(t value);
  t pop();
  t peek(int index);
  void display();
  int stacktop();
  int is_empty();
  int is_full();
};

template<class t>
void stack<t>::push(t value) {
  if(is_full())
    cout<<"Stack overflow!\n";
  else
    values[++top] = value;
}

template<class t>
t stack<t>::pop() {
  if(is_empty()) {
    cout<<"The stack is empty.\n";
    return -1;
  }
  else
    return values[top--];
}

template<class t>
t stack<t>::peek(int index) {
  if(index < 0 || index > top) {
    cout<<"Please enter a valid index.\n";
    return (t)-1;
  }
  else {
    return values[top-index];
  }
}

template<class t>
int stack<t>::stacktop() {
  if(is_empty())
    return -1;
  else
    return values[top];
}

template<class t>
int stack<t>::is_full() {
  return top == size - 1;
}

template<class t>
int stack<t>::is_empty() {
  return top == -1;
}

template<class t>
void stack<t>::display() {
  for(int navigator = top; navigator > -1; navigator--) {
    cout<<values[navigator]<<endl;
  }
}

int main(int argc, char const *argv[]) {
  stack<char> stk(12);

  stk.push('a');
  stk.push('b');
  stk.push('3');
  stk.push('4');
  stk.push('5');
  stk.push('6');

  stk.display();

  cout<<stk.peek(5);
  cout<<stk.pop();

  //cout<<stk.peek(0)<<endl;
  return 0;
}
