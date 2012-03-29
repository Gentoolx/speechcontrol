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
 *  along with SpeechControl .  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef SESSION_HPP
#define SESSION_HPP

#include <QMap>
#include <QList>
#include <QObject>
#include <QDateTime>
#include <QDomDocument>

#include <app/sessions/phrase.hpp>

namespace SpeechControl
{
class Phrase;
class Corpus;
class Content;
class Session;

/**
 * @brief Represents a @c QList of @c Session objects.
 **/
typedef QList<Session*> SessionList;

/**
 * @brief Represents a @c QMap of @c Session objects, mapped by their @c QString keys.
 **/
typedef QMap<QString, Session*> SessionMap;

/**
 * @brief Represents data to be used for adaption.
 **/
class Session : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY (Session)

public:
    /**
     * @brief New Session with ID
     *
     * @param  QString ID of the Session
     **/
    explicit Session (const QString& p_id);

    /**
     * @brief Destructor
     **/
    virtual ~Session();

    /**
     * @brief ID of the Session
     *
     * @return ID of the Session
     **/
    QString id() const;

    /**
     * @brief ...
     *
     * @return Name of the Session
     **/
    QString name() const;

    /**
     * @brief Check if the Session is completed.
     *
     * @return Boolean of completion
     **/
    bool isCompleted() const;

    /**
     * @brief Check if the Session is valid.
     *
     * @return Boolean of validity
     **/
    bool isValid() const;

    void erase() const;

    /**
     * @brief Sets the name of this @c Session.
     * @param  p_name The new name of the @c Session.
     **/
    void setName (const QString& p_name);

    /**
     * @brief Clones this entire Session's data.
     *
     * @return The cloned Session.
     **/
    Session* clone() const;

    /**
     * @brief Obtains the Corpus used by this Session.
     **/
    Corpus* corpus() const;

    /**
     * @brief Obtains the Content used by this Session.
     **/
    Content* content() const;

    Phrase* firstIncompletePhrase() const;
    Phrase* lastIncompletePhrase() const;
    PhraseList incompletedPhrases() const;
    QDateTime dateCompleted() const;
    QDateTime dateCreated() const;
    static void init();
    static Session* obtain (const QString& p_id);
    static Session* create (const Content* p_content);
    static void save();
    static SessionList allSessions();
    static SessionList completedSessions();
    static SessionList incompleteSessions();

signals:
    /**
     * @brief Signal emitted when the Session progress changes.
     *
     * @param  progress Amount of progress changed
     **/
    void progressChanged (const double& p_progress) const;

public slots:
    /**
     * @brief Sets the Corpus for this Session.
     *
     * @param  p_corpus Corpus for this Session
     **/
    void setCorpus (Corpus* p_corpus);

    /**
     * @brief Sets the Content for this Session.
     *
     * @param p_content The Content to represent this session.
     **/
    void setContent (Content* p_content);

    /**
     * @brief Loads a Session by its specified ID, p_id.
     *
     * @param p_id The ID to load the Session with.
     **/
    void load (const QString& p_id);

    /**
     * @brief Assesses the progress completed by this Session.
     *
     * @return The progress completed of this Session.
     **/
    double assessProgress() const;

private:
    static QDomDocument* s_dom;
    static QMap<QString, QDomElement*> s_elems;
    Corpus* m_corpus;
    Content* m_content;
    QDomElement* m_elem;
};
}

#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
