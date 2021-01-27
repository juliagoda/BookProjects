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

void TestAGitProcess::testExecGitEmpty()
{
    QCOMPARE(execute(""), false);
}

void TestAGitProcess::testExecGitNotProper()
{
    QCOMPARE(execute("badbad"), false);
}

void TestAGitProcess::testExecGitNotProperLong()
{
    QCOMPARE(execute("badbadfafaffsfagasgadgfadgfagesagsagshgrsgeagesghrshwsgeagsegeghershesgefeasghrshshsdgshdfhfehjbfhwejbgfhebgf"), false);
}

void TestAGitProcess::testExecNotGit()
{
    QCOMPARE(execute("ls -l"), false);
}

//QTEST_MAIN(TestAGitProcess)
