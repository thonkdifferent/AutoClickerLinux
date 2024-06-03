cmake_minimum_required(VERSION 3.16)

project(autoclickerlinux VERSION 1.0)

set(QT_MIN_VERSION "6.5.0")
set(KF_MIN_VERSION "6.0.0")
set(CMAKE_CXX_STANDARD 20)
find_package(ECM ${KF_MIN_VERSION} REQUIRED)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMInstallIcons)
include(FeatureSummary)

find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    DBus
)
pkg_check_modules(PC_EVDEV libevdev REQUIRED)

find_path(EVDEV_INCLUDE_DIR libevdev/libevdev.h
        HINTS ${PC_EVDEV_INCLUDE_DIRS} ${PC_EVDEV_INCLUDEDIR})
message(${EVDEV_INCLUDE_DIR})
find_library(EVDEV_LIBRARY
        NAMES evdev libevdev)


find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    I18n
    Config
    WidgetsAddons
    XmlGui
)
find_package(PkgConfig REQUIRED)


add_subdirectory(src)
add_subdirectory(icons)

# Make it possible to use the po files fetched by the fetch-translations step
ki18n_install(po)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
