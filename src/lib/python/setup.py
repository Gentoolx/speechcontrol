#
# Setup of Cython usage for libspeechcontrol.
#
# @author SpeechControl Developement <spchcntrl-devel@thesii.org>
#         Jacky Alcine <jacky.alcine@thesii.org>
#

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

# Is this right?
setup(ext_modules=[Extension(
                    "SpeechControl.System",
                    ["system.pyx", "../system.cpp"],
                    language = "c++")
    ],
    cmdclass={'build_ext': build_ext})