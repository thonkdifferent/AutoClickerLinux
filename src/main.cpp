/*
    SPDX-FileCopyrightText: 2024 ThonkDifferent <thonkdifferent@outlook.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application header
#include "autoclickerlinuxwindow.h"

// KF headers
#include <KAboutData>
#include <KLocalizedString>
#include <KConfig>
#include "VirtualMouse.h"

// Qt headers
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("autoclickerlinux");

    KAboutData aboutData(QStringLiteral("autoclickerlinux"),
                         i18n("AutoClickerLinux"),
                         QStringLiteral("1.0"),
                         i18n("A Simple Application written with KDE Frameworks"),
                         KAboutLicense::GPL,
                         i18n("Copyright 2024, ThonkDifferent <thonkdifferent@outlook.com>"));

    aboutData.addAuthor(i18n("ThonkDifferent"),i18n("Author"), QStringLiteral("thonkdifferent@outlook.com"));
    aboutData.addAuthor(i18n("Kommult"),i18n("Icon Designer"));
    aboutData.setOrganizationDomain("example.org");
    aboutData.setDesktopFileName(QStringLiteral("org.example.autoclickerlinux"));

    KAboutData::setApplicationData(aboutData);
    QApplication::setWindowIcon(QIcon::fromTheme(QStringLiteral("autoclickerlinux")));

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);

    parser.process(application);
    aboutData.processCommandLine(&parser);

    std::unique_ptr<VirtualMouse> vmouse = std::make_unique<VirtualMouse>();

    if(vmouse->failiure_code())
        return 1;


    AutoClickerLinuxWindow *mainWindow = new AutoClickerLinuxWindow(std::move(vmouse));
    mainWindow->show();

    return application.exec();
}
