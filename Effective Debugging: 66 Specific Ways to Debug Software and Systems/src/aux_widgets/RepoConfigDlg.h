#ifndef REPOCONFIGDLG_H
#define REPOCONFIGDLG_H

#include <QDialog>
#include <QMap>

class GitBase;
class QGridLayout;
class QLineEdit;

namespace Ui
{
class RepoConfigDlg;
}


/**
 * @brief This is a re-implementation of the QDialog. @#
 *
 * @class RepoConfigDlg RepoConfigDlg.h "RepoConfigDlg.h"
 */
class RepoConfigDlg : public QDialog
{
   Q_OBJECT

public:

    /**
     * @brief Default constructor of the class. @#
     *
     * @param git Object to perform the git branch operations.
     * @param parent The parent widget if needed.
     */
   explicit RepoConfigDlg(const QSharedPointer<GitBase> &git, QWidget *parent = nullptr);

    /**
     * @brief Default destructor. @#
     */
    ~RepoConfigDlg();

private:
   Ui::RepoConfigDlg *ui = nullptr;
   QSharedPointer<GitBase> mGit;
   QMap<QLineEdit *, QString> mLineeditKeyMap;

   /**
    * @brief Adds user config information to the layout based on local data @#
    *
    * @param elements Content elements of local config resulting from the "git config --local --list" command
    * @param layout Layout, to which contents from config are added
    */
   void addUserConfig(const QStringList &elements, QGridLayout *layout);

   /**
    * @brief The program updates user config data based on changes in widgets @#
    */
   void setConfig();

   /**
    * @brief User-specific non-essential (cached) data are removed @#
    */
   void clearCache();

   /**
    * @brief In the path for the cache the size in kilobytes is calculated and displayed in QLabel @#
    */
   void calculateCacheSize();

   /**
    * @brief Build system view is toggled (can be enabled or disabled) for user, token and url. @#
    */
   void toggleBsAccesInfo();
};

#endif // REPOCONFIGDLG_H
