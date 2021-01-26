#include "TestAGitProcess.h"

TestAGitProcess::TestAGitProcess(const QString &workingDir) : GitAsyncProcess(workingDir)
{}

void TestAGitProcess::testExecGit()
{
    QCOMPARE(execute("git"), true);
}

void TestAGitProcess::testExecGitHelp()
{
    QCOMPARE(execute("git --help"), true);
}

void TestAGitProcess::testExecGitShowRef()
{
    QCOMPARE(execute("git show-ref -d"), true);
}

void TestAGitProcess::testExecGitConfigList()
{
    QCOMPARE(execute("git config --local --list"), true);
}

//QTEST_MAIN(TestAGitProcess)
