#include <Arduino.h>
#include <Servo.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// WiFi constants
const char *WIFI_SSID = "...";
const char *WIFI_PASSWORD = "...";
const int WIFI_RETRY_DELAY = 1000;

// Switch constants
const int SWITCH_PIN = D1;

// Servo constants
const int SERVO_PAW_PIN = D5;
const int SERVO_GATE_PIN = D6;
const int SERVO_MOVE_DELAY = 1000;

// Audio constants
const char *AUDIO_URL = "...";
const int AUDIO_BUFFER_SIZE = 2048;

// Servo globals
Servo servo_paw;
Servo servo_gate;

/**
 * Setup method called when a RESET signal is sent to the ESP.
 * Initialize components mode and default state and establish WiFi connection.
 */
void setup() {
  setup_led();
  setup_switch();
  setup_servo();
  
  reset();

  wifi_connect();
}

/**
 * Setup LED mode.
 */
void setup_led() {
  pinMode(LED_BUILTIN, OUTPUT);
}

/**
 * Setup switch mode.
 */
void setup_switch() {
  pinMode(SWITCH_PIN, INPUT);
  pinMode(SWITCH_PIN, OUTPUT);
}

/**
 * Attach each servo to its respective pin.
 */
void setup_servo() {
  servo_paw.attach(SERVO_PAW_PIN);
  servo_gate.attach(SERVO_GATE_PIN);
}

/**
 * Reset components to their default state.
 */
void reset() {
  reset_led();
  reset_switch();
  reset_servo();
}

/**
 * Reset LED state.
 */
void reset_led() {
  digitalWrite(LED_BUILTIN, HIGH);
}

/**
 * Reset switch state.
 */
void reset_switch() {
  digitalWrite(SWITCH_PIN, HIGH);
}

/**
 * Reset each servo state to their nominal position.
 */
void reset_servo() {
  servo_move(servo_paw, 0);
  servo_move(servo_gate, 0);
}

/**
 * Initialize the WiFi connection using the provided SSID and password.
 * This method call may hang forever waiting for the WiFi connection to be established.
 */
void wifi_connect() {
  WiFi.disconnect();
  WiFi.softAPdisconnect(true);
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while(WiFi.status() != WL_CONNECTED) {
    delay(WIFI_RETRY_DELAY);
  }

  enable_led();
  delay(1000);
  disable_led();
}

/**
 * Make an HTTP request to the daemon to play a random sound.
 */
void audio_send_play_request() {
  HTTPClient http;
  
  http.begin(AUDIO_URL);
  http.GET();
  http.end();
}

/**
 * Enable the builtin LED.
 */
void enable_led() {
  digitalWrite(LED_BUILTIN, LOW);
}

/**
 * Disable the builtin LED.
 */
void disable_led() {
  digitalWrite(LED_BUILTIN, HIGH);
}

/**
 * Move the servo to the specified position in degrees.
 */
void servo_move(Servo servo, int new_position) {  
  servo.write(new_position);
  delay(SERVO_MOVE_DELAY);
}

/**
 * Open the KaamBox gate.
 */
void open_gate() {
  servo_move(servo_gate, 65);
}

/**
 * Close the KaamBox gate.
 */
void close_gate() {
  servo_move(servo_gate, 0);
}

/**
 * Toggle down the KaamBox switch.
 */
void toggle_down_switch() {
  servo_move(servo_paw, 160);
  servo_move(servo_paw, 0);
}

/**
 * Perform all servo actions in order.
 */
void perform_actions() {
  open_gate();
  audio_send_play_request();
  toggle_down_switch();
  close_gate();
}

/**
 * Returns `true` if the switch is toggled; returns `false` otherwise.
 */
boolean is_switch_enabled() {
  int switch_state = digitalRead(SWITCH_PIN);
  return switch_state == LOW;
}

/**
 * Perform the required actions base on the KaamBox switch state.
 */
void compute_switch_state() {
  if(is_switch_enabled()) {
    enable_led();
    reset_servo();
    perform_actions();
  }
  else {
    disable_led();
  }
}

/**
 * ESP event loop.
 */
void loop() {
  compute_switch_state();
  delay(500);
}

