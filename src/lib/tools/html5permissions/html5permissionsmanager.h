/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2013-2014  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef HTML5PERMISSIONSMANAGER_H
#define HTML5PERMISSIONSMANAGER_H

#include <QObject>
#include <QStringList>

#include "qzcommon.h"
#include "webpage.h"

class QUrl;
class WebPage;

class QUPZILLA_EXPORT HTML5PermissionsManager : public QObject
{
public:
    explicit HTML5PermissionsManager(QObject* parent);

#if QTWEBKIT_FROM_2_2
    void requestPermissions(WebPage* page, QWebEngineFrame* frame, const QWebEnginePage::Feature &feature);
    void rememberPermissions(const QString &host, const QWebEnginePage::Feature &feature,
                             const QWebEnginePage::PermissionPolicy &policy);
#endif

    void loadSettings();
    void showSettingsDialog();

private:
    void saveSettings();

    QStringList m_notificationsGranted;
    QStringList m_notificationsDenied;

    QStringList m_geolocationGranted;
    QStringList m_geolocationDenied;
};

#endif // HTML5PERMISSIONSMANAGER_H
