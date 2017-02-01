/***************************************************************************
 *   Copyright (C) 2014 Daniel Nicoletti <dantti12@gmail.com>              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; see the file COPYING. If not, write to       *
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,  *
 *   Boston, MA 02110-1301, USA.                                           *
 ***************************************************************************/

#include "root.h"

#include <Cutelyst/Context>
#include <Cutelyst/Plugins/Session/Session>

#include <QDebug>

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>

Root::Root(QObject *app) : Controller(app)
{
}

Root::~Root()
{
}

void Root::hello(Context *c)
{
    c->response()->setBody(QByteArrayLiteral("Hello World! \n"));
}

void Root::json(Context *c)
{
    QJsonObject obj;
    obj.insert(QStringLiteral("message"), QStringLiteral("Hello, World!"));

    c->res()->setJsonBody(QJsonDocument(obj));
}

void Root::session(Context *c)
{
    QString foo = Session::value(c, QStringLiteral("foo")).toString();

    c->response()->setBody(QLatin1String("Foo: ") + foo + QLatin1Char('\n'));

    Session::setValue(c, QStringLiteral("foo"), QStringLiteral("bar"));
}

void Root::read_session(Context *c)
{
    QString foo = Session::value(c, QStringLiteral("foo")).toString();
    c->response()->setBody(QLatin1String("Foo: ") + foo + QLatin1Char('\n'));
}
