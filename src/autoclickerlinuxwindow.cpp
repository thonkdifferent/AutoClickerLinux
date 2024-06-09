/*
    SPDX-FileCopyrightText: 2024 ThonkDifferent <thonkdifferent@outlook.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#include "autoclickerlinuxwindow.h"

AutoClickerLinuxWindow::AutoClickerLinuxWindow(std::unique_ptr<VirtualMouse> virtual_mouse) :
    mousy(std::move(virtual_mouse))

{
    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);
    m_ui.setupUi(widget);

    m_ui.clickDelayBox->setMinimum(100);
    m_ui.clickDelayBox->setMaximum(5000);
    m_ui.clickDelayBox->setSingleStep(10);
    m_ui.clickDelayBox->setValue(500);

    connect(m_ui.toggleKeySequence,&KKeySequenceWidget::keySequenceChanged,this,&AutoClickerLinuxWindow::onToggleKeyComboChanged);
    connect(m_ui.pushButton,&QAbstractButton::clicked,this,&AutoClickerLinuxWindow::onStartClicked);
}

AutoClickerLinuxWindow::~AutoClickerLinuxWindow()
{
}

void AutoClickerLinuxWindow::onToggleKeyComboChanged(QKeySequence sequence) {

}

void AutoClickerLinuxWindow::onStartClicked() {
}

#include "moc_autoclickerlinuxwindow.cpp"
