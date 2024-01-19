int randNumber;

const int col[8] = {
  16, 4, 5, 11, 7, 12, 18, 19
};

const int row[8] = {
  10, 17, 9, 13, 2, 8, 3, 6
};

const bool matrixPin[8][8] = {
  {1,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,0,0,0,0,0,1}
};

const bool matrixPin2[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,0,1,1,0,1,0},
  {0,1,0,1,1,0,1,0},
  {1,0,0,1,1,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,1,1,0,0,1},
  {1,1,1,1,1,1,1,1}
};

const bool matrixPin3[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

void turnOff() {
  for (int pin = 0; pin < 8; pin++) {
    pinMode(col[pin], OUTPUT);
    pinMode(row[pin], OUTPUT);
    digitalWrite(col[pin], HIGH);
    digitalWrite(row[pin], LOW);
  }
}


void generateMatrix(int input, bool matrix[8][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      matrix[i][j] = false;
    }
  }

  int onesCount = input % 65;

  for (int i = 0; i < onesCount; i++) {
    matrix[i / 8][i % 8] = true;
  }
}


void display(bool matrix[8][8], unsigned long delayTime) {
  unsigned long end = millis() + delayTime;
  while (end >= millis()) {
    for (int rowPin = 0; rowPin < 8; rowPin++) {
      turnOff();
      for (int colPin = 0; colPin <8; colPin++) {
        if(matrix[rowPin][colPin]) {
          digitalWrite(row[rowPin], HIGH);
          digitalWrite(col[colPin], LOW);
        }
      }
      delay(2);
    }
  }
  turnOff();
}

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  for (int pin = 0; pin < 8; pin++) {
    pinMode(col[pin], OUTPUT);
    pinMode(row[pin], OUTPUT);
    digitalWrite(col[pin], LOW);
  }
  
  for (int pin = 0; pin < 8; pin++) {
    digitalWrite(row[pin], HIGH);
    delay(150);
  }
  delay(700);
  turnOff();
}

void loop() {
  randNumber = random(65);
  bool matrix[8][8];
  generateMatrix(randNumber, matrix);
  display(matrix, 5000);
}
