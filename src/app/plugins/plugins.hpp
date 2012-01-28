/**
 * This file is part of SpeechControl
 *
 * Copyright 2011 Jacky Alcine <jacky.alcine@thesii.org>
 *
 * SpeechControl is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * SpeechControl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with SpeechControl; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef PLUGINS_HPP
#define PLUGINS_HPP

#include <QObject>

class QPluginLoader;
class QSettings;

namespace SpeechControl {
    class Factory;
    class AbstractPlugin;

    class Factory : public QObject {
      Q_OBJECT

    public:
      explicit Factory(QObject* = 0);
    };

    class AbstractPlugin : public QObject {
      Q_OBJECT

    public:
      explicit AbstractPlugin(QObject* = 0);
      const QString name() const;
      const double version() const;

    private:
      QPluginLoader* m_loader;
      QSettings* m_config;
      QSettings* m_sttgs;
    };

}

#endif // PLUGINS_HPP
