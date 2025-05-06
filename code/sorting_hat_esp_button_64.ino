#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "sorting_model.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Button Pins
const int buttonPins[4] = {12, 13, 14, 27}; // Update with your wiring
int responses[10];
int currentQuestion = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  showMessage("Sorting Hat Ready!");
  delay(1000);
  askQuestion();
}

void loop() {
  checkButtons();
}

void askQuestion() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Question ");
  display.print(currentQuestion + 1);
  display.setCursor(0, 10);
  display.print("Press 1-4");
  display.display();
}

void checkButtons() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      delay(200); // debounce
      responses[currentQuestion] = i + 1;
      currentQuestion++;
      if (currentQuestion >= 10) {
        classifyHouse();
      } else {
        askQuestion();
      }
      while (digitalRead(buttonPins[i]) == LOW); // wait for release
      break;
    }
  }
}

void classifyHouse() {
  float input[10];
  for (int i = 0; i < 10; i++) input[i] = responses[i];

  int predicted = predict(input);
  String house = "Unknown";
  if (predicted == 0) house = "Gryffindor";
  else if (predicted == 1) house = "Hufflepuff";
  else if (predicted == 2) house = "Ravenclaw";
  else if (predicted == 3) house = "Slytherin";

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("You're in...");
  display.setCursor(0, 20);
  display.setTextSize(2);
  display.print(house);
  display.display();
}

void showMessage(const char* msg) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(msg);
  display.display();
}
