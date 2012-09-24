/***
 *  This file is part of the SpeechControl project.
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
 *  You should have received a copy of the GNU Library General Public
 *  License along with SpeechControl .
 *  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/**
 * @author Jacky Alciné <jackyalcine@gmail.com>
 * @date 05/20/12 14:48:29 PM
 */

/*!
 * \mainpage The %SpeechControl Application
 *
 * %SpeechControl's primary goal is to provide efficient and simple speech recognition
 * services to the Linux desktop (or whichever desktop it happens to be compiled on).
 * Using CMU's Sphinx speech recognition libraries and the Voxforge collective, we take
 * on a task never to be ventured before by a open-source community. It happens to also
 * be one of the many applications to be released by the Synthetic Intellect Institute.
 *
 * Visit the Synthetic Intellect Institute on the web at http://www.thesii.org.
 * The bug tracker for the Institute is at http://tasks.thesii.org and SpeechControl's
 * registered under the tracker as a component. Feel free to report bugs and help us
 * make %SpeechControl a fantastic, open-source tool.
 */

#include <QIcon>
#include <QApplication>
#include "global.hpp"
#include "core.hpp"

// pretty simple, huh?
int main (int argc, char** argv)
{
    QApplication* app = new QApplication (argc, argv);

    app->setApplicationName ("SpeechControl");
    app->setOrganizationDomain ("thesii.org");
    app->setOrganizationName ("Synthetic Intellect Institute");
    app->setWindowIcon (QIcon (":/logo/sc-large"));
    app->setApplicationVersion (SPCHCNTRL_BUILD_VERSION);
    app->setQuitOnLastWindowClosed (false);

    // Initialize SpeechControl's core.
    SpeechControl::Core appCore (argc, argv, app);
    appCore.start();
    return app->exec();
}
// kate: indent-mode cstyle; replace-tabs on;

