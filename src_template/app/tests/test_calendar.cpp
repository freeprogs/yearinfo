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
    void testGetPart();
    void testTableLookUp();
};

void TestCalendar::testGetPart()
{
    CalendarFunctions obj;

    // values without table lookup
    QVERIFY(obj.getPart(1, 1, 1800, true) == CalendarFunctions::P_Small);
    QVERIFY(obj.getPart(1, 2, 1800, true) == CalendarFunctions::P_Unknown);
    QVERIFY(obj.getPart(1, 4, 1800, true) == CalendarFunctions::P_Big);

    // values with table lookup
    QVERIFY(obj.getPart(1, 1, 2016, true) == CalendarFunctions::P_Small);
    QVERIFY(obj.getPart(7, 2, 2016, true) == CalendarFunctions::P_Small);
    QVERIFY(obj.getPart(8, 2, 2016, true) == CalendarFunctions::P_Big);
    QVERIFY(obj.getPart(1, 4, 2016, true) == CalendarFunctions::P_Big);

    // values in before our era
    QVERIFY(obj.getPart(1, 1, 2016, false) == CalendarFunctions::P_Small);
    QVERIFY(obj.getPart(1, 2, 2016, false) == CalendarFunctions::P_Unknown);
    QVERIFY(obj.getPart(1, 4, 2016, false) == CalendarFunctions::P_Big);

    // left border value
    QVERIFY(obj.getPart(1, 1, 4294967295, false) == CalendarFunctions::P_Small);

    // right border value
    QVERIFY(obj.getPart(31, 12, 4294967295, true) == CalendarFunctions::P_Big);
}

void TestCalendar::testTableLookUp()
{
    CalendarFunctions obj;

    // left border value
    QVERIFY(obj.tableLookUp(1900) == QDate(1900, 1, 31));

    // right border value
    QVERIFY(obj.tableLookUp(2043) == QDate(2043, 2, 10));

    // middle value
    QVERIFY(obj.tableLookUp(2000) == QDate(2000, 2, 5));

    // before left border value
    QVERIFY(obj.tableLookUp(1899) == QDate(0, 0, 0));

    // after right border value
    QVERIFY(obj.tableLookUp(2044) == QDate(0, 0, 0));
}

QTEST_MAIN(TestCalendar)
#include "test_calendar.moc"
