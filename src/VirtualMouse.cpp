//
// Created by thonkdifferent on 01.06.24.
//

#include "VirtualMouse.h"

VirtualMouse::VirtualMouse() {
    this->set_name("AutoClicker for Linux Virtual Mouse >:3");
    this->set_product_id(2395);
    this->set_vendor_id(69);
    this->set_hardware_version(1);

    this->enable_event(EV_KEY);
    this->enable_event_code(EV_KEY, BTN_LEFT);
    this->save_device_changes();
}

void VirtualMouse::click() {
    this->stage_event(EV_KEY,BTN_LEFT,1);
    this->commit_events();
    this->stage_event(EV_KEY, BTN_LEFT, 0);
    this->commit_events();
}
