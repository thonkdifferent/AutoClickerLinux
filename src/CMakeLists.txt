qt_add_dbus_interface(XDG_SRCS portals/org.freedesktop.portal.GlobalShortcuts.xml xdg_global_shortcuts_iface)


add_executable(autoclickerlinux
        evdev/EvDevDevice.cpp
        evdev/EvDevDevice.h
        evdev/EvDevException.cpp
        evdev/EvDevException.h
        VirtualMouse.cpp
        VirtualMouse.h
        ${XDG_SRCS}
        portals/GlobalShortcutsController.cpp
        portals/GlobalShortcutsController.h
)

target_include_directories(autoclickerlinux PRIVATE ${EVDEV_INCLUDE_DIR})
target_sources(autoclickerlinux PRIVATE
    main.cpp
    autoclickerlinuxwindow.cpp
)

ki18n_wrap_ui(autoclickerlinux autoclickerlinux.ui)

target_link_libraries(autoclickerlinux
    KF6::CoreAddons
    KF6::I18n
    KF6::ConfigCore
    KF6::ConfigGui
    KF6::WidgetsAddons
    KF6::XmlGui
    Qt6::Widgets
    Qt6::DBus
    ${EVDEV_LIBRARY}
)

install( TARGETS autoclickerlinux ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} )
install( PROGRAMS org.example.autoclickerlinux.desktop DESTINATION ${KDE_INSTALL_APPDIR} )
install( FILES org.example.autoclickerlinux.metainfo.xml DESTINATION ${KDE_INSTALL_METAINFODIR} )
