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

#include "upload.hpp"
#include "ui_voxforgewizard-upload.h"

using namespace SpeechControl::Windows::Pages;

UploadEnaction::UploadEnaction (QWidget* parent) : QWizardPage (parent), ui (new Ui::UploadEnaction)
{
    ui->setupUi (this);
    this->setWindowIcon (QIcon::fromTheme ("go-up"));
    this->setLayout (ui->gridLayout);
}

UploadEnaction::~UploadEnaction()
{

}

#include "ui/wizards/voxforge/upload.moc"
// kate: indent-mode cstyle; replace-tabs on; 
