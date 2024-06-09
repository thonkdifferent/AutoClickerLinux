//
// Created by thonkdifferent on 02.06.24.
//

#include "GlobalShortcutsController.h"
Q_DECLARE_METATYPE(Shortcut)
Q_DECLARE_METATYPE(QList<Shortcut>)
#define PORTAL_SIGNAL_CONNECT(interface,signalName,target,slot) {\
const bool ret = QDBusConnection::sessionBus().connect(QString(),\
        sessionReply.value().path(),\
        interface,\
        signalName,\
        target,\
        slot\
        );\
if(!ret)\
    report_portal_error("Could not bind to signalName");\
}
#define PORTAL(name) QLatin1String("org.freedesktop.portal.%1").arg(QStringLiteral(name))
void GlobalShortcutsController::report_portal_error(QString title, QString message)
 {
    QMessageBox::critical(nullptr, title,message);
    qFatal()<<message;
    exit(1);
    return;
}
void GlobalShortcutsController::report_portal_error(const char* message) {
    report_portal_error(QStringLiteral("Could not connect to connect to portal"),QLatin1String(message));
}

GlobalShortcutsController::GlobalShortcutsController() : iface(QLatin1String("org.freedesktop.portal.Desktop"), QLatin1String("/org/freedesktop/portal/desktop"),
                                                               QDBusConnection::sessionBus(), this),
                                                         handle_id(QStringLiteral("AutoClickerLinux-%1").arg(QRandomGenerator64::global()->generate()))
{


    const auto sessionParameters = QVariantMap{
                {QLatin1String("session_handle_token"),handle_id},
                {QLatin1String("handle_token"),handle_id}
    };

    auto sessionReply = iface.CreateSession(sessionParameters);
    sessionReply.waitForFinished();
    if(!sessionReply.isValid())
        report_portal_error("Could not connect to the global shortcuts portal.");


    const bool ret = QDBusConnection::sessionBus().connect(QString(),
        sessionReply.value().path(),
        QLatin1String("org.freedesktop.portal.Request"),
        QLatin1String("Response"),
        this,
        SLOT(response(uint,QVariantMap))
        );
    if(!ret)
        report_portal_error("Could not create a DBus session");


    qDBusRegisterMetaType<Shortcut>();
    qDBusRegisterMetaType<QList<Shortcut>>();

    PORTAL_SIGNAL_CONNECT(PORTAL("GlobalShortcuts"),QLatin1String("Activated"),this,SLOT(onShortcutActivated()))
    PORTAL_SIGNAL_CONNECT(PORTAL("GlobalShortcuts"),QLatin1String("Deactivated"),this, SLOT(onShortcutDeactivated()))
    PORTAL_SIGNAL_CONNECT(PORTAL("GlobalShortcuts"),QLatin1String("ShortcutsChanged"),this,SLOT(onShortcutsChanged()))
}

void GlobalShortcutsController::response(uint code, const QVariantMap &results) {
    if(code>0)//error :(
    {
        QStringList message;
        message<<QStringLiteral("More information here: \n")
                <<QStringLiteral("Code: ")<< QString::number(code)<<QStringLiteral("\n")
                <<QStringLiteral("Results: \n");
        for (auto& chars: results) {
                message<<chars.toStringList()<<QStringLiteral("\n");
        }
        report_portal_error(QStringLiteral("Something went wrong"),message.join(QStringLiteral(" ")));
    }



}
#undef PORTAL_SIGNAL_CONNECT
#undef PORTAL