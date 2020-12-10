#pragma once

#include <QDialog>

namespace Ui
{
class InitialRepoConfig;
}

class GitBase;


/**
* @brief The InitialRepoConfig class updates information about repo config as maximum commits to retrieve, update submodules when pull, auto-fetch interval and prune when fetch @#
*
* @class InitialRepoConfig InitialRepoConfig.h "InitialRepoConfig.h"
*/
class InitialRepoConfig : public QDialog
{
   Q_OBJECT

public:

    /**
    * @brief Default constructor of InitialRepoConfig, within which the widgets data are updated @#.
    *
    * @param git Object to perform the git branch operations.
    * @param parent The parent widget if needed.
    */
   explicit InitialRepoConfig(const QSharedPointer<GitBase> &git, QWidget *parent = nullptr);

    /**
    * @brief Default destructor of InitialRepoConfig @#.
    */
    ~InitialRepoConfig();

private:
   Ui::InitialRepoConfig *ui;
   QSharedPointer<GitBase> mGit;
};
