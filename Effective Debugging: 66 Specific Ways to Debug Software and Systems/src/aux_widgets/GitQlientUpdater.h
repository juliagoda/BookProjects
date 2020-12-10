#pragma once

#include <QObject>

class QNetworkAccessManager;
class QProgressDialog;

/**
 * @brief The GitQlientUpdater class is responsible for notifying you of anything related to updating the entire program @#
 *
 * @class GitQlientUpdater GitQlientUpdater.h "GitQlientUpdater.h"
 */
class GitQlientUpdater : public QObject
{
   Q_OBJECT
signals:

    /**
     * @brief Signal emited when new version of program is available @#
     */
   void newVersionAvailable();

public:

   /**
    * @brief Default constructor of GitQlientUpdater. @#
    *
    * @param parent The parent widget if needed.
    */
   explicit GitQlientUpdater(QObject *parent = nullptr);

   /**
    * @brief Checks if there is a new version of the program through sending a request over the network @#
    */
   void checkNewGitQlientVersion();

   /**
    * @brief Shows a graphic message about the new program version @#
    */
   void showInfoMessage();

private:
   QNetworkAccessManager *mManager = nullptr;
   QProgressDialog *mDownloadLog = nullptr;
   QString mLatestGitQlient;
   QString mChangeLog;
   QString mGitQlientDownloadUrl;

   /**
    * @brief With the help of a network request, it downloads data in JSON format about the new program version. @#
    */
   void processUpdateFile();

   /**
    * @brief With the help of a network request it downloads data in JSON format for Changelog @#
    */
   void processChangeLog();

   /**
    * @brief It's responsible for downloading the new version of the program from the Internet to the appropriate path in the system. @#
    */
   void downloadFile();
};
