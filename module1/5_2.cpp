#include <iostream>
#define ERR_POP -1
#define ERR_INPUT -2

using std::cin;
using std::cout;
using std::endl;

class Deck
{
public:
    Deck(int val);
    ~Deck();

    void pushBack(int val);
    int popBack();
    void pushFront(int val);
    int popFront();
private:
    int *elements;
    int size;
    int head;
    int tail;

    bool isEmpty();
    void doubleBuffer();
};

Deck::Deck(int size):
    size(size),
    head(size / 2),
    tail(size / 2)
{
    elements = new int[size];
}

Deck::~Deck()
{
    delete[] elements;
}

void Deck::pushBack(int val)
{
    if ((head - tail + size) % size == 1)
        doubleBuffer();
    elements[tail++] = val;
    if (tail == size)
        tail = 0;
}

int Deck::popBack()
{
    if (!isEmpty())
    {
        int result = elements[--tail];
        if (tail == 0)
            tail = size;
        return result;
    }
    else return ERR_POP;
}

void Deck::pushFront(int val)
{
    if ((head - tail + size) % size == 1)
        doubleBuffer();
    elements[--head] = val;
    if (head == 0)
        tail = size - 1;
}

int Deck::popFront()
{
    if (!isEmpty())
    {
        int result = elements[head++];
        if (head == size)
            head = 0;
        return result;
    }
    else return ERR_POP;
}

bool Deck::isEmpty()
{
    return head == tail;
}

void Deck::doubleBuffer()
{
    int *temp = new int[2*size];
    for (int i = head; i < size; ++i)
        temp[i] = elements[i];
    for (int i = 0; i < head; ++i)
        temp[size + i] = elements[i];
    tail = head + size;
    size *= 2;
    delete[] elements;
    elements = temp;
}

int main()
{
    Deck deck(10);
    int countOfCommands;
    int command, argument;
    bool presupposition = true;

    cin >> countOfCommands;

    for (int i = 0; i < countOfCommands; ++i)
    {
        cin >> command >> argument;
        switch(command)
        {
        case 1:
            deck.pushFront(argument);
            break;
        case 2:
            if (argument != deck.popFront())
                presupposition = false;
            break;
        case 3:
            deck.pushBack(argument);
            break;
        case 4:
            if (argument != deck.popBack())
                presupposition = false;
            break;
        default:
            return ERR_INPUT;
            break;
        }
    }
    cout << (presupposition ? "YES" : "NO") << endl;
    return 0;
}
