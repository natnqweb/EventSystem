
# EventSystem Library

## Event based system designed for Arduino Framework. EventSystem monitors variables and fire event when the variable value change.
## Classes & TypeDefs
| TypeDefs | ActualTypes |
| ----------- | ----------- |
| `Variable` | `Double` |
| `Event` | `void function()` |

| Class |  Constructor |
| ----------- | ----------- |
| template <*class T*> `EventSystem` | `EventSystem() = default` |
| `BasicEventSystem` | `BasicEventSystem() = default` |

### Example Object Construction
- `BasicEventSystem eventSys`
- `EventSystem<Variable> eventSysVar`
- `EventSystem<Int> eventSysInt`
- `EventSystem<float> eventSysFloat`
- `EventSystem<long> eventSysLong`
- `EventSystem<char> eventSysChar`

## EventSystem Class Methods
| Return Type | Method Name | Parameters |
| ----------- | ----------- | ----------- |
| `void` | `Run` | `void` |
| `void` | `Subscribe` | `Event* events`, `T* var`|
### Methods Calling Example
It is recommended to use Subscribe Method inside setup
```
#include <EventSystem.h>
EventSystem<float> eventSysFloat;
void TemperatureChangeEvent()
{
  Serial.println("Hello From Event");
}
float temperature = 23.4f;
void setup()
{
  Serial.begin(115200);
  eventSysFloat.Subscribe(TemperatureChangeEvent, &temperature);
  temperature +=1;
}
// Always place Run in Loop
void loop()
{
  eventSysFloat.Run();
}
```


## BasicEventSystem Class Methods
| Return Type | Method Name | Parameters |
| ----------- | ----------- | ----------- |
| `void` | `Run` | `void` |
| `void` | `Subscribe` | `Event *event`, `double **variables`, `int numberOfEvents`|
### Methods Calling Example
It is recommended to use Subscribe Method inside setup
```
#include <EventSystem.h>
BasicEventSystem eventSys;
void TemperatureChangeEvent()
{
  Serial.println("Hello From Event");
}
Variable temperature = 23.4;
Event events[]{ TemperatureChangeEvent };
Variable* variables[]{ &temperature };
void setup()
{
  Serial.begin(115200);
  eventSys.Subscribe(events, variables, EVENT_SIZE(events));
  temperature +=1;
}
// Always place Run in Loop
void loop()
{
  eventSys.Run();
}

```

## Static Global Object 

`static BasicEventSystem eventSystem`

# BASIC EXAMPLE

```
// ===========================Author: Natan Lisowski========================
// ===========================Email: pythonboardsbeta@gmail.com=============
// ===========================GitHub: https://github.com/natnqweb ==========
// ===========================BASIC EXAMPLE=================================
// =========================================================================
// This is a basic example of how to use the EventSystem library.
//  - The EventSystem library is a simple library that allows you to create
//    events and trigger them.
//  - The EventSystem library is designed to be used with the Arduino framework.
// It will print out the events that are received.
// every 1000ms temperature and humidity will be updated and that change in value will trigger event.
// =========================================================================
// =================================Header Files============================
#include <EventSystem.h>
#include <Arduino.h>
// =================================Header Files============================
// =========================================================================
// ----------------------------GLOBAL VARIABLES & CONST---------------------

Variable temperature = 15.5; // Celsius
Variable humidity = 65;      //%
unsigned long lastUpdateTime = 0;
static const unsigned long updateInterval = 1000; // ms

// ----------------------------GLOBAL VARIABLES & CONST---------------------
// =========================================================================
// ---------------------------- EVENTS DECLARATION--------------------------

void TemperatureChangedEvent();
void HumidityChangedEvent();

// ---------------------------- EVENTS DECLARATION--------------------------
// =========================================================================
// -----------------------REGISTERING EVENTS AND VARIABLES------------------

Event events[]{TemperatureChangedEvent, HumidityChangedEvent};
Variable *variables[]{&temperature, &humidity};

// -----------------------REGISTERING EVENTS AND VARIABLES------------------
// =========================================================================
// =========================================================================
// ----------------------------------SETUP----------------------------------

void setup()
{
    Serial.begin(115200);
    eventSystem.Subscribe(events, variables, EVENT_SIZE(events));
}

// ----------------------------------SETUP----------------------------------
// =========================================================================
// =========================================================================
// ----------------------------------LOOP-----------------------------------

void loop()
{
    eventSystem.Run();
    if (millis() - lastUpdateTime > updateInterval)
    {
        lastUpdateTime = millis();
        temperature = temperature > 30 ? 20 : temperature + 0.5;
        humidity = humidity > 80 ? 50 : humidity + 1;
    }
}

// ----------------------------------LOOP-----------------------------------
// =========================================================================
// =========================================================================
// ---------------------------- EVENTS DEFINITION---------------------------

void TemperatureChangedEvent()
{
    Serial.print(F("Temperature updated T = "));
    Serial.print(temperature);
    Serial.println(F("C"));
}

void HumidityChangedEvent()
{
    Serial.print(F("Humidity updated H = "));
    Serial.print(humidity);
    Serial.println(F("%"));
}

// ---------------------------- EVENTS DEFINITION---------------------------
// =========================================================================
```

## Currently There Is a limit how many events you can register using EventSystem class however that is not the case in BasicEventSystem

You can always Expand this limit in config.h
there is `#define EVENTS_NUMBER 10` limit set to 10 events.

### to expand this limit you must perform following steps.

1. Go to library src folder.

    ![path](<assets/path.png>)

2. Open config.h.

    ![config.h](<assets/config.png>)

3. Change EVENTS_NUMBER value to whatever fits your preferences.

    ![Changing](<assets/modify.png>)

MIT License

Copyright (c) 2022 Natan Lisowski

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
