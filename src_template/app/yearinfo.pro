#
# This file is a part of __PROGRAM_NAME__ __PROGRAM_VERSION__
#
# This file installs __PROGRAM_NAME__ in the operating system, cleans
# temporary files and directory in the project.
#
# __PROGRAM_COPYRIGHT__ __PROGRAM_AUTHOR__ __PROGRAM_AUTHOR_EMAIL__
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T18:30:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yearinfo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pictures.cpp \
    calendar.cpp

HEADERS  += mainwindow.h \
    pictures.h \
    calendar.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
