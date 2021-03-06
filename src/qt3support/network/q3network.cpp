/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt3Support module of the Qt Toolkit.
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

#include "q3network.h"

#ifndef QT_NO_NETWORK

#include "q3networkprotocol.h"

// protocols
#include "q3ftp.h"
#include "q3http.h"

QT_BEGIN_NAMESPACE

/*!
    \relates Q3UrlOperator

    This function registers the network protocols for FTP and HTTP.
    You must call this function before you use QUrlOperator for
    these protocols.
*/
void q3InitNetworkProtocols()
{
#ifndef QT_NO_NETWORKPROTOCOL_FTP
    Q3NetworkProtocol::registerNetworkProtocol( QLatin1String("ftp"), new Q3NetworkProtocolFactory< Q3Ftp > );
#endif
#ifndef QT_NO_HTTP
    Q3NetworkProtocol::registerNetworkProtocol( QLatin1String("http"), new Q3NetworkProtocolFactory< Q3Http > );
#endif
}

QT_END_NAMESPACE

#endif // QT_NO_NETWORK
