#pragma once
#include "config.h"
#define EVENT_SIZE(x) ((int)(sizeof(x) / 2))
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
    void Subscribe(Event event, T *object);

private:
    Event events[EVENTS_NUMBER]{};
    T objects[EVENTS_NUMBER]{};
    int eventCount = 0;
    T *pointers[EVENTS_NUMBER]{};
};

class BasicEventSystem
{
public:
    BasicEventSystem();
    ~BasicEventSystem();
    void Run();
    void Subscribe(Event *event, double **object, int numberOfEvents);

private:
    bool bRegistered = false;
    Event *events;
    double **objects;
    int numberOfEvents = 0;
    double *tempObjects;
};
static BasicEventSystem eventSystem;
