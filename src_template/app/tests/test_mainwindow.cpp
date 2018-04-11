/*
 * This file is a part of __PROGRAM_NAME__ __PROGRAM_VERSION__
 *
 * __PROGRAM_COPYRIGHT__ __PROGRAM_AUTHOR__ __PROGRAM_AUTHOR_EMAIL__
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtTest/QtTest>
#include "../mainwindow.h"

class TestMainwindow: public QObject
{
    Q_OBJECT
private slots:
    void testIsLeapYear();
    void testIsLeapNegativeYear();
};

void TestMainwindow::testIsLeapYear()
{
    MainWindowFunctions obj;

    QVERIFY(obj.isLeapYear(2012));
    QVERIFY(!obj.isLeapYear(2013));
    QVERIFY(!obj.isLeapYear(2014));
    QVERIFY(!obj.isLeapYear(2015));
    QVERIFY(obj.isLeapYear(2016));

    QVERIFY(obj.isLeapYear(1600));
    QVERIFY(!obj.isLeapYear(1700));
    QVERIFY(!obj.isLeapYear(1800));
    QVERIFY(!obj.isLeapYear(1900));
    QVERIFY(obj.isLeapYear(2000));
}

void TestMainwindow::testIsLeapNegativeYear()
{
    MainWindowFunctions obj;

    QVERIFY(obj.isLeapNegativeYear(1));
    QVERIFY(!obj.isLeapNegativeYear(2));
    QVERIFY(!obj.isLeapNegativeYear(3));
    QVERIFY(!obj.isLeapNegativeYear(4));
    QVERIFY(obj.isLeapNegativeYear(5));

    QVERIFY(obj.isLeapNegativeYear(1));
    QVERIFY(!obj.isLeapNegativeYear(101));
    QVERIFY(!obj.isLeapNegativeYear(201));
    QVERIFY(!obj.isLeapNegativeYear(301));
    QVERIFY(obj.isLeapNegativeYear(401));
}

QTEST_MAIN(TestMainwindow)
#include "test_mainwindow.moc"
