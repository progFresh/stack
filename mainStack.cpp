#include <iostream>

struct Data {
public:
	int num; 
	char symbol;
};

struct StackElement {
public:
	Data data;
	StackElement* previous;
};

struct Stack {
public:
	int count; //Количество элементов стека
	StackElement* last; // Указатель на конец стека
};

Stack* createStack() {
	Stack* stack = new Stack;
	stack->count = 0; 
	stack->last = NULL;
	return stack;
}

void push(Stack* stack, Data data) {
	StackElement* element = new StackElement;
	element->data = data;
	element->previous= NULL;
	if (stack->count == 0) {
		element->previous = NULL;
		stack->last = element;
	} else {
		element->previous = stack->last;
		stack->last = element;
	}
	stack->count++;
};

Data pop(Stack* stack) {
	if (stack->count == 0) throw "Empty stack!";
	StackElement* element = stack->last;
	Data data = element->data; 
	stack->last = stack->last->previous;
	delete (element);
	stack->count--; //Количество элементов дека меньше на 1
	return data;
}

void clearStack(Stack* stack) {
	while (stack->count != 0) {
		pop(stack); //Удаляем элемент из дека
	}
	delete(stack);
}


int main(int argc, char **argv) {
	Stack* stack = createStack();
	for (int i = 0; i < 3; i++) {
		Data data;
		data.num = 10 + i;
		data.symbol = 'a' + i;
		push(stack, data);
	}
	clearStack(stack);

	system("PAUSE");

	return 0;
}