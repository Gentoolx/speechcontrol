/***
 *  This file is part of SpeechControl.
 *
 *  Copyright (C) 2012 SpeechControl Developers <spchcntrl-devel@thesii.org>
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
 *  along with SpeechControl .  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

// libspchcntrl includes
#include <lib/microphone.hpp>

#include "micselect.hpp"
#include "app/windows/micsetup-wizard.hpp"
#include "ui_micwizard-select.h"

using namespace SpeechControl;
using namespace SpeechControl::Wizards::Pages;
using SpeechControl::Wizards::Pages::MicrophoneSelection;

/// @todo The loudness of the content spoken should begin detection here.
MicrophoneSelection::MicrophoneSelection ( QWidget *parent ) :
    QWizardPage ( parent ), ui ( new Ui::MicrophoneSelection ),
    m_mic ( Microphone::defaultMicrophone() ) {
    ui->setupUi ( this );
    this->registerField ( "mic",ui->comboBoxMicrophones,"currentIndex",SIGNAL ( currentIndexChanged ( QString ) ) );
}

MicrophoneSelection::~MicrophoneSelection() {
    delete ui;
}

/// @todo Fill the combo box with all of the mics.
void SpeechControl::Wizards::Pages::MicrophoneSelection::initializePage() {
    MicrophoneList l_allMics = Microphone::allMicrophones();
    if ( l_allMics.empty() ) {
        /// @todo Add error saying no mics found.
    } else {
        Q_FOREACH ( const Microphone* l_mic, l_allMics ) {
            ui->comboBoxMicrophones->addItem ( l_mic->name(),l_mic->id() );
        }
    }
}

bool SpeechControl::Wizards::Pages::MicrophoneSelection::validatePage() {
    if ( m_mic ) {
        wizard()->setProperty ( "mic-id",m_mic->id() );
    }

    return ui->progressBarFeedback->isEnabled();
}

void SpeechControl::Wizards::Pages::MicrophoneSelection::cleanupPage() {
    ui->comboBoxMicrophones->clear();
    ui->progressBarFeedback->setValue ( 0 );
    ui->progressBarFeedback->setFormat ( "inactive" );
}

bool SpeechControl::Wizards::Pages::MicrophoneSelection::isComplete() {
    return m_complete;
}

/// @todo Set the device to be detected for volume detection here.
/// @todo Set this page's value to this field.
void SpeechControl::Wizards::Pages::MicrophoneSelection::on_comboBoxMicrophones_activated ( int index ) {
    const QUuid l_uuid ( ui->comboBoxMicrophones->itemData ( index ).toString() );
    m_mic = Microphone::getMicrophone ( l_uuid );
}

#include "micselect.moc"
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
