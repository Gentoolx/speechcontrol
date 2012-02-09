/**
 * This file is part of SpeechControl
 *
 * Copyright 2011 SpeechControl Developers <spchcntrl-devel@thesii.org>
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

#ifndef PLUGINS_SETTINGS_HPP
#define PLUGINS_SETTINGS_HPP

#include <QFrame>

namespace Ui {
    class PluginsSettingsPane;
}

namespace SpeechControl {
namespace Windows {

class PluginsSettingsPane : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(const QString Title READ title)
    Q_PROPERTY(const QString ID READ id)

public:
    explicit PluginsSettingsPane(QWidget *parent = 0);
    ~PluginsSettingsPane();
    const QString title() const;
    const QString id() const;

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_btnInfo_clicked();

private:
    Ui::PluginsSettingsPane *ui;
};

}}

#endif // PLUGINS_HPP
