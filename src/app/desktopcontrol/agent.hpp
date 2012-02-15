/**
 * This file is part of SpeechControl
 *
<<<<<<< HEAD
 * Copyright 2011 SpeechControl Developers <spchcntrl-devel@thesii.org>
=======
 * Copyright 2011 Jacky Alcine <jacky.alcine@thesii.org>
>>>>>>> FETCH_HEAD
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

#ifndef AGENT_HPP
#define AGENT_HPP

#include <QObject>
#include <sphinx.hpp>

namespace SpeechControl {
    namespace DesktopControl {
        class Agent;

        class Agent : public QObject
        {
            Q_OBJECT
            Q_DISABLE_COPY(Agent)

        signals:
            void started();
            void stopped();

        public:
            explicit Agent(QObject* = 0);
            virtual ~Agent();

            static void start();
            static void stop();
            static void invokeCommand(const QString&);

            static Agent* instance();
            static const bool isActive();

        private:
            static Agent* s_inst;
            Sphinx* m_sphnx;
        };
    }
}

#endif // AGENT_H
