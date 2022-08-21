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
#include "EventSystem.h"

template <>
EventSystem<double>::EventSystem() = default;
template <>
EventSystem<double>::~EventSystem() = default;
template <>
void EventSystem<double>::Subscribe(Event event, double* object)
{
    if (eventCount < EVENTS_NUMBER)
    {
        *(events + eventCount) = event;
        *(pointers + eventCount) = object;
        *(objects + eventCount) = *object;
        eventCount++;
    }
}
template <>
void EventSystem<double>::Run()
{
    for (int i = 0; i < eventCount; i++)
    {
        if (*pointers[i] != objects[i])
        {
            objects[i] = *pointers[i];
            events[i]();
        }
    }
}

template <>
EventSystem<long>::EventSystem() = default;
template <>
EventSystem<long>::~EventSystem() = default;
template <>
void EventSystem<long>::Subscribe(Event event, long* object)
{
    if (eventCount < EVENTS_NUMBER)
    {
        *(events + eventCount) = event;
        *(pointers + eventCount) = object;
        *(objects + eventCount) = *object;
        eventCount++;
    }
}
template <>
void EventSystem<long>::Run()
{
    for (int i = 0; i < eventCount; i++)
    {
        if (*pointers[i] != objects[i])
        {
            objects[i] = *pointers[i];
            events[i]();
        }
    }
}

template <>
EventSystem<int>::EventSystem() = default;
template <>
EventSystem<int>::~EventSystem() = default;
template <>
void EventSystem<int>::Subscribe(Event event, int* object)
{
    if (eventCount < EVENTS_NUMBER)
    {
        *(events + eventCount) = event;
        *(pointers + eventCount) = object;
        *(objects + eventCount) = *object;
        eventCount++;
    }
}
template <>
void EventSystem<int>::Run()
{
    for (int i = 0; i < eventCount; i++)
    {
        if (*pointers[i] != objects[i])
        {
            objects[i] = *pointers[i];
            events[i]();
        }
    }
}

template <>
EventSystem<float>::EventSystem() = default;
template <>
EventSystem<float>::~EventSystem() = default;
template <>
void EventSystem<float>::Subscribe(Event event, float* object)
{
    if (eventCount < EVENTS_NUMBER)
    {
        *(events + eventCount) = event;
        *(pointers + eventCount) = object;
        *(objects + eventCount) = *object;
        eventCount++;
    }
}
template <>
void EventSystem<float>::Run()
{
    for (int i = 0; i < eventCount; i++)
    {
        if (*pointers[i] != objects[i])
        {
            objects[i] = *pointers[i];
            events[i]();
        }
    }
}

template <>
EventSystem<char>::EventSystem() = default;
template <>
EventSystem<char>::~EventSystem() = default;
template <>
void EventSystem<char>::Subscribe(Event event, char* object)
{
    if (eventCount < EVENTS_NUMBER)
    {
        *(events + eventCount) = event;
        *(pointers + eventCount) = object;
        *(objects + eventCount) = *object;
        eventCount++;
    }
}
template <>
void EventSystem<char>::Run()
{
    for (int i = 0; i < eventCount; i++)
    {
        if (*pointers[i] != objects[i])
        {
            objects[i] = *pointers[i];
            events[i]();
        }
    }
}

BasicEventSystem::BasicEventSystem() = default;

BasicEventSystem::~BasicEventSystem()
{
    delete[] tempObjects;
}

void BasicEventSystem::Subscribe(Event* events, double** objects, int numberOfEvents)
{
    if (!bRegistered)
    {
        this->events = events;
        this->objects = objects;
        tempObjects = new double[numberOfEvents] {};
        for (int i = 0; i < numberOfEvents; i++)
        {
            tempObjects[i] = *objects[i];
        }
        this->numberOfEvents = numberOfEvents;
        bRegistered = true;
    }
}

void BasicEventSystem::Run()
{
    for (int i = 0; i < numberOfEvents; i++)
    {
        if (*objects[i] != tempObjects[i])
        {
            tempObjects[i] = *objects[i];
            events[i]();
        }
    }
}
