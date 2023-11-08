#include <Microbit_I2C.h>

class DFRobot_SpeechSynthesis {
public:
    DFRobot_SpeechSynthesis(i2c_t i2c);

    void begin();

    void playWav(uint8_t* wavData, uint16_t len);

private:
    i2c_t i2c_;
};

DFRobot_SpeechSynthesis::DFRobot_SpeechSynthesis(i2c_t i2c) {
    i2c_ = i2c;
}

void DFRobot_SpeechSynthesis::begin() {
    microbit::pin::set_mode(MICROBIT_PIN_0, microbit::pin_mode::OUTPUT);
    i2c_init(i2c_);
}

void DFRobot_SpeechSynthesis::playWav(uint8_t* wavData, uint16_t len) {
    i2c_write(i2c_, wavData, len);
}

DFRobot_SpeechSynthesis speechSynthesis(MICROBIT_I2C_SCL, MICROBIT_I2C_SDA);

void setup() {
    speechSynthesis.begin();
}

void loop() {
    speechSynthesis.playWav(wavData, len);
}
