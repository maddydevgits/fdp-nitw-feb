import paho.mqtt.client as mqtt

# pub, sub - clients
# broker - server - cloud - pub,sub - anywhere
# broker - server - a laptop or local server - pub, sub - in the network

broker='broker.hivemq.com' # cloud server
port=1883

try:
    client=mqtt.Client() # Client is a class
    client.connect(broker,port)
    print('Broker Connected')
    client.publish('nitw/fdp','Temp: 24.0') 
    print('Msg Sent')
except:
    print('Broker Connection Failure')
