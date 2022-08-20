#include <EventSystem.h>
#include <Arduino.h>
// ===========================BASIC EXAMPLE===============================
// =========================================================================
// This is a basic example of how to use the EventSystem library.
//  - The EventSystem library is a simple library that allows you to create
//    events and trigger them.
//  - The EventSystem library is designed to be used with the Arduino framework.
// It will print out the events that are received.
// every 1000ms temperature and humidity will be updated and that change in value will trigger event.
// =========================================================================
// ----------------------------VARIABLES----------------------------------
#pragma region VARIABLES

Variable temperature = 15.5; // Celsius
Variable humidity = 65;      //%
unsigned long lastUpdateTime = 0;
static const unsigned long updateInterval = 1000; // ms

// ----------------------------VARIABLES----------------------------------
#pragma endregion

// ---------------------------- EVENTS DECLARATION-------------------------
#pragma region EVENTS DECLARATION

void TemperatureChangedEvent();
void HumidityChangedEvent();

// ---------------------------- EVENTS DECLARATION-------------------------
#pragma endregion

// -----------------------REGISTERING EVENTS AND VARIABLES-----------------
#pragma region EVENTS DECLARATION

Event events[]{TemperatureChangedEvent, HumidityChangedEvent};
Variable *variables[]{&temperature, &humidity};

// -----------------------REGISTERING EVENTS AND VARIABLES-----------------
#pragma endregion

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
// ---------------------------- EVENTS DEFINITION-------------------------
#pragma region EVENTS DEFINITION

void TemperatureUpdateEvent()
{
    Serial.print(L("Temperature updated T = "));
    Serial.print(temperature);
    Serial.println(L("C"));
}

void HumidityUpdateEvent()
{
    Serial.print(L("Humidity updated H = "));
    Serial.print(humidity);
    Serial.println(L("%"));
}

// ---------------------------- EVENTS DEFINITION-------------------------
#pragma endregion
