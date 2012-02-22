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

#include "fileselect.hpp"
#include "ui_cw_fileselectionpage.h"

#include <QDebug>
#include <QTextStream>
#include <QDomDocument>
#include <QFileDialog>
#include <QMessageBox>

using SpeechControl::Wizards::Pages::FileSelectionPage;

FileSelectionPage::FileSelectionPage(QWidget *parent) :
    QWizardPage(parent),
    m_ui(new Ui::FileSelectionPage)
{
    m_ui->setupUi(this);
    registerField("file.content",m_ui->plainTextEdit,"plainText",SIGNAL(textChanged()));
    registerField("file.author",m_ui->lineEditAuthor);
    registerField("file.title",m_ui->lineEditTitle);
}

FileSelectionPage::~FileSelectionPage()
{
    delete m_ui;
}

void SpeechControl::Wizards::Pages::FileSelectionPage::on_toolButton_clicked()
{
    const QString l_filePath = QFileDialog::getOpenFileName(this, tr("Open Text File"), QDir::homePath(), tr("SpeechControl Books (*.spch)"));

    if (!l_filePath.isNull()){
        QFile* l_file = new QFile(l_filePath);
        l_file->open(QIODevice::ReadOnly);
        QDomDocument l_dom("Book");
        QString l_errMsg;
        int l_errLn, l_errCol;
        if (l_dom.setContent(l_file,&l_errMsg,&l_errLn,&l_errCol)){
            qDebug() << l_dom.documentElement().nodeName();
            const QDomElement l_book = l_dom.documentElement().namedItem("Book").toElement();
            const QString l_author = l_book.attribute("author");
            const QString l_title = l_book.attribute("title");
            const QString l_text = l_dom.documentElement().namedItem("Text").toElement().text();
            m_ui->lineEditAuthor->setText(l_author);
            m_ui->lineEditTitle->setText(l_title);
            m_ui->plainTextEdit->setPlainText(l_text);
            m_ui->lineEdit->setText(l_filePath);
        } else {
            if (QMessageBox::Ok == QMessageBox::warning(this,"Unable to Load Content","The file you've chosen is either in the wrong format or isn't valid.\nPlease try another file.\n\nMessage: " + l_errMsg + " on line " + QString::number(l_errLn) + ", col " + QString::number(l_errCol) ,QMessageBox::Ok,QMessageBox::Cancel))
                on_toolButton_clicked();
        }
    }
}
