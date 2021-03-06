#ifndef STACK_STACK_H
#define STACK_STACK_H

#include "Container.h"

using namespace std;

enum ExceptionStack {
    EmptyStack
};

template<class Type>
class Stack : public Container<Type> {
public:
    Type Pop() override
    {
        if (isEmpty()) {
            throw ExceptionStack::EmptyStack;
        } else {
            auto end = container.end() - 1;
            auto temp = *end;
            container.pop_back();
            return temp;
        }
    }

    Type Fetch() override
    {
        if (isEmpty()) {
            throw ExceptionStack::EmptyStack;
        } else {
            auto end = container.end() - 1;
            return *end;
        }
    }

    void ForEach(void(*Func)(Type))
    {
        /*
        for (auto i = container.rbegin; i != container.rend; ++i) {
            Func(*i);
        }
        */
        for (auto element : container) {
            Func(element);
        }
    }
    void ForEach(Type(*Func)(Type))
    {
        for (auto i = container.begin(); i < container.end(); ++i) {
            *i = Func(*i);
        }
    }
};

#endif //STACK_STACK_H
