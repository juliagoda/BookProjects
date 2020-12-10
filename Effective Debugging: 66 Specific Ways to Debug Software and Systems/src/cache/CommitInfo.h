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

#include <QVector>
#include <QStringList>
#include <QDateTime>

#include <Lane.h>
#include <References.h>

/**
 * @brief CommitInfo concerns any information that an existing commit may contain. @#
 */
class CommitInfo
{
public:

    /**
     * @brief The mode indicates each element of the commit @#
     *
     * @enum Field
     */
   enum class Field
   {
      SHA,
      PARENTS_SHA,
      COMMITER,
      AUTHOR,
      DATE,
      SHORT_LOG,
      LONG_LOG
   };

   /**
    * @brief Default constructor. @#
    **/
   CommitInfo() = default;

   /**
    * @brief Constructor who writes in its variables all information about commit @#
    *
    * @param sha The current commit number
    * @param parentSha Parents of specific commit
    * @param boundary Boundary commit
    * @param commiter The person who committed the code
    * @param commitDate Date of commit's publication
    * @param author The person who originally wrote the code
    * @param log The repo's history
    * @param longLog The long version of repo's history
    * @param isSigned Whether the commit was signed with a GPG key
    * @param gpgKey GPG key with which the commit was signed
    */
   explicit CommitInfo(const QString sha, const QStringList &parents, const QChar &boundary, const QString &commiter,
                       const QDateTime &commitDate, const QString &author, const QString &log,
                       const QString &longLog = QString(), bool isSigned = false, const QString &gpgKey = QString());

   /**
    * @brief Operator checking if both instances of CommitInfo class are equal @#
    *
    * @param commit Another instance of CommitInfo class
    * @return True when commits are equal, otherwise False
    **/
   bool operator==(const CommitInfo &commit) const;

   /**
    * @brief Operator checking if both instances of CommitInfo class aren't equal @#
    *
    * @param commit Another instance of CommitInfo class
    * @return True when commits are NOT equal, otherwise False
    **/
   bool operator!=(const CommitInfo &commit) const;

   /**
    * @brief Returns one of the commit information based on enum "Field" @#
    *
    * @param field The type of commit information we want to obtain
    * @return One of the commit information
    */
   QString getFieldStr(CommitInfo::Field field) const;

   /**
    * @brief Changes commit boundary. @#
    *
    * @param info The commit boundary information
    */
   void setBoundary(QChar info) { mBoundaryInfo = std::move(info); }

   /**
    * @brief Whether the commit was marked as boundary. Usually boundary commits are marked with -
    *
    * @return True when commit is marked as boundary commit, otherwise False
    */
   bool isBoundary() const { return mBoundaryInfo == '-'; }

   /**
    * @brief Counts number of parents of current commit from list. @#
    *
    * @return Number of parents of current commit
    */
   int parentsCount() const;

   /**
    * @brief Returns parent of current commit according to the given list index. @#
    *
    * @param idx The list index with commit's parents
    * @return Parent of current commit
    */
   QString parent(int idx) const;

   /**
    * @brief Returns a list with all parents of the commit from local variable. @#
    *
    * @return List of all parents
    */
   QStringList parents() const;

   /**
    * @brief Returns commit number from local variable. @#
    *
    * @return Commit number
    */
   QString sha() const { return mSha; }

   /**
    * @brief Returns commiter of commit from local variable. @#
    *
    * @return commiter
    */
   QString committer() const { return mCommitter; }

   /**
    * @brief Returns author of commit from local variable. @#
    *
    * @return Author's name
    */
   QString author() const { return mAuthor; }

   /**
    * @brief Returns author date of commit (author date notes when this commit was originally made) @#
    *
    * @return Author date
    **/
   QString authorDate() const { return QString::number(mCommitDate.toSecsSinceEpoch()); }

   /**
    * @brief Returns log information of commit from local variable. @#
    *
    * @return Log's content
    */
   QString shortLog() const { return mShortLog; }

   /**
    * @brief Returns long log information of commit from local variable. @#
    *
    * @return Enhanced log's content
    */
   QString longLog() const { return mLongLog; }

