/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qwaylandeglintegration.h"

#include "gl_integration/qwaylandglintegration.h"

#include "qwaylandeglwindow.h"

#include <QtCore/QDebug>

QWaylandEglIntegration::QWaylandEglIntegration(struct wl_display *waylandDisplay)
    : mWaylandDisplay(waylandDisplay)
    , mNativeEglDisplay(wl_egl_display_create(mWaylandDisplay))
{
    qDebug() << "Using Wayland-EGL";
}


QWaylandEglIntegration::~QWaylandEglIntegration()
{
    eglTerminate(mEglDisplay);
}

void QWaylandEglIntegration::initialize()
{
    EGLint major,minor;
    mEglDisplay = eglGetDisplay((EGLNativeDisplayType)mNativeEglDisplay);
    if (mEglDisplay == NULL) {
        qWarning("EGL not available");
    } else {
        if (!eglInitialize(mEglDisplay, &major, &minor)) {
            qWarning("failed to initialize EGL display");
            return;
        }
    }
}

QWaylandWindow *QWaylandEglIntegration::createEglWindow(QWidget *window)
{
    return new QWaylandEglWindow(window);
}

EGLDisplay QWaylandEglIntegration::eglDisplay() const
{
    return mEglDisplay;
}

wl_egl_display * QWaylandEglIntegration::nativeDisplay() const
{
    return mNativeEglDisplay;
}

QWaylandGLIntegration *QWaylandGLIntegration::createGLIntegration(QWaylandDisplay *waylandDisplay)
{
    return new QWaylandEglIntegration(waylandDisplay->wl_display());
}
