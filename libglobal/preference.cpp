/*
 * preference.cpp
 * Copyright 2017 - ~, Apin <apin.klas@gmail.com>
 *
 * This file is part of Sultan.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "preference.h"

using namespace LibG;

static Preference *sInstance = nullptr;

Preference::Preference():
    mSetting(new QSettings(QLatin1String("apin"), QLatin1String("Sultan")))
{
}

Preference::~Preference()
{
    if(mSetting)
        delete mSetting;
    mSetting = nullptr;
}

Preference *Preference::instance()
{
    if(sInstance == nullptr)
        sInstance = new Preference();
    return sInstance;
}

void Preference::destroy()
{
    if(sInstance)
        delete sInstance;
    sInstance = nullptr;
}

void Preference::createInstance()
{
    instance();
}

void Preference::setValue(const QString &key, const QVariant &data)
{
    sInstance->mSetting->setValue(key, data);
}

int Preference::getInt(const QString &key, int def)
{
    return sInstance->mSetting->value(key, def).toInt();
}

QString Preference::getString(const QString &key, const QString &def)
{
    return sInstance->mSetting->value(key, def).toString();
}

bool Preference::getBool(const QString &key, bool def)
{
    return sInstance->mSetting->value(key, def).toBool();
}

void Preference::sync()
{
    sInstance->mSetting->sync();
}