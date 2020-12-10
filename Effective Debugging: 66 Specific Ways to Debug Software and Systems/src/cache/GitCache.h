#pragma once

/****************************************************************************************
 ** GitQlient is an application to manage and operate one or several Git repositories. With
 ** GitQlient you will be able to add commits, branches and manage all the options Git provides.
 ** Copyright (C) 2020  Francesc Martinez
 **
 ** LinkedIn: www.linkedin.com/in/cescmm/
 ** Web: www.francescmm.com
 **
 ** This program is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public
 ** License as published by the Free Software Foundation; either
 ** version 2 of the License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public
 ** License along with this library; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 ***************************************************************************************/

#include <RevisionFiles.h>
#include <lanes.h>
#include <CommitInfo.h>

#include <QSharedPointer>
#include <QObject>
#include <QHash>
#include <QMutex>

/**
 * @brief Struct containing information about revision marked as "work in progress".
 * Contains info about commit's number of parent and operation modes (cached and non-cached) @#
 */
struct WipRevisionInfo
{
   QString parentSha;
   QString diffIndex;
   QString diffIndexCached;

   /**
    * @brief Checks if the information about the "work in progress" revision is not empty - if it is correct @#
    *
    * @return True, if the current "work in progress" revision is correct (has non empty values), otherwise False
    */
   bool isValid() const { return !parentSha.isEmpty() || !diffIndex.isEmpty() || !diffIndexCached.isEmpty(); }
};

/**
 * @brief GitCache class as the name suggests applies to data that is stored in the version control system cache for repo @#
 **/
class GitCache : public QObject
{
   Q_OBJECT

signals:

   /**
    * @brief Signal triggered when the cache is updated @#
    */
   void signalCacheUpdated();

public:

   /**
    * @brief Struct containing information about the number of differences in commits
    * between the local branch and the upstream branch. 0 will be returned when the branch
    * has no upstream configuration or if the upstream branch does not exist. @#
    */
   struct LocalBranchDistances
   {
      int aheadMaster = 0;
      int behindMaster = 0;
      int aheadOrigin = 0;
      int behindOrigin = 0;
   };

   /**
    * @brief Default constructor of GitCache @#
    *
    * @param parent The parent widget if needed.
    */
   explicit GitCache(QObject *parent = nullptr);

   /**
    * @brief Destructor. @#
    */
   ~GitCache();

   /**
    * @brief Configures caches for commit elements from local repo and prepares "work in progress" revision information @#
    *
    * @param wipInfo Information on the "work in progress" revision
    * @param commits Commits approved locally by the git commit command
    */
   void setup(const WipRevisionInfo &wipInfo, const QList<CommitInfo> &commits);

   /**
    * @brief Returns number of locally approved commits. @#
    *
    * @return Number of locally approved commits
    */
   int count() const;


   /**
    * @brief Returns an object containing information about the chosen commit based on its sha number. @#
    *
    * @param sha The commit number
    * @return Object containing informations about commit
    */
   CommitInfo getCommitInfo(const QString &sha);

   /**
    * @brief Returns an object containing information about the chosen commit based on its vector index
    * which corresponds to the number of the occurrence in the table. @#
    *
    * @param row The number of vector index containing objects with informations about commits (table row == vector index)
    * @return Object containing informations about commit
    */
   CommitInfo getCommitInfoByRow(int row);

   /**
    * @brief returns a commit position from QHash based on its sha number, which acts as a key. @#
    *
    * @param sha The commit number
    * @return Position of the commit
    */
   int getCommitPos(const QString &sha);

   /**
    * @brief Iterates through commits from the beginning or end. @#
    *
    * @param field Type of commit information (whether we are looking for a sha number, date, author, etc.).
    * @param text The content that should be included in the commit information from the first parameter
    * @param startingPoint Index from which further commits in the commit vector will be checked
    * @param reverse Whether to search for commits from the beginning or from the end
    * @return Object with commit information
    */
   CommitInfo getCommitInfoByField(CommitInfo::Field field, const QString &text, int startingPoint, bool reverse);

   /**
    * @brief Returns revision files that occurred between the first sha number of a given commit and the second sha number of another commit. @#
    *
    * @param sha1 the first limit in the form of sha commit number
    * @param sha2 the second limit in the form of sha commit number
    * @return Revision files
    */
   RevisionFiles getRevisionFile(const QString &sha1, const QString &sha2) const;

