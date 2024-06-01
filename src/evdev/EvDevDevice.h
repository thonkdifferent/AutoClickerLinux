//
// Created by thonkdifferent on 01.06.24.
//

#ifndef EVDEV_H
#define EVDEV_H
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>
#include <string_view>
#include <sstream>


#include "EvDevDevice.h"
#include "EvDevException.h"



class EvDevDevice {
public:

    explicit EvDevDevice();
    void enable_event(uint evdev_event);
    void enable_event_code(uint event, uint code);
    void save_device_changes();

    void set_name(std::string_view name) noexcept;
    void set_vendor_id(int vendor_id) noexcept;
    void set_product_id(int product_id) noexcept;
    void set_hardware_version(int version) noexcept;

    [[nodiscard]] const char* name() const noexcept;
    [[nodiscard]] int vendor_id() const noexcept;
    [[nodiscard]] int product_id() const noexcept;
    [[nodiscard]] int hardware_version() const noexcept;
    [[nodiscard]] int failiure_code() const noexcept;
    void stage_event(uint event, uint code, int value);
    void commit_events();
protected:
    ~EvDevDevice() {
        libevdev_free(m_libevdev);
        libevdev_uinput_destroy(m_uinput);
    }
    libevdev* m_libevdev = nullptr;
    libevdev_uinput* m_uinput = nullptr;
    int fail = 0;
};



#endif //EVDEV_H
