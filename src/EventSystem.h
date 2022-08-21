// ===========================Author: Natan Lisowski========================
// ===========================Email: pythonboardsbeta@gmail.com=============
// ===========================GitHub: https://github.com/natnqweb ==========
// ===========================LICENSE: MIT License==========================
// ===========================Version: 1.0.0================================
/*  MIT License

    Copyright(c) 2022 Natan Lisowski

    Permission is hereby granted,
    free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"),
    to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and / or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all copies
    or
    substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS",
    WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER
    LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
#pragma once
#include "config.h"

#ifndef EVENTS_NUMBER
#define EVENTS_NUMBER 10
#endif

typedef void (*Event)(void);
typedef double Variable;

template <class T>
class EventSystem
{
public:
    EventSystem();
    ~EventSystem();
    void Run();
    void Subscribe(Event event, T* object);

private:
    Event events[EVENTS_NUMBER]{};
    T objects[EVENTS_NUMBER]{};
    int eventCount = 0;
    T* pointers[EVENTS_NUMBER]{};
};

class BasicEventSystem
{
public:
    BasicEventSystem();
    ~BasicEventSystem();
    void Run();
    void Subscribe(Event* event, double** object, int numberOfEvents);

private:
    bool bRegistered = false;
    Event* events;
    double** objects;
    int numberOfEvents = 0;
    double* tempObjects;
};
static BasicEventSystem eventSystem;
