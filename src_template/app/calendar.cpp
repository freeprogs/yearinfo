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

#include "calendar.h"

void Calendar::setDate(
    int day,
    int month,
    size_t year,
    bool isOurEra)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->isOurEra = isOurEra;
}

Calendar::BasisIndex Calendar::getBasis()
{
    BasisIndex res = B_Unknown;
    CalendarFunctions::PartOfYear part =
        calFuncs.getPart(day, month, year, isOurEra);

    if (part == CalendarFunctions::P_Unknown)
        return res;

    BasisIndex era_after[2] = { B_Yan, B_In };
    BasisIndex era_before[2] = { B_In, B_Yan };

    if (isOurEra) {
        if (part == CalendarFunctions::P_Big) {
            res = era_after[year % 2];
        }
        else if (part == CalendarFunctions::P_Small) {
            if (year > 1)
                res = era_after[(year - 1) % 2];
            else
                res = era_after[0];
        }
    } else {
        if (part == CalendarFunctions::P_Big)
            res = era_before[year % 2];
        else if (part == CalendarFunctions::P_Small)
            res = era_before[(year + 1) % 2];
    }
    return res;
}

Calendar::ElementIndex Calendar::getElement()
{
    ElementIndex res = E_Unknown;
    CalendarFunctions::PartOfYear part =
        calFuncs.getPart(day, month, year, isOurEra);

    if (part == CalendarFunctions::P_Unknown)
        return res;

    ElementIndex era_after[10] = { E_Metal, E_Metal, E_Water, E_Water,
                                   E_Wood, E_Wood, E_Fire, E_Fire,
                                   E_Earth, E_Earth };
    ElementIndex era_before[10] = { E_Metal, E_Metal, E_Earth, E_Earth,
                                    E_Fire, E_Fire, E_Wood, E_Wood,
                                    E_Water, E_Water };

    if (isOurEra) {
        if (part == CalendarFunctions::P_Big) {
            res = era_after[year % 10];
        }
        else if (part == CalendarFunctions::P_Small) {
            if (year > 1)
                res = era_after[(year - 1) % 10];
            else
                res = era_after[0];
        }
    } else {
        if (part == CalendarFunctions::P_Big)
            res = era_before[year % 10];
        else if (part == CalendarFunctions::P_Small)
            res = era_before[(year + 1) % 10];
    }
    return res;
}

Calendar::AnimalIndex Calendar::getAnimal()
{
    AnimalIndex res = A_Unknown;
    CalendarFunctions::PartOfYear part =
        calFuncs.getPart(day, month, year, isOurEra);

    if (part == CalendarFunctions::P_Unknown)
        return res;

    AnimalIndex era_after[12] = { A_Monkey, A_Rooster, A_Dog,
                                  A_Pig, A_Rat, A_Ox,
                                  A_Tiger, A_Rabbit, A_Dragon,
                                  A_Snake, A_Horse, A_Goat };
    AnimalIndex era_before[12] = { A_Rooster, A_Monkey, A_Goat,
                                   A_Horse, A_Snake, A_Dragon,
                                   A_Rabbit, A_Tiger, A_Ox,
                                   A_Rat, A_Pig, A_Dog };

    if (isOurEra) {
        if (part == CalendarFunctions::P_Big) {
            res = era_after[year % 12];
        }
        else if (part == CalendarFunctions::P_Small) {
            if (year > 1)
                res = era_after[(year - 1) % 12];
            else
                res = era_after[0];
        }
    } else {
        if (part == CalendarFunctions::P_Big)
            res = era_before[year % 12];
        else if (part == CalendarFunctions::P_Small)
            res = era_before[(year + 1) % 12];
    }
    return res;
}

CalendarFunctions::PartOfYear
CalendarFunctions::getPart(int day, int month, size_t year, bool isOurEra)
{
    // до 20 января включительно - старый год
    // после 20 февраля включительно - новый год

    if (month == 1 && day <= 20) {
        return CalendarFunctions::P_Small;
    }
    if (month > 2 || (month == 2 && day >= 20)) {
        return CalendarFunctions::P_Big;
    }
    if ((month == 1 && day > 20) || (month == 2 && day < 20)) {
        if (isOurEra) {
            QDate tableDate = tableLookUp(year);
            if (year == size_t(tableDate.year())) {
                QDate today(year, month, day);
                if (today >= tableDate)
                    return CalendarFunctions::P_Big;
                else
                    return CalendarFunctions::P_Small;
            }
        }
    }
    return CalendarFunctions::P_Unknown;
}

