#pragma once

enum my_layers {
    _COLEMAK = 0,
    _QWERTY,
    _NAV,
    _NUM,
    _SYM,
    _ADJ,
    // if you need more than 8 layers, you need to remove
    //   #define LAYER_STATE_8BIT
    // from config.h, which is there for space saving
};
