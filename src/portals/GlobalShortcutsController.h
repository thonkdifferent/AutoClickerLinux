//
// Created by thonkdifferent on 02.06.24.
//

#ifndef GLOBALSHORTCUTSCONTROLLER_H
#define GLOBALSHORTCUTSCONTROLLER_H


#include "xdg_global_shortcuts_iface.h"
#include <QObject>
#include <QStringList>
#include <QRandomGenerator64>
#include <QMessageBox>


using Shortcut = QMap<QString,QVariantMap>;
struct GlobalShortcutsController : QObject{
Q_OBJECT
public:
    explicit GlobalShortcutsController();

public Q_SLOTS:
   void response(uint code, const QVariantMap& results);
    void onActivated(const QDBusObjectPath &session_handle, const QString &shortcut_id, qulonglong timestamp, const QVariantMap &options);
    void onDeactivated(const QDBusObjectPath &session_handle, const QString &shortcut_id, qulonglong timestamp, const QVariantMap &options);
    void onShortcutsChanged(const QDBusObjectPath &session_handle, const QList<QPair<QString,QVariantMap>> &shortcuts);
private:
    void report_portal_error(QString message);
    void report_portal_error(QString title, QString message);
    OrgFreedesktopPortalGlobalShortcutsInterface *iface;
    QString handle_id;

};



#endif //GLOBALSHORTCUTSCONTROLLER_H