static QDate knownDatesTable[] = {
    QDate(2016, 2, 8), QDate(1900, 1, 31), QDate(1901, 2, 19),
    QDate(1902, 2, 8), QDate(1903, 1, 29), QDate(1904, 2, 16),
    QDate(1905, 2, 4), QDate(1906, 1, 25), QDate(1907, 2, 13),
    QDate(1908, 2, 2), QDate(1909, 1, 22), QDate(1910, 2, 10),
    QDate(1911, 1, 30), QDate(1912, 2, 18), QDate(1913, 2, 6),
    QDate(1914, 1, 26), QDate(1915, 2, 14), QDate(1916, 2, 3),
    QDate(1917, 1, 23), QDate(1918, 2, 11), QDate(1919, 2, 1),
    QDate(1920, 2, 20), QDate(1921, 2, 8), QDate(1922, 1, 28),
    QDate(1923, 2, 16), QDate(1924, 2, 5), QDate(1925, 1, 25),
    QDate(1926, 2, 13), QDate(1927, 2, 2), QDate(1928, 1, 23),
    QDate(1929, 2, 10), QDate(1930, 1, 30), QDate(1931, 2, 17),
    QDate(1932, 2, 6), QDate(1933, 1, 26), QDate(1934, 2, 14),
    QDate(1935, 2, 4), QDate(1936, 1, 24), QDate(1937, 2, 11),
    QDate(1938, 1, 31), QDate(1939, 2, 19), QDate(1940, 2, 8),
    QDate(1941, 1, 27), QDate(1942, 2, 15), QDate(1943, 2, 5),
    QDate(1944, 1, 25), QDate(1945, 2, 13), QDate(1946, 2, 2),
    QDate(1947, 1, 22), QDate(1948, 2, 10), QDate(1949, 1, 29),
    QDate(1950, 2, 17), QDate(1951, 2, 6), QDate(1952, 1, 27),
    QDate(1953, 2, 14), QDate(1954, 2, 3), QDate(1955, 1, 24),
    QDate(1956, 2, 12), QDate(1957, 1, 31), QDate(1958, 2, 18),
    QDate(1959, 2, 8), QDate(1960, 1, 28), QDate(1961, 2, 15),
    QDate(1962, 2, 5), QDate(1963, 1, 25), QDate(1964, 2, 13),
    QDate(1965, 2, 2), QDate(1966, 1, 21), QDate(1967, 2, 9),
    QDate(1968, 1, 30), QDate(1969, 2, 17), QDate(1970, 2, 6),
    QDate(1971, 1, 27), QDate(1972, 2, 15), QDate(1973, 2, 3),
    QDate(1974, 1, 23), QDate(1975, 2, 11), QDate(1976, 1, 31),
    QDate(1977, 2, 18), QDate(1978, 2, 7), QDate(1979, 1, 28),
    QDate(1980, 2, 16), QDate(1981, 2, 5), QDate(1982, 1, 25),
    QDate(1983, 2, 13), QDate(1984, 2, 2), QDate(1985, 2, 20),
    QDate(1986, 2, 9), QDate(1987, 1, 29), QDate(1988, 2, 17),
    QDate(1989, 2, 6), QDate(1990, 1, 27), QDate(1991, 2, 15),
    QDate(1992, 2, 4), QDate(1993, 1, 23), QDate(1994, 2, 10),
    QDate(1995, 1, 31), QDate(1996, 2, 19), QDate(1997, 2, 7),
    QDate(1998, 1, 28), QDate(1999, 2, 16), QDate(2000, 2, 5),
    QDate(2001, 1, 24), QDate(2002, 2, 12), QDate(2003, 2, 1),
    QDate(2004, 1, 22), QDate(2005, 2, 9), QDate(2006, 1, 29),
    QDate(2007, 2, 18), QDate(2008, 2, 7), QDate(2009, 1, 26),
    QDate(2010, 2, 14), QDate(2011, 2, 3), QDate(2012, 1, 23),
    QDate(2013, 2, 10), QDate(2014, 1, 31), QDate(2015, 2, 19),
    QDate(2016, 2, 8), QDate(2017, 1, 28), QDate(2018, 2, 16),
    QDate(2019, 2, 5), QDate(2020, 1, 25), QDate(2021, 2, 12),
    QDate(2022, 2, 1), QDate(2023, 1, 22), QDate(2024, 2, 10),
    QDate(2025, 1, 29), QDate(2026, 2, 17), QDate(2027, 2, 6),
    QDate(2028, 1, 26), QDate(2029, 2, 13), QDate(2030, 2, 3),
    QDate(2031, 1, 23), QDate(2032, 2, 11), QDate(2033, 1, 31),
    QDate(2034, 2, 19), QDate(2035, 2, 8), QDate(2036, 1, 28),
    QDate(2037, 2, 15), QDate(2038, 2, 4), QDate(2039, 2, 24),
    QDate(2040, 2, 12), QDate(2041, 2, 1), QDate(2042, 2, 22),
    QDate(2043, 2, 10),
};

QDate CalendarFunctions::tableLookUp(size_t year)
{
    size_t size =
        sizeof knownDatesTable / sizeof knownDatesTable[0];
    for (size_t i = 0; i < size; i++) {
        if (size_t(knownDatesTable[i].year()) == year)
            return knownDatesTable[i];
    }
    return QDate(0, 0, 0);
}
