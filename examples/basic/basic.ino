#include <EventSystem.h>
#include <Arduino.h>
Variable v1 = 1;
Variable v2 = 2;
void event2()
{
    Serial.println("call2");
}
void event3()
{
    Serial.println("call3");
}

long v3 = 1;

void event1()
{
    Serial.println("call");
}
void event4()
{
    Serial.println("call4");
}
void event5()
{
    Serial.println("call5");
}
long v4 = 5;
Event events[]{event1, event2, event3, event4, event5};
Variable *variables[]{&v1, &v2, &v2, (Variable *)&v3, (Variable *)&v4};

void setup()
{
    Serial.begin(115200);
    eventSystem.Subscribe(events, variables, EVENT_SIZE(variables));
}

void loop()
{
    eventSystem.Run();
    // sys2.Run();
    v1 += 1;
    v2 += 1;
    v4 += 1;
    v3 += 1;
    delay(1000);
}
