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

#ifdef PYTHON_BINDINGS

// Boost includes
#include <boost/python.hpp>
#include <boost/noncopyable.hpp>

// Python includes
#include "traceback.h"

// local includes
#include "system.hpp"
#include "sphinx.hpp"
#include "microphone.hpp"
#include "acousticmodel.hpp"

struct SystemStruct {
public:
  static void start() {
    SpeechControl::System::start();
  }

  static void stop() {
    SpeechControl::System::stop();
  }
};

/// @note issue 0000033
BOOST_PYTHON_MODULE(spchcntrl)
{
    using namespace boost::python;
    using SpeechControl::Sphinx;
    using SpeechControl::Microphone;
    using SpeechControl::AcousticModel;

    class_<SystemStruct>("System", no_init)
      .def("stop" , &SystemStruct::stop)
      .def("start", &SystemStruct::start)
    ;

    class_<AcousticModel>("AcousticModel", no_init)
      .add_property("samplerate"   , &AcousticModel::sampleRate, &AcousticModel::setSampleRate)
      .add_property("parameters"   , &AcousticModel::parameters, &AcousticModel::setParameters)
    ;

    class_<Microphone>("Microphone", no_init)
      .add_property("uuid" 	   , &Microphone::uuid)
      .add_property("active" 	   , &Microphone::active)
      .add_property("friendlyName" , &Microphone::friendlyName)
      //.def("defaultMicrophone", &Microphone::defaultMicrophone)
    ;

    class_<Sphinx>("Sphinx", init<const AcousticModel*>("AcousticModel"))
      .add_property("text", &Sphinx::text)
    ;
}

#else
#warning "Python bindings for libspeechcontrol have been disabled. Ensure that your build system has found the required libraries and development files to re-enable binding support."
#endif /* PYTHON_BINDINGS */