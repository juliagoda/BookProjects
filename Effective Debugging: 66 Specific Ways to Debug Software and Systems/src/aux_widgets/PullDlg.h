#ifndef PULLDLG_H
#define PULLDLG_H

#include <QDialog>

namespace Ui
{
class PullDlg;
}

class GitBase;

/**
 * @brief This is a re-implementation of the QDialog. @#
 *
 * @class PullDlg PullDlg.h "PullDlg.h"
 */
class PullDlg : public QDialog
{
   Q_OBJECT

signals:
   /*!
    \brief Signal triggered when the user manually forces a refresh of the repository data.
   */
   void signalRepositoryUpdated();
   /*!
    * \brief Signal triggered when trying to pull and a conflict happens.
    */
   void signalPullConflict();

public:
   explicit PullDlg(QSharedPointer<GitBase> git, const QString &text, QWidget *parent = nullptr);
   ~PullDlg() override;

   /**
    * @brief When the user clicks the Ok/Accept button, it triggers the \ref accept method that validates the data and
    * tries to perform the pull action.If it's successfully executed, it will close the dialog. @#
    */
   void accept() override;

private:
   Ui::PullDlg *ui;
   QSharedPointer<GitBase> mGit;
};

#endif // PULLDLG_H
