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

#include <QString>
#include "acousticmodel.hpp"

using SpeechControl::AcousticModel;

AcousticModel::AcousticModel(const AcousticModel &p_mdl) :
    QObject(p_mdl.parent()) {

}

AcousticModel::~AcousticModel()
{
}

void AcousticModel::setParameter(const QString &p_str, const QVariant &p_val)
{
}

void AcousticModel::setParameters(const QVariantMap &p_vals)
{
}

void AcousticModel::mergeParameters(const QVariantMap &p_vals)
{
}

QVariant AcousticModel::parameter(const QString &p_str) const
{
    return QVariant();
}

const QVariantMap AcousticModel::parameters() const
{
    return QVariantMap();
}

const quint16 AcousticModel::sampleRate() const
{
    return 0;
}

void AcousticModel::setSampleRate(const quint16 &p_rate)
{
}

#ifdef WITH_PYTHON_BINDINGS

#include <boost/python.hpp>
#include <boost/noncopyable.hpp>

BOOST_PYTHON_MODULE(spchcntrl)
{
    using namespace boost::python;

    class_<AcousticModel>("AcousticModel", no_init)
    .add_property("samplerate"   , &AcousticModel::sampleRate, &AcousticModel::setSampleRate)
    .add_property("parameters"   , &AcousticModel::parameters, &AcousticModel::setParameters)
    ;

}

#endif