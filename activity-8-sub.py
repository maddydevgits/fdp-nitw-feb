import paho.mqtt.client as mqtt
from pymongo import MongoClient

dbclient=MongoClient('127.0.0.1',27017)
print('Connected to MongoDB Server')
db=dbclient['nitwfdp'] # provide db name
table=db['mqtt'] # provide table name

broker='broker.hivemq.com'
port=1883


client=mqtt.Client()
client.connect(broker,port)
print('Broker Connected')
client.subscribe('nitw/fdp')

def notification(client,userdata,msg):
    k=msg.payload.decode('utf-8') # bytes to string
    data={'data':k}
    print(data)
    table.insert_one(data)

client.on_message=notification
client.loop_forever() # infinite loop - backend running
