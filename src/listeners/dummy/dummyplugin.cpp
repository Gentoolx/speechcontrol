/*
 * This file is part of SpeechControl.
 *
 * Copyright 2012 Jacky Alcine <jacky.alcine@thesii.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "dummyplugin.hpp"
#include "dummylistener.hpp"

using SpeechControl::Listeners::DummyPlugin;
using SpeechControl::Listeners::DummyListener;
using SpeechControl::Listeners::AbstractListener;

DummyPlugin::DummyPlugin(QObject* parent): AbstractPlugin(parent)
{
}

QSettings* DummyPlugin::settings() const
{
  return new QSettings(AbstractPlugin::settingsPath("dummy").toLocalFile());
}

AbstractListener* DummyPlugin::listener() const
{
  return new DummyListener;
}
