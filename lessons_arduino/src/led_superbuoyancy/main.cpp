//
// Created by Alduin on 26.04.2025.
//

//#include <Arduino.h>
//
//// Pin definitions for RGB LEDs
//#define RED_PIN 16
//#define GREEN_PIN 17
//#define BLUE_PIN 5
//
//// Constants for PWM frequency and resolution
//const int frequency = 5000;    // PWM frequency in Hz (5kHz)
//const int resolution = 8;      // PWM resolution (8-bit means values from 0 to 255)
//
//// PWM channels for each color
//const int RED_CHANNEL = 0;
//const int GREEN_CHANNEL = 1;
//const int BLUE_CHANNEL = 2;
//
//// Settings for breathing effect and color change speed
//const float breathingPeriod = 4.0;  // Breathing period in seconds (full cycle of fading in and out)
//const float colorCycleSpeed = 30.0; // Speed of color change in degrees per second
//
//// Internal variables
//unsigned long previousMillis = 0; // Stores the previous time for timing calculations
//
///**
// * @brief Initializes the RGB LEDs with the given PWM frequency and resolution
// */
//void setup() {
//    // Set up PWM for Red channel
//    ledcSetup(RED_CHANNEL, frequency, resolution);
//    ledcAttachPin(RED_PIN, RED_CHANNEL);
//
//    // Set up PWM for Green channel
//    ledcSetup(GREEN_CHANNEL, frequency, resolution);
//    ledcAttachPin(GREEN_PIN, GREEN_CHANNEL);
//
//    // Set up PWM for Blue channel
//    ledcSetup(BLUE_CHANNEL, frequency, resolution);
//    ledcAttachPin(BLUE_PIN, BLUE_CHANNEL);
//}
//
///**
// * @brief Sets the RGB color by writing values to each PWM channel
// * @param r The red color intensity (0-255)
// * @param g The green color intensity (0-255)
// * @param b The blue color intensity (0-255)
// */
//void setColor(int r, int g, int b) {
//    ledcWrite(RED_CHANNEL, r);
//    ledcWrite(GREEN_CHANNEL, g);
//    ledcWrite(BLUE_CHANNEL, b);
//}
//
///**
// * @brief Converts a hue value (0-360 degrees) to RGB color.
// * The hue value is used in the HCV color model where 'C' (chroma) is set to 1 for simplicity.
// * The function calculates the RGB components based on the hue and adjusts brightness later.
// *
// * @param hue The hue value (0-360 degrees)
// * @param r Output red component (0-255)
// * @param g Output green component (0-255)
// * @param b Output blue component (0-255)
// */
//void HCVtoRGB(float hue, int &r, int &g, int &b) {
//    // C = 1 (chroma)
//    float c = 1.0;
//    // x is the difference between chroma and the RGB components
//    float x = (1.0 - fabs(fmod(hue / 60.0, 2) - 1.0));
//    // m is the offset for brightness adjustment
//    float m = 0;
//
//    // Temporary RGB values
//    float r_, g_, b_;
//
//    // Hue ranges for determining RGB values
//    if (hue < 60) {
//        r_ = c; g_ = x; b_ = 0;
//    } else if (hue < 120) {
//        r_ = x; g_ = c; b_ = 0;
//    } else if (hue < 180) {
//        r_ = 0; g_ = c; b_ = x;
//    } else if (hue < 240) {
//        r_ = 0; g_ = x; b_ = c;
//    } else if (hue < 300) {
//        r_ = x; g_ = 0; b_ = c;
//    } else {
//        r_ = c; g_ = 0; b_ = x;
//    }
//
//    // Apply brightness offset (m) and scale the values to 255
//    r = (r_ + m) * 255;
//    g = (g_ + m) * 255;
//    b = (b_ + m) * 255;
//}
//
///**
// * @brief The main loop for controlling the RGB LEDs
// * - Changes the color smoothly by modifying the hue over time
// * - Implements a breathing effect by varying the brightness using a sine wave
// */
//void loop() {
//    unsigned long currentMillis = millis();         // Get the current time in milliseconds
//    float elapsedTime = currentMillis / 1000.0;     // Convert to seconds for easier calculation
//
//    // Smooth color change (cycling through the color wheel)
//    float hue = fmod(elapsedTime * colorCycleSpeed, 360);  // The hue value is incremented based on elapsed time
//
//    int r, g, b;
//    HCVtoRGB(hue, r, g, b);  // Convert hue to RGB values
//
//    // Breathing effect: a sine wave function that oscillates between 0 and 1
//    float breathing = (sin(elapsedTime * 2.0 * PI / breathingPeriod) + 1.0) / 2.0;
//
//    // Apply the breathing effect to the RGB values
//    int rBreath = r * breathing;
//    int gBreath = g * breathing;
//    int bBreath = b * breathing;
//
//    // Set the color on the RGB LED
//    setColor(rBreath, gBreath, bBreath);
//
//    // No delay() function is used here to ensure continuous smooth animation
//}
