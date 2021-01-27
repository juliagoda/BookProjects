#include <QtTest/QtTest>

#include "GitAsyncProcess.h"

class TestAGitProcess : public GitAsyncProcess {
    
Q_OBJECT

public:
    explicit TestAGitProcess(const QString &workingDir);

private slots:
    void testExecGit();
    void testExecGitHelp();
    void testExecGitShowRef();
    void testExecGitConfigList();
    void testExecGitEmpty();
    void testExecGitNotProper();
    void testExecGitNotProperLong();
    void testExecNotGit();
}; 
