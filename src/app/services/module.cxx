/***
 *  This file is part of SpeechControl.
 *
 *  Copyright (C) 2012 Jacky Alciné <jackyalcine@gmail.com>
 *
 *  SpeechControl is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  SpeechControl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with SpeechControl.  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "app/services/module.hxx"

using namespace SpeechControl::Services;

AbstractModulePrivate::AbstractModulePrivate (AbstractModule* p_qPtr) :
    q_ptr (p_qPtr)
{

}

void AbstractModulePrivate::changeState (AbstractModule::ActivityState p_state)
{
    Q_Q (AbstractModule);

    if (p_state == m_state)
        return;

    m_state = handleStateChange (p_state);
    emit q->stateChanged (m_state);
}

AbstractModule::ActivityState AbstractModulePrivate::handleStateChange (const AbstractModule::ActivityState p_state)
{
    return p_state;
}

AbstractModulePrivate::~AbstractModulePrivate()
{

}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