   /**
    * @brief Adds revision files between first sha number and second sha number. @#
    *
    * @param sha1 The first limit in the form of sha commit number
    * @param sha2 The second limit in the form of sha commit number
    * @param file The added revision files
    * @return True, if you managed to add revision files, otherwise False
    */
   bool insertRevisionFile(const QString &sha1, const QString &sha2, const RevisionFiles &file);

   /**
    * @brief Adds new reference to vector of references. @#
    *
    * @param sha The commit number
    * @param type Type of commit (whether it's local branch, remote branches, local tag or remote tag)
    * @param reference The name of the added reference
    */
   void insertReference(const QString &sha, References::Type type, const QString &reference);

   /**
    * @brief Inserts new local branch distances to local map variable. @#
    *
    * @param name The name for distances object (key of map)
    * @param distances The informations about distances in local branch (value of map)
    */
   void insertLocalBranchDistances(const QString &name, const LocalBranchDistances &distances);

   /**
    * @brief Returns distances of local branch by its name. @#
    *
    * @param name The name for distances (as a key for searching in map)
    * @return Information on local branch distances (object)
    */
   LocalBranchDistances getLocalBranchDistances(const QString &name) { return mLocalBranchDistances.value(name); }

   /**
    * @brief Updates "work in progress" commit but after processing revisions. @#
    *
    * @param parentSha The previous sha
    * @param diffIndex Compared a tree object with the corresponding tracked files in the working tree, or with the corresponding paths in the index
    * @param diffIndexCache Compared the staged changes with the local repository
    */
   void updateWipCommit(const QString &parentSha, const QString &diffIndex, const QString &diffIndexCache);

   /**
    * @brief Checks if there are any revision files between two sha numbers. @#
    *
    * @param sha1 the first limit in the form of sha commit number
    * @param sha2 the second limit in the form of sha commit number
    * @return True, if there are any revision files, otherwise False
    */
   bool containsRevisionFile(const QString &sha1, const QString &sha2) const;

   /**
    * @brief Parses log file containing differences. @#
    *
    * @param logDiff The content of log file
    * @return Object containing information on revision files
    */
   RevisionFiles parseDiff(const QString &logDiff);

   /**
    * @brief Changes or creates a vector of untracked files, saving them in a local variable. @#
    *
    * @param Vector of untracked files
    */
   void setUntrackedFilesList(const QVector<QString> &untrackedFiles);

   /**
    * @brief Waiting for local changes without taking into account untracked files. @#
    *
    * @return True, if there are some local changes, otherwise False
    */
   bool pendingLocalChanges();

   /**
    * @brief Returns branches according to the type we are interested in (remote, local). @#
    *
    * @param type Type of reference
    * @return Vector with pairs of sha number and its references by type
    */
   QVector<QPair<QString, QStringList>> getBranches(References::Type type);

   /**
    * @brief Returns tags according to the type of tag we are interested in (remote, local). @#
    *
    * @param tagType Type of tag
    * @return Map of commit's references by tag type (key) and its sha number (value)
    */
   QMap<QString, QString> getTags(References::Type tagType) const;

   /**
    * @brief Assigns remote tags to local variable. @#
    *
    * @param map of remote tags
    */
   void updateTags(const QMap<QString, QString> &remoteTags);

private:
   friend class GitRepoLoader;

   QMutex mMutex;
   bool mConfigured = true;
   QVector<CommitInfo *> mCommits;
   QHash<QString, CommitInfo> mCommitsMap;
   QMultiMap<QString, CommitInfo *> mTmpChildsStorage;
   QHash<QPair<QString, QString>, RevisionFiles> mRevisionFilesMap;
   QVector<CommitInfo *> mReferences;
   QMap<QString, LocalBranchDistances> mLocalBranchDistances;
   Lanes mLanes;
   QVector<QString> mDirNames;
   QVector<QString> mFileNames;
   QVector<QString> mUntrackedfiles;
   QMap<QString, QString> mRemoteTags;

   /**
    * @brief Responsible for detecting files and directories in the project path. @#
    */
   struct FileNamesLoader
   {
      FileNamesLoader()
         : rf(nullptr)
      {
      }

