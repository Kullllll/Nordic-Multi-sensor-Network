# Nordic Multi-sensor Network

Blink an LED forever using the GPIO API.

---

## Overview

The Blinky sample blinks an LED forever using the GPIO API.

The source code shows how to:

1. Get a pin specification from the devicetree as a `gpio_dt_spec`
2. Configure the GPIO pin as an output
3. Toggle the pin forever

See `pwm-blinky` for a similar sample that uses the PWM API instead.

---

## Requirements

Your board must:

1. Have an LED connected via a GPIO pin
2. Have the LED configured using the `led0` devicetree alias

---

## Building and Running

Build and flash Blinky as follows, changing `reel_board` for your board:

```bash
west build -b reel_board
west flash
```

After flashing, the LED starts to blink and messages with the current LED state are printed on the console.

If a runtime error occurs, the sample exits without printing to the console.

---

## Build Errors

You will see a build error at the source code line defining the `struct gpio_dt_spec led` variable if you try to build Blinky for an unsupported board.

On GCC-based toolchains, the error looks like this:

```text
error: '__device_dts_ord_DT_N_ALIAS_led_P_gpios_IDX_0_PH_ORD'
undeclared here (not in a function)
```

---

## Adding Board Support

To add support for your board, add something like this to your devicetree:

```dts
/ {
    aliases {
        led0 = &myled0;
    };

    leds {
        compatible = "gpio-leds";

        myled0: led_0 {
            gpios = <&gpio0 13 GPIO_ACTIVE_LOW>;
        };
    };
};
```

The above sets your board's `led0` alias to use pin 13 on GPIO controller `gpio0`.

The pin flag `GPIO_ACTIVE_HIGH` means the LED is on when the pin is set HIGH and off when the pin is LOW.

---

## Tips

- See `gpio-leds` for more information on defining GPIO-based LEDs
- Check supported board devicetrees for reference
- See `gpio.h` for available GPIO flags
- Use a devicetree overlay if your LED is external