#include <Wire.h>
#include <PulseSensorPlayground.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Pin Definitions
#define HW827_PIN 36
#define GSR_PIN 34
#define BUZZ_PIN 26
#define THRESHOLD 550

// Object Creation
PulseSensorPlayground pulseSensor;
Adafruit_MLX90614 mlx;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup()
{
    Serial.begin(115200);
    Wire.begin(21, 22);

    pinMode(BUZZ_PIN, OUTPUT);

    // Pulse Sensor Initialization
    pulseSensor.analogInput(HW827_PIN);
    pulseSensor.setThreshold(THRESHOLD);
    pulseSensor.begin();

    // Temperature Sensor Initialization
    mlx.begin();

    // OLED Initialization
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
}

void loop()
{
    // Read Heart Rate
    int heartRate = pulseSensor.getBeatsPerMinute();
    bool beatDetected = pulseSensor.sawStartOfBeat();

    // Read Temperature
    float temp = mlx.readObjectTempC();

    // Read GSR Sensor
    int gsr = analogRead(GSR_PIN);
    int stress = map(gsr, 0, 4095, 0, 100);

    // Display Data on OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("STRESS MONITOR");

    display.drawLine(0, 9, 127, 9, WHITE);

    display.setCursor(0, 13);
    display.print("HR: ");
    display.print(beatDetected ? heartRate : 0);
    display.println(" BPM");

    display.print("Temp: ");
    display.print(temp);
    display.println(" C");

    display.print("Stress: ");
    display.print(stress);
    display.println("%");

    if (stress > 70)
    {
        display.println("!! HIGH STRESS !!");
    }

    display.display();

    // Buzzer Alert
    if (stress > 70 || heartRate > 100)
    {
        digitalWrite(BUZZ_PIN, HIGH);
        delay(300);
        digitalWrite(BUZZ_PIN, LOW);
    }

    delay(20);
}