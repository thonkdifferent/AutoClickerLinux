//
// Created by thonkdifferent on 01.06.24.
//

#include "EvDevDevice.h"

#include <libevdev/libevdev.h>
#include <libevdev/libevdev.h>

EvDevDevice::EvDevDevice() {
    UNWRAP_NULL(m_libevdev,libevdev_new())
}

void EvDevDevice::enable_event(uint evdev_event) {
    GUARD_NEG1(libevdev_enable_event_type(m_libevdev,evdev_event))
}

void EvDevDevice::enable_event_code(uint event, uint code) {
    GUARD_NEG1(libevdev_enable_event_code(m_libevdev,event,code, nullptr))
}

void EvDevDevice::save_device_changes() {
    if(this->m_uinput != nullptr) libevdev_uinput_destroy(m_uinput);
    GUARD_NERR(libevdev_uinput_create_from_device(m_libevdev,LIBEVDEV_UINPUT_OPEN_MANAGED,&m_uinput))
}

void EvDevDevice::set_name(std::string_view name) noexcept {
    libevdev_set_name(m_libevdev, name.data());
}

void EvDevDevice::set_vendor_id(int vendor_id) noexcept {
    libevdev_set_id_vendor(m_libevdev, vendor_id);
}

void EvDevDevice::set_product_id(int product_id) noexcept {
    libevdev_set_id_product(m_libevdev, product_id);
}

void EvDevDevice::set_hardware_version(int version) noexcept {
    libevdev_set_id_version(m_libevdev, version);
}

int EvDevDevice::vendor_id() const noexcept {
    return libevdev_get_id_vendor(m_libevdev);
}

int EvDevDevice::product_id() const noexcept {
    return libevdev_get_id_product(m_libevdev);
}

int EvDevDevice::hardware_version() const noexcept {
    return libevdev_get_id_version(m_libevdev);
}

int EvDevDevice::failiure_code() const noexcept {
    return fail;
}

const char * EvDevDevice::name() const noexcept {
    if(m_libevdev == nullptr ) return "";
    return libevdev_get_name(m_libevdev);
}


void EvDevDevice::stage_event(uint event, uint code, int value) {
    GUARD_NERR(libevdev_uinput_write_event(m_uinput, event,code,value))
}

void EvDevDevice::commit_events() {
    stage_event(EV_SYN,SYN_REPORT,0);
}
