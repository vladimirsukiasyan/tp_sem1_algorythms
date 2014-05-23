#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Stack
{
public:
	Stack(int size);
	~Stack();
	void push(int val);
	int pop();
    int getHead();
    bool isEmpty();
private:
    char *stack;
	int size;
	int head;
	void doubleBuf();
};

Stack::Stack(int size): size(size), head(0)
{
    stack = new char[size];
}

Stack::~Stack()
{
    delete[] stack;
}

void Stack::push(int val)
{
	if (head < size)
		stack[head++] = val;
	else
		doubleBuf();
}

int Stack::pop()
{
	if (not isEmpty())
		return stack[--head];
    else return 0;
}

bool Stack::isEmpty()
{
	return (head) ? false : true;
}

void Stack::doubleBuf()
{
    char *temp = new char[2 * size];
	for (int i = 0; i < size; ++i)
		temp[i] = stack[i];
	size *= 2;
	delete[] stack;
	stack = temp;
}

int Stack::getHead()
{
    return stack[head - 1];
}

string makePolish(string statement, Stack &stack);

int countPolish(string statement, Stack &stack);

int main(void)
{
	Stack stack(10);
	string statement;
    getline(cin, statement);
    statement = makePolish(statement, stack);
    cout << countPolish(statement, stack) << endl;
	return 0;
}

string makePolish(string statement, Stack &stack)
{
    string result = "";
    string::const_iterator iter;
    char stackHead = 0;
    for (iter = statement.begin(); iter != statement.end(); ++iter)
    {
        while (*iter == ' ')
            ++iter;

        if (isdigit(*iter))
        {
            while (isdigit(*iter))
            {
                result.append(iter, iter + 1);
                ++iter;
            }
            --iter;
            result += " ";
        }
        else if (*iter == '+' || *iter == '-')
        {
            stackHead = static_cast<char>(stack.getHead());
            while (stackHead == '*' || stackHead == '/')
            {
                result = result + static_cast<char>(stack.pop()) + " ";
                stackHead = static_cast<char>(stack.getHead());
            }
            stack.push(*iter);
        }
        else if (*iter == '/')
        {
            stackHead = static_cast<char>(stack.getHead());
            while (stackHead == '*')
            {
                result = result + static_cast<char>(stack.pop()) + " ";
                stackHead = static_cast<char>(stack.getHead());
            }
            stack.push(*iter);
        }
        else if (*iter == '*' || *iter == '(')
            stack.push(*iter);
        else if (*iter == ')')
        {
            stackHead = static_cast<char>(stack.getHead());
            while (stackHead != '(')
            {
                result = result + static_cast<char>(stack.pop()) + " ";
                stackHead = static_cast<char>(stack.getHead());
            }
            stack.pop();
            if (stack.getHead() != '(')
                result = result + static_cast<char>(stack.pop()) + " ";
        }
    }
    while (!stack.isEmpty())
        result = result + static_cast<char>(stack.pop()) + " ";
    result += '\0';
    return result;
}

int countPolish(string statement, Stack &stack)
{
    string::const_iterator iter;
    int numBuf = 0;
    int op;
    for (iter = statement.begin(); iter != statement.end(); ++iter)
    {
        while (*iter == ' ')
            ++iter;
        if (isdigit(*iter))
        {
            numBuf = 0;
            while (isdigit(*iter))
            {
                numBuf = numBuf * 10 + *iter - '0';
                ++iter;
            }
            stack.push(numBuf);
        }
        else if (*iter == '+')
            stack.push(stack.pop() + stack.pop());
        else if (*iter == '-')
        {
            op = stack.pop();
            stack.push(stack.pop() - op);
        }
        else if (*iter == '*')
            stack.push(stack.pop() * stack.pop());
        else if (*iter == '/')
        {
            op = stack.pop();
            stack.push(stack.pop() / op);
        }
    }
    return stack.pop();
}
