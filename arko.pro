############################################################################
 ##
 ## Copyright (C) 2010-2012 Dmitriy Sukharev.
 ## All rights reserved.
 ## Contact: Dmitriy Sukharev (ecuna@mail.ru)
 ##
 ## This file is part of Arko.
 ##
 ## Arko is free software: you can redistribute it and/or modify
 ## it under the terms of the GNU Lesser General Public License as published
 ## by the Free Software Foundation, either version 3 of the License, or
 ## (at your option) any later version.
 ##
 ## Arko is distributed in the hope that it will be useful,
 ## but WITHOUT ANY WARRANTY; without even the implied warranty of
 ## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ## GNU Lesser General Public License for more details.
 ##
 ## You should have received a copy of the GNU Lesser General Public License
 ## along with Arko.  If not, see <http://www.gnu.org/licenses/>.
 ##
 ############################################################################

#-------------------------------------------------
#
# Project created by QtCreator 2010-11-27T17:33:51
#
#-------------------------------------------------

QT       += core gui

TARGET = arko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamearea.cpp \
    arkanoidmodel.cpp \
    ball.cpp \
    shield.cpp \
    bricktable.cpp \
    brick.cpp

HEADERS  += mainwindow.h \
    gamearea.h \
    arkanoidmodel.h \
    ball.h \
    shield.h \
    bricktable.h \
    brick.h

FORMS    += mainwindow.ui
