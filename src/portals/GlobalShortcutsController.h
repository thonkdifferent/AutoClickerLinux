//
// Created by thonkdifferent on 02.06.24.
//

#ifndef GLOBALSHORTCUTSCONTROLLER_H
#define GLOBALSHORTCUTSCONTROLLER_H

#include "globalshortcutsadaptor.h"
#include "xdg_global_shortcuts_iface.h"
#include <QObject>
#include <QStringList>
#include <QRandomGenerator64>
#include <QMessageBox>


struct Shortcut {
    QString id;
    QVariantMap trigger;
};
struct GlobalShortcutsController : QObject{

    explicit GlobalShortcutsController();

public Q_SLOTS:
   void response(uint code, const QVariantMap& results);
private:
    void report_portal_error(const char *message);
    void report_portal_error(QString title, QString message);
    OrgFreedesktopPortalGlobalShortcutsInterface iface;
    QString handle_id;

};



#endif //GLOBALSHORTCUTSCONTROLLER_H
