# keyboard0 by ht12345
![keyboard0](https://geekhack.org/index.php?action=dlattach;topic=115921.0;attach=280953;image)

A tenkeyless keyboard with 5 additional macro keys, RGB lighting, 2 rotary encoders, OLED display, and USB hub daughterboard.
* Keyboard Maintainer: [ht12345](https://github.com/howardt12345)
* Hardware Supported: keyboard0 p2
* Hardware Availability: limited prototype quantities

There is currently one version of the keyboard0 (+revisions), with plans for future versions. Please use the appropriate firmware for your keyboard. **Pay close attention to the specific MCU and RGB controller.** 

* p2: MCU: **STM32F303CB**, RGB: 3x **IS31FL3731**
    * p2.1: MCU: **STM32F303CC**, RGB: 3x **IS31FL3731**

Make example for this keyboard (after setting up your build environment):

    make ht12345/keyboard0/p2:default # (p2)


See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
