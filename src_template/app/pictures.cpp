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

#include "pictures.h"

PicturesHolder::PicturesHolder()
{
    QString path;

    path = QString::fromUtf8(":/images/basis/images/basis/basis-none.png");
    basises.push_back(QPixmap(path));

    path = QString::fromUtf8(":/images/basis/images/basis/basis-unknown.png");
    basises.push_back(QPixmap(path));

    path = QString::fromUtf8(":/images/basis/images/basis/basis-yan.png");
    basises.push_back(QPixmap(path));

    path = QString::fromUtf8(":/images/basis/images/basis/basis-in.png");
    basises.push_back(QPixmap(path));


    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-none.png");
    elements.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-unknown.png");
    elements.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-wood1.png");
    elements.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-fire2.png");
    elements.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-earth3.png");
    elements.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-metal4.png");
    elements.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/elements/images/elements/elements-water5.png");
    elements.push_back(QPixmap(path));


    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-none.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-unknown.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-rat1.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-ox2.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-tiger3.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-rabbit4.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-dragon5.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-snake6.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-horse7.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-goat8.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-monkey9.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-rooster10.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-dog11.png");
    animals.push_back(QPixmap(path));

    path = QString::fromUtf8(
        ":/images/animals/images/animals/animals-pig12.png");
    animals.push_back(QPixmap(path));
}

QPixmap PicturesHolder::basis(BasisIndex index)
{
    return basises[index];
}

QPixmap PicturesHolder::element(ElementIndex index)
{
    return elements[index];
}

QPixmap PicturesHolder::animal(AnimalIndex index)
{
    return animals[index];
}