   /**
    * @brief Returns full log information of commit from a combination of a shortened log and a long one. @#
    *
    * @return Complete log's content
    */
   QString fullLog() const { return QString("%1\n\n%2").arg(mShortLog, mLongLog.trimmed()); }

   /**
    * @brief Whether the sha commit number is correct according to the established scheme with the help of regular expressions @#
    *
    * @return True, when commit number is valis, otherwise False
    */
   bool isValid() const;

   /**
    * @brief Whether the commit number is default. Whether it consists of only zeros. @#
    *
    * @return True, when sha number is default, otherwise False
    */
   bool isWip() const { return mSha == ZERO_SHA; }

   /**
    * @brief Changes lanes. @#
    *
    * @param lanes New lanes
    */
   void setLanes(const QVector<Lane> &lanes) { mLanes = lanes; }

   /**
    * @brief Returns lanes from local variable. @#
    *
    * @return Vector of lanes
    */
   QVector<Lane> getLanes() const { return mLanes; }

   /**
    * @brief Returns lane from vector according to the given vector index. @#
    *
    * @param i The vector index
    * @return Lane
    */
   Lane getLane(int i) const { return mLanes.at(i); }

   /**
    * @brief Counts lanes in vector. @#
    *
    * @return Number of lanes
    */
   int getLanesCount() const { return mLanes.count(); }

   /**
    * @brief Iterates through vector of lanes looking for the first active lane. @#
    *
    * @return Index number of the active lane within lanes vector
    */
   int getActiveLane() const;

   /**
    * @brief Adds to QMap type of reference and reference as value. @#
    *
    * @param type Type of reference (local tag, remote tag, local branch, remote branches)
    * @param reference The name of reference
    */
   void addReference(References::Type type, const QString &reference);

   /**
    * @brief Assigns map of references to local variable of commit. @#
    *
    * @param refs QMap of types of references as keys and references as values
    */
   void addReferences(const References &refs) { mReferences = refs; }

   /**
    * @brief Returns a list of reference names by reference type. @#
    *
    * @param type The reference type (local tag, remote tag, local branch, remote branches)
    * @return List of references names
    */
   QStringList getReferences(References::Type type) const { return mReferences.getReferences(type); }

   /**
    * @brief Cheks whether map of references is empty @#
    *
    * @return True, when there are some references, otherwise False
    */
   bool hasReferences() const { return !mReferences.isEmpty(); }


   /**
    * @brief Adds to map commit children, where its sha is a key and all commit is a value  (newest child is the lastly created commit). @#
    *
    * @param commit The commit being added to map of children
    */
   void addChildReference(CommitInfo *commit) { mChilds.insert(commit->sha(), commit); }

   /**
    * @brief Returns all commits children from local map variable to list. @#
    *
    * @return List of all children commits
    */
   QList<CommitInfo *> getChilds() const { return mChilds.values(); }

   /**
    * @brief Checks whether there is not empty map of children commits. @#
    *
    * @return True, when map of children is not empty, otherwise False
    */
   bool hasChilds() const { return !mChilds.empty(); }

   /**
    * @brief Clears all references from local variable. @#
    */
   void clearReferences() { mReferences.clear(); }


   /**
    * @brief Checks if the commit is signed from local variable @#
    *
    * @return True, if the commit is signed, otherwise False
    */
   bool isSigned() const { return mSigned; }

   /**
    * @brief Returns GPG key from local variable. @#
    *
    * @return GPG Key
    */
   QString getGpgKey() const { return mGpgKey; }

   /**
    * @brief It's not a commit SHA yet, it's just a default value used in the UI @#
    */
   static const QString ZERO_SHA;

   /**
    * @brief Empty tree SHA1 (SHA1 pops up on some GitHub repo when the author wants its first commit to be empty) @#
    */
   static const QString INIT_SHA;

private:
   QChar mBoundaryInfo;
   QString mSha;
   QStringList mParentsSha;
   QString mCommitter;
   QString mAuthor;
   QDateTime mCommitDate;
   QString mShortLog;
   QString mLongLog;
   QString mDiff;
   QVector<Lane> mLanes;
   References mReferences;
   QMap<QString, CommitInfo *> mChilds;
   bool mSigned = false;
   QString mGpgKey;
};
