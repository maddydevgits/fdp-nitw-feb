import serial
import paho.mqtt.client as mqtt

ser=serial.Serial('/dev/cu.usbserial-1120',9600,timeout=0.5)
client=mqtt.Client()
client.connect('broker.hivemq.com',1883)
print('Broker Connected')

while True:
    if ser.inWaiting()>0:
        k=ser.readline()
        print(k)
        client.publish('nitw/dht11',k)
