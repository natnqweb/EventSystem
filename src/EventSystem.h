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
typedef struct _BasicEvent
{
    Event event;
    double* object;
} BasicEvent;
// MACRO FOR DECLARING EVENTS
#define DECLARATION_MAP_BEGIN enum EVENT_SYSTEM_DECLARATIONS{
#define DECLARATION_MAP_END EVENT_SYSTEM_SIZE};
#define DECLARE_EVENT_FUNCTION(NAME) void NAME()
#define DECLARE_EVENT(NAME,VARIABLE,VALUE) void NAME(); Variable VARIABLE{VALUE}
#define DEFINE_EVENT_FUNCTION(NAME) void NAME()
#define EVENT_LIST_START BasicEvent events[]{
#define EVENT_LIST_END };
#define EVENT_SYSTEM_AUTO() eventSystem.Subscribe(events, sizeof(events)/sizeof(events[0]))
#define EVENT_SYSTEM_RUN() eventSystem.Run()
#define EVENT_SYSTEM_SUBSCRIBE(X) eventSystem.Subscribe(events, variables, X)

template <class T>
class EventSystem
{
public:
    EventSystem();
    ~EventSystem();
    void Run();
    void Subscribe(Event event, T* object);
    void Stop();
    void Start();

private:
    Event events[EVENTS_NUMBER]{};
    T objects[EVENTS_NUMBER]{};
    int eventCount = 0;
    bool m_bStop{ false };
    T* pointers[EVENTS_NUMBER]{};
};

class BasicEventSystem
{
public:
    BasicEventSystem();
    ~BasicEventSystem();
    void Run();
    void Stop();
    void Start();
    void Subscribe(BasicEvent* basicEventArr, int numberOfEvents);

private:
    bool m_bStop = false;
    bool bRegistered = false;
    BasicEvent* events;
    int numberOfEvents = 0;
    double* tempObjects;
};
static BasicEventSystem eventSystem;

template<class T>
EventSystem<T>::EventSystem() = default;
template<class T>
EventSystem<T>::~EventSystem() = default;
template<class T>
void EventSystem<T>::Subscribe(Event event, T* object)
{
    if (eventCount < EVENTS_NUMBER)
    {
        *(events + eventCount) = event;
        *(pointers + eventCount) = object;
        *(objects + eventCount) = *object;
        eventCount++;
    }
}
template<class T>
void EventSystem<T>::Run()
{
    for (int i = 0;((i < eventCount) && (!m_bStop)); i++)
    {
        if (*pointers[i] != objects[i])
        {
            objects[i] = *pointers[i];
            events[i]();
        }
    }
}
template <class T>
void EventSystem<T>::Stop()
{
    m_bStop = true;
}

template <class T>
void EventSystem<T>::Start()
{
    m_bStop = false;
}

BasicEventSystem::BasicEventSystem() = default;

BasicEventSystem::~BasicEventSystem()
{
    delete[] tempObjects;
}

void BasicEventSystem::Subscribe(BasicEvent* basicEventArr, int numberOfEvents)
{
    if (!bRegistered)
    {
        events = basicEventArr;
        tempObjects = new double[numberOfEvents] {};
        for (int i = 0; i < numberOfEvents; i++)
        {
            tempObjects[i] = *(basicEventArr[i].object);
        }
        this->numberOfEvents = numberOfEvents;
        bRegistered = true;
    }
}

void BasicEventSystem::Run()
{
    for (int i = 0; ((i < numberOfEvents) && (!m_bStop)); i++)
    {
        if (*(events[i]->object) != tempObjects[i])
        {
            tempObjects[i] = *(events[i]->object);
            events[i].event();
        }
    }
}

void BasicEventSystem::Stop()
{
    m_bStop = true;
}

void BasicEventSystem::Start()
{
    m_bStop = false;
}

