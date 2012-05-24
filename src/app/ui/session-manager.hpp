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


#ifndef SESSIONMANAGER_HPP
#define SESSIONMANAGER_HPP

#include <QDialog>

class QListWidgetItem;

namespace Ui
{
class SessionManager;
}

namespace SpeechControl
{
class Session;
namespace Windows
{
namespace Managers
{

class SessionManager : public QDialog
{
    Q_OBJECT

public:
    explicit SessionManager (QWidget* parent = 0);
    ~SessionManager();
    static Session* pickSession();
    Session* session() const;

private slots:
    void on_btnCancel_clicked();
    void on_btnSelect_clicked();
    void on_btnCreate_clicked();
    void updateList();
    void on_listSession_itemSelectionChanged();
    void on_listSession_itemDoubleClicked (QListWidgetItem* p_item);

private:
    Ui::SessionManager* m_ui;
    Session* m_session;
};

}
}
}

#endif // SESSIONMANAGER_HPP
// kate: indent-mode cstyle; replace-tabs on; 
