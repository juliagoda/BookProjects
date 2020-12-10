#pragma once

#include <QFrame>

class GitCache;
class GitBase;
class QPushButton;
class QToolButton;
class QMenu;

/**
 * @brief The class is a smaller part of the BranchesWidget class, which contains
 * the most important information about the repository @#
 *
 **/
class BranchesWidgetMinimal : public QFrame
{
   Q_OBJECT
signals:

   /**
   * @brief Signal triggered when when the user clicks on the arrow button to
   * see more information about the repository (the part on the right side containing information about stashes etc.). @#
   **/
   void showFullBranchesView();

   /**
   * @brief Signal triggered when when the user clicks on the selected commit in the repository history. @#
   *
   * @param sha The number of the selected commit.
   **/
   void commitSelected(const QString &sha);

   /**
   * @brief Signal triggered when the user clicks on chosen stash. @#
   *
   * @param stashId The stash name.
   **/
   void stashSelected(const QString &stashId);

public:

   /**
    * @brief Default constructor. @#
    *
    * @param cache The GitQlient cache for the current repository.
    * @param git The Git object to execute git commands.
    * @param parent The parent widget if needed.
    **/
   explicit BranchesWidgetMinimal(const QSharedPointer<GitCache> &cache, const QSharedPointer<GitBase> git,
                                  QWidget *parent = nullptr);

   /**
    * @brief Creates a menu in the first section for Local, where you can find information about branches and actions . @#
    *
    * @param sha The number of the selected commit.
    * @param branch The name of branch.
    **/
   void configureLocalMenu(const QString &sha, const QString &branch);

   /**
    * @brief Creates a menu in the section "Remote", where you can find information about remotes. @#
    *
    * @param sha The number of the selected commit.
    * @param branch The name of branch.
    **/
   void configureRemoteMenu(const QString &sha, const QString &branch);

   /**
    * @brief Creates a menu in the section for "Tags", where you can find information about previously created tags. @#
    *
    * @param sha The number of the selected commit.
    * @param tag The name of tag.
    **/
   void configureTagsMenu(const QString &sha, const QString &tag);

   /**
    * @brief Creates a menu in the section for "Stashes", where you can find information about stashes. @#
    *
    * @param stashId The number of the selected stash.
    * @param name The name of stash.
    **/
   void configureStashesMenu(const QString &stashId, const QString &name);

   /**
    * @brief Creates a menu in the section for "Submodules", where you can find information about submodules. @#
    *
    * @param sha The number of the selected commit.
    * @param name The name of selected submodule.
    **/
   void configureSubmodulesMenu(const QString &name);

   /**
    * @brief Clears the displayed menu information about branches, remotes, tags, stashes and submodules. @#
    **/
   void clearActions();

private:
   QSharedPointer<GitBase> mGit;
   QSharedPointer<GitCache> mCache;
   QPushButton *mBack = nullptr;
   QToolButton *mLocal = nullptr;
   QMenu *mLocalMenu = nullptr;
   QToolButton *mRemote = nullptr;
   QMenu *mRemoteMenu = nullptr;
   QToolButton *mTags = nullptr;
   QMenu *mTagsMenu = nullptr;
   QToolButton *mStashes = nullptr;
   QMenu *mStashesMenu = nullptr;
   QToolButton *mSubmodules = nullptr;
   QMenu *mSubmodulesMenu = nullptr;
   QMenu *mCurrentMenuShown = nullptr;

   /**
    * @brief Event, detecting the position of the window and moving it relative to the X axis. @#
    *
    * @param obj Object concerned by the event.
    * @param event Type of event detected.
    **/
   bool eventFilter(QObject *obj, QEvent *event);

   /**
    * @brief Adds item to the indicated menu based on commit number and name. @#
    *
    * @param sha The number of the added commit.
    * @param name The name of item.
    * @param menu Menu to which the item is assigned.
    **/
   void addActionToMenu(const QString &sha, const QString &name, QMenu *menu);
};
