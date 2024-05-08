import paho.mqtt.client as mqtt  # Corrected import statement

# Function to process received message
def process_message(client, userdata, message):
    print("Message received:", str(message.payload.decode("utf-8")))
    print("Message topic:", message.topic)
    print("Message qos:", message.qos)  # Corrected attribute name
    print("Message retain flag:", message.retain)

# Create client
client = mqtt.Client(client_id="subscriber-1")

# Assign callback function
client.on_message = process_message  # Corrected assignment

# Connect to broker
broker_address = "your_broker_address"  # Replace with your broker address
client.connect(broker_address, 1883, 60)

# Subscribe to topic
client.subscribe("house/light")

# Run loop
client.loop_forever()
