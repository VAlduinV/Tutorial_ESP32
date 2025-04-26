#include <Arduino.h>

#define RED_PIN 16
#define GREEN_PIN 17
#define BLUE_PIN 5

const int frequency = 5000;
const int resolution = 8;

const int RED_CHANNEL = 0;
const int GREEN_CHANNEL = 1;
const int BLUE_CHANNEL = 2;

void setup() {
    ledcSetup(RED_CHANNEL, frequency, resolution);
    ledcAttachPin(RED_PIN, RED_CHANNEL);

    ledcSetup(GREEN_CHANNEL, frequency, resolution);
    ledcAttachPin(GREEN_PIN, GREEN_CHANNEL);

    ledcSetup(BLUE_CHANNEL, frequency, resolution);
    ledcAttachPin(BLUE_PIN, BLUE_CHANNEL);
}

// Функція конвертації Hue в RGB
void HCVtoRGB(float hue, int &r, int &g, int &b) {
    float s = 1.0; // Насыщенность 100%
    float v = 1.0; // Яркость 100%

    int i = int(hue / 60.0) % 6;
    float f = (hue / 60.0) - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    float rF, gF, bF;
    switch (i) {
        case 0: rF = v; gF = t; bF = p; break;
        case 1: rF = q; gF = v; bF = p; break;
        case 2: rF = p; gF = v; bF = t; break;
        case 3: rF = p; gF = q; bF = v; break;
        case 4: rF = t; gF = p; bF = v; break;
        case 5: rF = v; gF = p; bF = q; break;
    }

    r = int(rF * 255);
    g = int(gF * 255);
    b = int(bF * 255);
}

void setColor(int red, int green, int blue) {
    ledcWrite(RED_CHANNEL, red);
    ledcWrite(GREEN_CHANNEL, green);
    ledcWrite(BLUE_CHANNEL, blue);
}

void loop() {
    for (float hue = 0; hue < 360; hue += 1) { // Плавний перехід по всім кольорам
        int r, g, b;
        HCVtoRGB(hue, r, g, b);
        setColor(r, g, b);
        delay(20); // Можеш гратись з часом для більшого або меншого розгону
    }
}
