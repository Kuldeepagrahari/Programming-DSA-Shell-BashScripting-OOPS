/* The `#include <stdint.h>` directive is including the standard header file `stdint.h` in the C
program. This header file provides definitions for integer types with specified widths, which are
particularly useful for writing portable code that needs specific data sizes regardless of the
platform or compiler being used. It defines integer types like `uint8_t`, `uint16_t`, `uint32_t`,
`int8_t`, `int16_t`, `int32_t`, etc., with guaranteed sizes, making the code more readable and
maintainable. */
#include <stdint.h>

// Register addresses
#define CLOCK_GATING_REG_BASE       ((volatile uint32_t *)0x400FE000)
#define CLOCK_GATING_REG_OFFSET     0x608
#define PORTF_DIR_REG               ((volatile uint32_t *)0x40025400)
#define PORTF_DEN_REG               ((volatile uint32_t *)0x4002551C)
#define GPIO_LOCK_REG_BASE          ((volatile uint32_t *)0x40025000)
#define GPIO_LOCK_REG_OFFSET        0x520
#define GPIO_CR_REG_BASE            ((volatile uint32_t *)0x40025000)
#define GPIO_CR_REG_OFFSET          0x524
#define GPIO_PULLUP_REG             ((volatile uint32_t *)0x40025510)
#define GPIO_DATAF_REG              ((volatile uint32_t *)0x40025000)

// Bit manipulation macros
#define SET_BIT(reg, bit)          ((*(reg)) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)        ((*(reg)) &= ~(1 << (bit)))
#define READ_BIT(reg, bit)         (((*(reg)) >> (bit)) & 0x01)

// LED definitions
#define LED_RED     0x02    // Bit 1
#define LED_BLUE    0x04    // Bit 2
#define LED_GREEN   0x08    // Bit 3

// Switch definitions
#define SW1_BIT     4       // Bit 4
#define SW2_BIT     0       // Bit 0

// Function to initialize GPIO
void GPIO_Init() {
    // Enable clock for PORT F
    SET_BIT(CLOCK_GATING_REG_BASE + (CLOCK_GATING_REG_OFFSET / 4), 5);
    
    // Set direction of PORT F pins as output for LED
    SET_BIT(PORTF_DIR_REG, LED_RED);
    SET_BIT(PORTF_DIR_REG, LED_BLUE);
    SET_BIT(PORTF_DIR_REG, LED_GREEN);
    
    // Enable digital functionality for PORT F pins
    SET_BIT(PORTF_DEN_REG, LED_RED);
    SET_BIT(PORTF_DEN_REG, LED_BLUE);
    SET_BIT(PORTF_DEN_REG, LED_GREEN);
    
    // Unlock switches
    *GPIO_LOCK_REG_BASE = 0x4C4F434B;
    SET_BIT(GPIO_CR_REG_BASE, SW1_BIT);
    SET_BIT(GPIO_CR_REG_BASE, SW2_BIT);
    
    // Enable pull-up resistors for switches
    SET_BIT(GPIO_PULLUP_REG, SW1_BIT);
    SET_BIT(GPIO_PULLUP_REG, SW2_BIT);
}

// Function to read switch states
uint8_t Read_Switches() {
    uint8_t sw1_state = READ_BIT(GPIO_DATAF_REG, SW1_BIT);
    uint8_t sw2_state = READ_BIT(GPIO_DATAF_REG, SW2_BIT);
    
    // Combine switch states into a single byte
    return (sw1_state << 1) | sw2_state;
}

// Function to control LED based on switch combination
void Control_LED(uint8_t switch_state) {
    switch (switch_state) {
        case 0:  // Neither switch pressed
            *GPIO_DATAF_REG = 0;  // Turn off all LEDs
            break;
        case 1:  // SW2 pressed
            *GPIO_DATAF_REG = LED_RED | LED_BLUE;  // Turn on red and blue LEDs
            break;
        case 2:  // SW1 pressed
            *GPIO_DATAF_REG = LED_GREEN | LED_BLUE;  // Turn on green and blue LEDs
            break;
        case 3:  // Both switches pressed
            *GPIO_DATAF_REG = LED_RED | LED_GREEN | LED_BLUE;  // Turn on all LEDs
            break;
        default:
            break;
    }
}

int main() {
    // Initialize GPIO
    GPIO_Init();
    
    // Main loop
    while (1) {
        // Read switch states
        uint8_t switch_state = Read_Switches();
        
        // Control LED based on switch combination
        Control_LED(switch_state);
    }
    
    return 0;
}
