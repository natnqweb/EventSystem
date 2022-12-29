
# EventSystem Library

## Fully Tested On

### ESPRESSIF

- [x] - ESP8266 - NodeMcu 0.9
- [x] - ESP8266 - NodeMcu 1.0
- [X] - ESP8266 - Wemos D1 R1
- [X] - ESP32
- [ ] - Others

### Arduino

- [x] - Arduino Uno R3
- [x] - Arduino Mega
- [X] - Arduino Nano
- [ ] - Others

### RaspberryPi

- [X] - Pico

### STM

- [ ] - Not Yet

## Event based system designed for Arduino Framework. EventSystem monitors variables and fire event when the variable value change

## Classes & TypeDefs

| TypeDefs   | ActualTypes       |
| ---------- | ----------------- |
| `Variable` | `Double`          |
| `Event`    | `void function()` |

| Class                              | Constructor                    |
| ---------------------------------- | ------------------------------ |
| template <*class T*> `EventSystem` | `EventSystem() = default`      |
| `BasicEventSystem`                 | `BasicEventSystem() = default` |

### Example Object Construction

- `BasicEventSystem eventSys`
- `EventSystem<Variable> eventSysVar`
- `EventSystem<Int> eventSysInt`
- `EventSystem<float> eventSysFloat`
- `EventSystem<long> eventSysLong`
- `EventSystem<char> eventSysChar`

## EventSystem Class Methods

| Return Type | Method Name | Parameters                |
| ----------- | ----------- | ------------------------- |
| `void`      | `Run`       | `void`                    |
| `void`      | `Subscribe` | `Event* events`, `T* var` |
| `void`      | `Stop`      | `void`                    |
| `void`      | `Start`     | `void`                    |

## Currently There Is a limit how many events you can register using EventSystem class however that is not the case in BasicEventSystem

You can always Expand this limit in config.h
there is `#define EVENTS_NUMBER 10` limit set to 10 events.

### to expand this limit you must perform following steps

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
