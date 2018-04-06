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
#include "../calendar.h"

class TestCalendar: public QObject
{
    Q_OBJECT
private slots:
    void testValues();
};

void TestCalendar::testValues()
{
    Calendar obj;
    Calendar::BasisIndex res;

    obj.setDate(1, 1, 2017, true);
    res = obj.getBasis();
    QVERIFY(res == Calendar::B_Yan);
}

QTEST_MAIN(TestCalendar)
#include "test_calendar.moc"
