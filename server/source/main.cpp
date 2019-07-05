/**
 * @brief SCD Image Server, Main - https://github.com/sc-develop/scd-imgserver
 *
 *        SCD Image sever is a TCP server for fast downoad/upload image or binary files
 *
 * @author Ing. Salvatore Cerami - dev.salvatore.cerami@gmail.com
 *
 * @copyright (c) 2019 (MIT) Ing. Salvatore Cerami - dev.salvatore.cerami@gmail.com - https://github.com/sc-develop/
 *
 */
#include <QCoreApplication>
#include "scdimgserver.h"
#include <QSettings>

#define  echo QTextStream(stderr) <<

/**
 * @brief main server main function
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   echo "SC-Develop Image Server v1.0\n";
   echo "Copyright (c) 2019 (MIT) Ing. Salvatore Cerami - dev.salvatore.cerami@gmail.com\n";
   echo "https://github.com/sc-develop - git.sc.develop@gmail.com\n\n";

   QString appPath = a.applicationDirPath();

   QSettings cfg(appPath + "/config.cfg",QSettings::IniFormat);

   int port = cfg.value("port",12345).toInt();
   QString rootPath = cfg.value("rootpath","./").toString();

   cfg.setValue("port",port);
   cfg.setValue("rootpath",rootPath);

   cfg.sync();

   SCDImgServer srv(0,port,rootPath);

   if (srv.start())
   {
      return a.exec();
   }

   return 0;
}
