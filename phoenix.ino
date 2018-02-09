#include "driving.h"

Motor motor_left(1, 2, 3);
Motor motor_right(4, 5, 6);
Driving *driving = new Driving(motor_left, motor_right);
String lastCmd = "";

void setup() {
  Serial.begin(9600);
  
  Serial.println("Ready.");
}
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

void loop() {
    recvWithStartEndMarkers();
    showNewData();
}

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

void work(String cmd) {
  if (cmd.equals("FWD")) {
    lastCmd = "FWD";
    driving->goForward();
  } else if(cmd.equals("RGT")) {
    lastCmd = "RGT";
    driving->goRight();
  } else if(cmd.equals("LFT")) {
    lastCmd = "LFT";
    driving->goLeft();
  } else if (cmd.equals("STP")) {
    lastCmd = "STP";
    driving->stop();
  } else if (cmd.equals("STPCRANGE")) {
    driving->critical_range = true;
  } else if (cmd.equals("STPNCRANGE")) {
    work(lastCmd);
    driving->critical_range = false;
  }
}

void showNewData() {
  if (newData == true) {
    Serial.println(receivedChars);
    newData = false;
  }
  work(receivedChars);  
}


