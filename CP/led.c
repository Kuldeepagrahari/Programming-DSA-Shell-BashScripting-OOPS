#include <stdint.h>

// Define register addresses and bit positions
#define SYSCTL_RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIO_PORTF_DIR (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_DEN (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_DATA (*((volatile uint32_t *)0x40025000))

#define SW1_BIT 4 // Bit position of SW1 (PF4) on PORTF
#define RED_LED_BIT 1 // Bit position of Red LED (PF1) on PORTF
#define GREEN_LED_BIT 3 // Bit position of Green LED (PF3) on PORTF
#define BLUE_LED_BIT 2 // Bit position of Blue LED (PF2) on PORTF

// Function prototypes
void delay(uint32_t);

int main() {
    // Enable clock for PORTF
    SYSCTL_RCGCGPIO |= (1 << 5); // Setting bit 5 for PORTF

    // Set the direction of PF1 (Red LED), PF2 (Blue LED), PF3 (Green LED) as output
    GPIO_PORTF_DIR |= ((1 << RED_LED_BIT) | (1 << GREEN_LED_BIT) | (1 << BLUE_LED_BIT));

    // Enable digital functionality on PF1, PF2, PF3
    GPIO_PORTF_DEN |= ((1 << RED_LED_BIT) | (1 << GREEN_LED_BIT) | (1 << BLUE_LED_BIT));

    // Enable pull-up resistor on PF4 (SW1)
    GPIO_PORTF_DEN |= (1 << SW1_BIT);
    GPIO_PORTF_DATA |= (1 << SW1_BIT); // Setting bit to 1 enables pull-up resistor

    while (1) {
        // Check the status of SW1
        if (GPIO_PORTF_DATA & (1 << SW1_BIT)) { // SW1 is open
            // Green LED blinks and Red LED stays on
            GPIO_PORTF_DATA |= (1 << GREEN_LED_BIT); // Green LED on
            GPIO_PORTF_DATA |= (1 << RED_LED_BIT); // Red LED on
            delay(1000000); // Delay
            GPIO_PORTF_DATA ^= (1 << GREEN_LED_BIT); // Toggle Green LED
            delay(1000000); // Delay
        } else { // SW1 is closed
            // Red LED blinks and Green LED stays on
            GPIO_PORTF_DATA |= (1 << RED_LED_BIT); // Red LED on
            GPIO_PORTF_DATA |= (1 << GREEN_LED_BIT); // Green LED on
            delay(1000000); // Delay
            GPIO_PORTF_DATA ^= (1 << RED_LED_BIT); // Toggle Red LED
            delay(1000000); // Delay
        }
    }
}

void delay(uint32_t iterations) {
    while(iterations > 0) {
        iterations--;
    }
}
