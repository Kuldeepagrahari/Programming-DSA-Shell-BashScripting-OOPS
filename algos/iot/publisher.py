import paho.mqtt.client as mqtt

# Function to handle connection
def on_connect(client, userdata, flags, rc):
    print('Connected to Broker')

# Function to handle publishing
def on_publish(client, userdata, mid):
    print('Message Published')

# Creating client
client = mqtt.Client(client_id='publisher-1')

# Connecting callback functions
client.on_connect = on_connect
client.on_publish = on_publish

# Connect to broker
client.connect("127.0.0.1", 1883)

# Publish a message with topic
ret = client.publish("house/light", "on")

# Run a loop
client.loop_forever()
