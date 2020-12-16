
# Theme debug

## When

After change of theme and application exit

## Message

Podproces zatrzymany, ponieważ otrzymał on sygnał z systemu operacyjnego.

Nazwa sygnału: 
SIG32
Znaczenie sygnału: 
Real-time event 32


## Debug's message

```
[31920:31920:1210/022632.025370:ERROR:sandbox_linux.cc(374)] InitializeSandbox() called with multiple threads in process gpu-process.
[31920:31920:1210/022635.357602:ERROR:shared_context_state.cc(74)] Skia shader compilation error
------------------------

Errors:

[31920:31920:1210/022635.520868:ERROR:shared_context_state.cc(74)] Skia shader compilation error
------------------------

Errors:

[31920:31920:1210/022638.906644:ERROR:shared_context_state.cc(74)] Skia shader compilation error
------------------------

Errors:

[31920:31920:1210/022638.919313:ERROR:shared_context_state.cc(74)] Skia shader compilation error
------------------------

Errors:

```

1 pselect        0x7ffff667fc96 
2 ??             0x7ffff0972524 
3 ??             0x7ffff09738a9 
4 start_thread   0x7ffff6a973e9 
5 clone          0x7ffff6688293 



# Pinning debug

## When

After choosing "Pin" by right click on mouse on main page


# Window's message

```
Podproces zatrzymany, ponieważ otrzymał on sygnał z systemu operacyjnego.

Nazwa sygnału: 
SIGSEGV
Znaczenie sygnału: 
Segmentation fault
```


1  QString::QString                                                                                                                                                            qstring.h              1093 0x4415d0       
2  GitQlientRepo::currentDir                                                                                                                                                   GitQlientRepo.h        118  0x46e171       
3  GitQlient::closeTab                                                                                                                                                         GitQlient.cpp          247  0x46d7d0       
4  QtPrivate::FunctorCall<QtPrivate::IndexesList<0>, QtPrivate::List<int>, void, void (GitQlient:: *)(int)>::call                                                              qobjectdefs_impl.h     152  0x46f7a1       
5  QtPrivate::FunctionPointer<void (GitQlient:: *)(int)>::call<QtPrivate::List<int>, void>                                                                                     qobjectdefs_impl.h     185  0x46f435       
6  QtPrivate::QSlotObject<void (GitQlient:: *)(int), QtPrivate::List<int>, void>::impl                                                                                         qobjectdefs_impl.h     418  0x46edb7       
7  ??                                                                                                                                                                                                      0x7ffff6e24dd6 
8  QTabWidget::tabCloseRequested(int)                                                                                                                                                                      0x7ffff7c0bb42 
9  ??                                                                                                                                                                                                      0x7ffff6e24e10 
10 QTabBar::tabCloseRequested(int)                                                                                                                                                                         0x7ffff7beaf02 
11 operator()                                                                                                                                                                  QPinnableTabWidget.cpp 248  0x58ca7e       
12 QtPrivate::FunctorCall<QtPrivate::IndexesList<>, QtPrivate::List<>, void, QPinnableTabWidget::unpinTab()::<lambda()>>::call(struct {...} &, void * *)                       qobjectdefs_impl.h     146  0x58d1af       
13 QtPrivate::Functor<QPinnableTabWidget::unpinTab()::<lambda()>, 0>::call<QtPrivate::List<>, void>(struct {...} &, void *, void * *)                                          qobjectdefs_impl.h     256  0x58d129       
14 QtPrivate::QFunctorSlotObject<QPinnableTabWidget::unpinTab()::<lambda()>, 0, QtPrivate::List<>, void>::impl(int, QtPrivate::QSlotObjectBase *, QObject *, void * *, bool *) qobjectdefs_impl.h     443  0x58d0ce       
15 ??                                                                                                                                                                                                      0x7ffff6e24dd6 
16 QAbstractButton::clicked(bool)                                                                                                                                                                          0x7ffff7b28d53 
17 ??                                                                                                                                                                                                      0x7ffff7b296dc 
18 ??                                                                                                                                                                                                      0x7ffff7b2b083 
19 QAbstractButton::mouseReleaseEvent(QMouseEvent *)                                                                                                                                                       0x7ffff7b2b263 
20 QWidget::event(QEvent *)                                                                                                                                                                                0x7ffff7a78b0e 
21 QApplicationPrivate::notify_helper(QObject *, QEvent *)                                                                                                                                                 0x7ffff7a37752 
22 QApplication::notify(QObject *, QEvent *)                                                                                                                                                               0x7ffff7a3e87b 
23 QCoreApplication::notifyInternal2(QObject *, QEvent *)                                                                                                                                                  0x7ffff6deda7a 
24 QApplicationPrivate::sendMouseEvent(QWidget *, QMouseEvent *, QWidget *, QWidget *, QWidget * *, QPointer<QWidget>&, bool, bool)                                                                        0x7ffff7a3d87e 
25 ??                                                                                                                                                                                                      0x7ffff7a91249 
26 ??                                                                                                                                                                                                      0x7ffff7a9463f 
27 QApplicationPrivate::notify_helper(QObject *, QEvent *)                                                                                                                                                 0x7ffff7a37752 
28 QCoreApplication::notifyInternal2(QObject *, QEvent *)                                                                                                                                                  0x7ffff6deda7a 
29 QGuiApplicationPrivate::processMouseEvent(QWindowSystemInterfacePrivate::MouseEvent *)                                                                                                                  0x7ffff7349594 
30 QWindowSystemInterface::sendWindowSystemEvents(QFlags<QEventLoop::ProcessEventsFlag>)                                                                                                                   0x7ffff731ebb5 
31 ??                                                                                                                                                                                                      0x7ffff318c16c 
32 g_main_context_dispatch                                                                                                                                                                                 0x7ffff5893914 
33 ??                                                                                                                                                                                                      0x7ffff58e77d1 
34 g_main_context_iteration                                                                                                                                                                                0x7ffff5892121 
35 QEventDispatcherGlib::processEvents(QFlags<QEventLoop::ProcessEventsFlag>)                                                                                                                              0x7ffff6e466e1 
36 QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>)                                                                                                                                                 0x7ffff6dec3fc 
37 QCoreApplication::exec()                                                                                                                                                                                0x7ffff6df4894 
38 main                                                                                                                                                                        main.cpp               42   0x44128a       
