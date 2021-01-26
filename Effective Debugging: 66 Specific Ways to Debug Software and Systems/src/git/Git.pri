INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/AGitProcess.h \
    $$PWD/GitAsyncProcess.h \
    $$PWD/GitBase.h \
    $$PWD/GitBranches.h \
    $$PWD/GitCloneProcess.h \
    $$PWD/GitConfig.h \
    $$PWD/GitExecResult.h \
    $$PWD/GitHistory.h \
    $$PWD/GitLocal.h \
    $$PWD/GitMerge.h \
    $$PWD/GitPatches.h \
    $$PWD/GitRemote.h \
    $$PWD/GitRepoLoader.h \
    $$PWD/GitRequestorProcess.h \
    $$PWD/GitStashes.h \
    $$PWD/GitSubmodules.h \
    $$PWD/GitSyncProcess.h \
    $$PWD/GitTags.h

SOURCES += \
    $$PWD/AGitProcess.cpp \
    $$PWD/GitAsyncProcess.cpp \
    $$PWD/GitBase.cpp \
    $$PWD/GitBranches.cpp \
    $$PWD/GitCloneProcess.cpp \
    $$PWD/GitConfig.cpp \
    $$PWD/GitExecResult.cpp \
    $$PWD/GitHistory.cpp \
    $$PWD/GitLocal.cpp \
    $$PWD/GitMerge.cpp \
    $$PWD/GitPatches.cpp \
    $$PWD/GitRemote.cpp \
    $$PWD/GitRepoLoader.cpp \
    $$PWD/GitRequestorProcess.cpp \
    $$PWD/GitStashes.cpp \
    $$PWD/GitSubmodules.cpp \
    $$PWD/GitSyncProcess.cpp \
    $$PWD/GitTags.cpp

test {
    message(Configuring test build...)

    TEMPLATE = app
    TARGET = GitQlientTests

    QT += testlib

    HEADERS += \
        $$PWD/tests/TestAGitProcess.h

    SOURCES += \
        $$PWD/tests/TestAGitProcess.cpp
}
