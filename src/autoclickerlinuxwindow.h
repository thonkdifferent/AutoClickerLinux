/*
    SPDX-FileCopyrightText: 2024 ThonkDifferent <thonkdifferent@outlook.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef AUTOCLICKERLINUXWINDOW_H
#define AUTOCLICKERLINUXWINDOW_H


#include "ui_autoclickerlinux.h"

#include <KXmlGuiWindow>

#include "xdg_global_shortcuts_iface.h"
#include "VirtualMouse.h"

/**
 * This class serves as the main window for AutoClickerLinux.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author ThonkDifferent <thonkdifferent@outlook.com>
 * @version 1.0
 */
class AutoClickerLinuxWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    AutoClickerLinuxWindow(std::unique_ptr<VirtualMouse> virtual_mouse);

    /**
     * Default Destructor
     */
    ~AutoClickerLinuxWindow() override;

public Q_SLOTS:
    void onToggleKeyComboChanged(QKeySequence sequence);
    void onStartClicked();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::mainWidget m_ui;
    org::freedesktop::portal::GlobalShortcuts xdg_shortcuts_portal;
    QString m_handle;
    std::unique_ptr<VirtualMouse> mousy;
};

#endif // AUTOCLICKERLINUXWINDOW_H
