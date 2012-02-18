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

#ifndef SESSION_HPP
#define SESSION_HPP

#include <QMap>
#include <QUuid>
#include <QObject>
#include <QDateTime>
#include <QStringList>
#include <QtXml/QDomDocument>

namespace SpeechControl {
    class Corpus;
    class Content;
    class Sentence;
    class Session;

    typedef QList<Session*> SessionList;
    typedef QList<Content*> ContentList;
    typedef QList<Sentence*> SentenceList;

    typedef QMap<QUuid, Content*> ContentMap;
    typedef QMap<QUuid, Session*> SessionMap;

    /// @todo Find a proper means of attribution.
    class Content : public QObject {
        Q_OBJECT
        Q_DISABLE_COPY(Content)

    public:
        explicit Content(const QUuid&);
        virtual ~Content();
        void load(const QUuid&);
        void erase();
        const uint pageCount() const;
        const uint words() const;
        const uint length() const;
        const uint characters() const;
        const QUuid uuid() const;
        const QString title() const;
        const QString author() const;
        const QStringList pages() const;
        const QString pageAt(const int&) const;
        static Content* create(const QString&, const QString&, const QString& );
        static Content* obtain(const QUuid&);
        static ContentList allContents();

    private:
        static QString getPath(const QUuid&);
        static ContentMap s_lst;
        QStringList m_pages;
        QDomDocument* m_dom;
        QUuid m_uuid;
    };

    class Session : public QObject {
        Q_OBJECT
        Q_DISABLE_COPY(Session)
        Q_PROPERTY(Corpus* Corpus READ corpus WRITE setCorpus)
        Q_PROPERTY(QUuid Uuid READ uuid)
        Q_PROPERTY(Content* Content READ content WRITE setContent)

    public:
        class Backup {
            friend class Session;
        public:
            virtual ~Backup();
            Session* session();
            QDateTime created();

        private:
            static const QString getPath(const QString&);
            static Backup* generate(const Session&);
            explicit Backup();
            QDomDocument* m_dom;
        };

        typedef QList<Backup*> BackupList;

        explicit Session(const QUuid&);
        virtual ~Session();
        const QUuid uuid() const;
        const bool isCompleted() const;
        const bool isValid() const;
        void erase() const;
        Session* clone() const;
        Backup* createBackup() const;
        BackupList* backups() const;
        Corpus* corpus() const;
        Content* content() const;
        Sentence* firstIncompleteSentence() const;
        Sentence* lastIncompleteSentence() const;
        SentenceList incompletedSentences() const;

        static void init();
        static Session* obtain(const QUuid&);
        static Session* create(const Content*);
        static SessionList allSessions();

    signals:
        void progressChanged(const double& );

    public slots:
        void setCorpus(Corpus* );
        void setContent(Content* );
        void load(const QUuid&);
        void assessProgress();

    private:
        //static const QString getPath(const QUuid&);
        static QDomDocument* s_dom;
        static QMap<QUuid, QDomElement*> s_elems;
        Corpus* m_corpus;
        Content* m_content;
        QDomElement* m_elem;
    };
}

#endif // SESSION_HPP
