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

#include "sentence.hpp"
#include "corpus.hpp"
#include <QDomNodeList>

using SpeechControl::Corpus;
using SpeechControl::Sentence;

/// @todo Drop the addition of the element and have it request it from the base Corpus.
Sentence::Sentence ( Corpus* p_corpus, QDomElement *p_elem ) : m_elem ( p_elem ), m_corpus ( p_corpus ) {
    QDir l_dir;
    l_dir.mkpath ( audioPath().path() );

    // Build phrases.
    QDomNodeList l_nodes = m_elem->childNodes();
    for ( uint i = 0; i < l_nodes.length(); i++ )
        m_phrsLst << new Phrase ( this,i );
}

Corpus * Sentence::parentSession() const {
    return m_corpus;
}

const QUuid Sentence::uuid() const {
    return QUuid ( m_elem->attribute ( "uuid" ) );
}

const QDir Sentence::audioPath() const {
    return QDir ( m_corpus->audioPath().toLocalFile() + "/" + m_elem->attribute ( "file" ) );
}

/// @todo Merge all of the phrases together.
const QString Sentence::text() const {
    QString l_text;

    Q_FOREACH ( const Phrase* l_phrs, m_phrsLst ) {
        l_text += l_phrs->text() + " ";
    }

    return l_text.trimmed();
}

Sentence* Sentence::create ( Corpus *p_corpus, const QString& p_text ) {
    QDomElement* l_elem = new QDomElement ( p_corpus->m_dom->createElement ( "Sentence" ) );
    l_elem->setAttribute ( "file",QUuid::createUuid() );
    l_elem->setAttribute ( "index",p_corpus->sentences().count() );
    p_corpus->m_dom->documentElement().namedItem ( "Sentences" ).appendChild ( *l_elem );

    // form phrases
    QStringList l_words = p_text.split ( " ",QString::SkipEmptyParts );
    QString l_phrase;

    for ( int i = 0, j = 0; i < l_words.count(); i++, j++ ) {
        if ( j < 4 )
            l_phrase += l_words.at ( i ) + " ";

        if ( j == 3 || (i - 1 == l_words.count() ) ) {
            l_phrase = l_phrase.trimmed();

            QDomElement* l_phrsElem = new QDomElement ( p_corpus->m_dom->createElement ( "Phrase" ) );
            l_phrsElem->setAttribute ( "uuid",QUuid::createUuid() );
            l_phrsElem->appendChild ( p_corpus->m_dom->createTextNode ( l_phrase.toUtf8().toBase64() ) );
            l_elem->appendChild ( *l_phrsElem );

            j = -1;
            l_phrase.clear();
        }
    }

    return p_corpus->addSentence ( new Sentence ( p_corpus,l_elem ) );
}

bool Sentence::allPhrasesCompleted() const {
    Q_FOREACH ( const Phrase* l_phrs, phrases() ) {
        if ( !l_phrs->isCompleted() )
            return false;
    }

    return true;
}

bool Sentence::isPhraseCompleted ( const int &p_indx ) const {
    return phrases().at ( p_indx )->isCompleted();
}

int Sentence::index() const {
    return m_elem->attribute ( "index" ).toInt();
}

double Sentence::completedProgress() const {
    uint l_count = 0;

    for (int i = 0; i < phrases().count(); i++){
        if (isPhraseCompleted(i))
            l_count += 1;
    }

    return (double) (l_count) / (double) (phrases().count());
}

Sentence::~Sentence() {
    // What to clean up? :P
}

#include "sentence.moc"
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
