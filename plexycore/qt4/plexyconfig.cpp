/*******************************************************************************
* This file is part of PlexyDesk.
*  Maintained by : Siraj Razick <siraj@kde.org>
*  Authored By  :
*
*  PlexyDesk is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  PlexyDesk is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with PlexyDesk. If not, see <http://www.gnu.org/licenses/lgpl.html>
*******************************************************************************/
#include "plexyconfig.h"
#include <desktopwidget.h>

namespace PlexyDesk
{
Config * Config::config = 0;

Config * Config::getInstance()
{
    if (config == 0) {
        return  new Config("plexydesk", QSettings::NativeFormat, 0);
    } else {
        return config;
    }
}

Config::Config(const QString & fileName, Format format, QObject * parent ): QSettings(fileName, format, parent)
{
write();
read();
}

void Config::write () 
{
    setValue("proxyOn",false);
    setValue("proxyURL","");
    setValue("proxyUser","");
    setValue("ProxyPasswd","");
    setValue("proxyPort",3128);
    setValue("CurrentWallpaper", DesktopWidget::applicationDirPath() + "/share/plexy/skins/default/default.png");
    setValue("collitionOn",false);
}
void Config::read()
{
    proxyOn=false;
    proxyURL="";
    proxyUser="";
    proxyPasswd="";
    proxyPort=3128;
    CurrentWallpaper =  DesktopWidget::applicationDirPath() + "/share/plexy/skins/default/default.png";
    //collitions detection
    collitionOn = false;
}

}

#include "plexyconfig.moc"
