#include <IssuesList.h>

#include <IssueItem.h>
#include <IRestApi.h>
#include <GitServerCache.h>

#include <QLabel>
#include <QIcon>

using namespace GitServer;

IssuesList::IssuesList(const QSharedPointer<GitServerCache> &gitServerCache, QWidget *parent)
   : AGitServerItemList(gitServerCache, parent)
{
   mHeaderIconLabel->setPixmap(QIcon(":/icons/issues").pixmap(QSize(15, 15)));
   mHeaderTitle->setText("Issues");

   connect(mGitServerCache.get(), &GitServerCache::issuesReceived, this,
           [this]() { onIssuesReceived(mGitServerCache->getIssues()); });

   onIssuesReceived(mGitServerCache->getIssues());
}

void IssuesList::refreshData()
{
   mGitServerCache->getApi()->requestIssues();
}

void IssuesList::onIssuesReceived(const QVector<Issue> &issues)
{
   QVector<IssueItem *> items;

   for (auto &issue : issues)
   {
      const auto issueItem = new IssueItem(issue);
      connect(issueItem, &IssueItem::selected, this, &AGitServerItemList::selected);
      items.append(issueItem);
   }

   createContent(items);
}