      RevisionFiles *rf;
      QVector<int> rfDirs;
      QVector<int> rfNames;
      QVector<QString> files;
   };

   /**
    * @brief Changes the status for the revision configuration to True.
    * Cleared setup for cache means not configured.
    * Without configuration commit's information cannot be inserted to storage
    * "Work in progress" revision can be updated only when configured. @#
    */
   void setConfigurationDone() { mConfigured = true; }

   /**
    * @brief In the commit vector, other information from the first parameter is
    * exchanged for an index from the second parameter. There is also an update
    * for childs storage data. @#
    *
    * @param rev The commit to get the data from.
    * @param orderIdx The index of commits vector, where the swap to another commit will take place
    */
   void insertCommitInfo(CommitInfo rev, int orderIdx);

   /**
    * @brief Inserts a "work in progress" commit. @#
    *
    * @param parentSha The previous sha
    * @param diffIndex Compared a tree object with the corresponding tracked files in the working tree, or with the corresponding paths in the index
    * @param diffIndexCache Compared the staged changes with the local repository
    */
   void insertWipRevision(const QString &parentSha, const QString &diffIndex, const QString &diffIndexCache);

   /**
    * @brief Returns revision files even if they are not tracked. @#
    *
    * @param diffIndex Compared a tree object with the corresponding tracked files in the working tree, or with the corresponding paths in the index
    * @param diffIndexCache Compared the staged changes with the local repository
    * @return Revision files
    */
   RevisionFiles fakeWorkDirRevFile(const QString &diffIndex, const QString &diffIndexCache);

   /**
    * @brief Lanes are calculated basing on commit's informations. @#
    *
    * @param c The commit to get the data from.
    * @return Vector of updated lanes
    */
   QVector<Lane> calculateLanes(const CommitInfo &c);

   /**
    * @brief Parses diff file format. @#
    *
    * @param buf Text data buffer
    * @param fl Loader responsible for detecting files and directories in the project path
    * @param cached Not used
    * @return Revision files
    */
   RevisionFiles parseDiffFormat(const QString &buf, FileNamesLoader &fl, bool cached = false);

   /**
    * @brief Appends file by name to loader of files and directories. @#
    *
    * @param name Name of file
    * @param fl Loader responsible for detecting files and directories in the project path
    */
   void appendFileName(const QString &name, FileNamesLoader &fl);

   /**
    * @brief Vectors of revision files and directories are cleared. There is only list of files. @#
    *
    * @param fl Loader responsible for detecting files and directories in the project path
    */
   void flushFileNames(FileNamesLoader &fl);

   /**
    * @brief Stores extra info with format "orig --> dest (Rxx%)". @#
    *
    * @param rf Revision files
    * @param rowSt Text of a row of parsed diff file
    * @param parNum The number of parent
    * @param fl Loader responsible for detecting files and directories in the project path
    */
   void setExtStatus(RevisionFiles &rf, const QString &rowSt, int parNum, FileNamesLoader &fl);

   /**
    * @brief Looks for commit in vector of commits by information type, text and starting index for searching. @#
    *
    * @param field Type of commit information (whether we are looking for a sha number, date, author, etc.).
    * @param text The content that should be included in the commit information from the first parameter
    * @param startingPoint Index from which further commits in the commit vector will be checked
    * @return Constant iterator indicating the searched commit
    */
   QVector<CommitInfo *>::const_iterator searchCommit(CommitInfo::Field field, const QString &text,
                                                      int startingPoint = 0) const;

   /**
    * @brief Looks for commit in vector of commits by information type, text and starting index for searching in reverse. @#
    *
    * @param field Type of commit information (whether we are looking for a sha number, date, author, etc.).
    * @param text The content that should be included in the commit information from the first parameter
    * @param startingPoint Index from which further commits in the commit vector will be checked
    * @return Constant reversed iterator indicating the searched commit
    */
   QVector<CommitInfo *>::const_reverse_iterator reverseSearchCommit(CommitInfo::Field field, const QString &text,
                                                                     int startingPoint = 0) const;

   /**
    * @brief Resets lanes (after merge, after fork, after branch). @#
    *
    * @param c The commit to get the data from.
    * @param isFork Whether lane indicates at fork
    */
   void resetLanes(const CommitInfo &c, bool isFork);
};
