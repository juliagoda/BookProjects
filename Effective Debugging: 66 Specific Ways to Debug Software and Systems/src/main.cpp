#include <QApplication>
#include <QFontDatabase>
#include <QIcon>
#include <QTimer>
#include <QtTest>

#include <GitQlient.h>
#include <GitQlientSettings.h>

#include <QLogger.h>

#include "tests/TestAGitProcess.h"

using namespace QLogger;

int main(int argc, char *argv[])
{
    int status = 0;

       auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
         status |= QTest::qExec(obj, argc, argv);
         delete obj;
       };

   ASSERT_TEST(new TestAGitProcess(QString("yourProjectPath")));

   qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");

   QApplication app(argc, argv);
   QStringList arguments;

   auto argNum = argc;

   while (argNum--)
      arguments.prepend(QString::fromUtf8(argv[argNum]));

   QApplication::setOrganizationName("CescSoftware");
   QApplication::setOrganizationDomain("francescmm.com");
   QApplication::setApplicationName("GitQlient");
   QApplication::setWindowIcon(QIcon(":/icons/GitQlientLogoIco"));

   QFontDatabase::addApplicationFont(":/DejaVuSans");
   QFontDatabase::addApplicationFont(":/DejaVuSansMono");

   GitQlientSettings settings;
   settings.setGlobalValue("isGitQlient", true);

   GitQlient mainWin(arguments);

   mainWin.show();

   QTimer::singleShot(500, &mainWin, &GitQlient::restorePinnedRepos);

   const auto ret = app.exec();

   return ret;
}
