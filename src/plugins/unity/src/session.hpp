/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  Jacky Alciné <jackyalcine@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef SPEECHCONTROL_PLUGINS_UNITY_SESSION_HPP
#define SPEECHCONTROL_PLUGINS_UNITY_SESSION_HPP

#include <QObject>
#include <app/macros.hpp>

namespace SpeechControl
{
namespace Plugins
{
namespace Unity
{

class Session : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY (Session)
    SC_SINGLETON (Session)

public:
    static void init();
    static void deinit();
    virtual ~Session();
};

}

}

}

#endif // SPEECHCONTROL_PLUGINS_UNITY_SESSION_HPP
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
