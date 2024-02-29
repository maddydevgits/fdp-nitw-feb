import paho.mqtt.client as mqtt
import pandas as pd

batch=0
dataset=[]
broker='broker.hivemq.com'
port=1883

client=mqtt.Client()
client.connect(broker,port)
print('Broker Connected')
client.subscribe('nitw/dht11')

def notification(client,userdata,msg):
    global batch
    data=msg.payload.decode('utf-8')[:-1]
    data=data.split(':')
    h=data[1]
    h=h.split(',')[0]
    h=h[1:]
    t=data[2]
    t=t[1:]
    h=float(h)
    t=float(t)
    dummy=[h,t]
    dataset.append(dummy)
    print(dataset)
    batch+=1
    if batch==10:
      df=pd.DataFrame(dataset)
      df.to_csv('iotdata.csv')
      batch=0


    
    # print(msg.topic,msg.payload)

client.on_message=notification
client.loop_forever() # infinite loop - backend running
