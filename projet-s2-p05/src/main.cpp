#include <Arduino.h>
#include <ArduinoJson.h>

#define BAUD 256000

#define pin_joystick_x A0
#define pin_joystick_y A1

#define pin_fire_led 53
#define pin_water_led 52

#define button1_pin 50
#define button2_pin 48
#define button3_pin 46
#define button4_pin 44

// #define debug_led_pin 45


typedef struct
{
	int accelX;
	int accelY;
	int accelZ;

	int joyX;
	int joyY;

	uint8_t buttons;
	uint32_t dt;
} sensor_data_t;

typedef struct
{
	int seg_1;
	int seg_2;
	
	uint8_t playerChoice;
	char lcd_data[64];
} display_data_t;

sensor_data_t sensor_data;
display_data_t display_data;

uint64_t time = 0;
uint64_t prevTime;

void SendUpdate(sensor_data_t* data)
{
	JsonDocument doc;

	doc["accelerometre"]["x"] = data->accelX;
	doc["accelerometre"]["y"] = data->accelY;
	doc["accelerometre"]["z"] = data->accelZ;

	doc["boutons"]["1"] = (data->buttons & 1) >> 0;
	doc["boutons"]["2"] = (data->buttons & 2) >> 1;
	doc["boutons"]["3"] = (data->buttons & 4) >> 2;
	doc["boutons"]["4"] = (data->buttons & 8) >> 3;

	doc["joystick"]["x"] = data->joyX;
	doc["joystick"]["y"] = data->joyY;
	doc["dt"] = data->dt;

	serializeJson(doc, Serial);
	doc.shrinkToFit();
	Serial.println();
}

void ReadUpdate(display_data_t* data)
{

	JsonDocument doc;
	
	DeserializationError err = deserializeJson(doc, Serial);
	
	if (err)
	{
		Serial.print("deserialize() failed: ");
    	Serial.println(err.c_str());
    	return;
	}

	data->playerChoice = doc["joueur"];
	data->seg_1 = doc["seg1"];
	data->seg_2 = doc["seg2"];
	strncpy(data->lcd_data, doc["lcd"], 64);
}

void setup() 
{
  	Serial.begin(BAUD);

	pinMode(pin_joystick_x, INPUT);
	pinMode(pin_joystick_y, INPUT);
	
	pinMode(button1_pin, INPUT);
	pinMode(button2_pin, INPUT);
	pinMode(button3_pin, INPUT);
	pinMode(button4_pin, INPUT);

	pinMode(pin_fire_led, OUTPUT);
	pinMode(pin_water_led, OUTPUT);

	// pinMode(debug_led_pin, OUTPUT);

	sensor_data.accelX = 0;
	sensor_data.accelY = 0;
	sensor_data.accelZ = 0;

	sensor_data.buttons = 0;
	sensor_data.joyX = 0;
	sensor_data.joyY = 0;

	display_data.seg_1 = 0;
	display_data.seg_2 = 0;
	display_data.playerChoice = 0;
	strncpy(display_data.lcd_data, "", 64);
}

void loop() 
{
	prevTime = time;
	time = millis();
	sensor_data.accelX = 0;
	sensor_data.accelY = 0;
	sensor_data.accelZ = 0;

	sensor_data.buttons = (digitalRead(button1_pin) | (digitalRead(button2_pin) << 1) | (digitalRead(button3_pin) << 2) | (digitalRead(button4_pin) << 3));
	
	sensor_data.joyX = analogRead(pin_joystick_x);
	sensor_data.joyY = analogRead(pin_joystick_y);

	sensor_data.dt = time - prevTime;

	SendUpdate(&sensor_data);
	delay(5);
	ReadUpdate(&display_data);

	digitalWrite(pin_fire_led, (display_data.playerChoice & 1) >> 0);
	digitalWrite(pin_water_led, (display_data.playerChoice & 2) >> 1);
	
	delay(5);
}