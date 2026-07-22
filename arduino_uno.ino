from machine import Pin, ADC, I2C
from time import sleep_ms
import ssd1306
import mlx90614

HW827_PIN = 36
GSR_PIN = 34
BUZZ_PIN = 26

buzzer = Pin(BUZZ_PIN, Pin.OUT)

heart_sensor = ADC(Pin(HW827_PIN))
heart_sensor.atten(ADC.ATTN_11DB)

gsr_sensor = ADC(Pin(GSR_PIN))
gsr_sensor.atten(ADC.ATTN_11DB)

i2c = I2C(0, scl=Pin(22), sda=Pin(21))

oled = ssd1306.SSD1306_I2C(128, 64, i2c)
mlx = mlx90614.MLX90614(i2c)

def get_bpm():
    value = heart_sensor.read()

    if value > 2000:
        bpm = 80
    else:
        bpm = 0

    return bpm

while True:

    bpm = get_bpm()

    temperature = mlx.read_object_temp()

    gsr = gsr_sensor.read()

    stress = int((gsr / 4095) * 100)

    oled.fill(0)

    oled.text("STRESS MONITOR", 0, 0)

    oled.text("HR: {} BPM".format(bpm), 0, 18)

    oled.text("Temp:{:.1f}C".format(temperature), 0, 32)

    oled.text("Stress:{}%".format(stress), 0, 46)

    if stress > 70:
        oled.text("HIGH STRESS!", 0, 56)

    oled.show()

    if stress > 70 or bpm > 100:
        buzzer.on()
        sleep_ms(300)
        buzzer.off()

    sleep_ms(20)
