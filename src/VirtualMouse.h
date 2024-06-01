//
// Created by thonkdifferent on 01.06.24.
//

#ifndef VIRTUALMOUSE_H
#define VIRTUALMOUSE_H
#include "evdev/EvDevDevice.h"


struct VirtualMouse : EvDevDevice{
    explicit VirtualMouse();

    void click();


};



#endif //VIRTUALMOUSE_H
