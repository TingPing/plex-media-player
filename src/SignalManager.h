#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>
#include <QSocketNotifier>
#include <QGuiApplication>

class SignalManager : public QObject
{
  Q_OBJECT

public:
  SignalManager(QGuiApplication* app);
  ~SignalManager() {}

  // Unix signal handlers.
  static void signalHandler(int signal_num);

  int setupHandlers();
  void closeApplication();

public slots:
  // Qt signal handlers.
  void handleSignal();

private:
  static int sigtermFd[2];

  QSocketNotifier* snTerm;
  QGuiApplication* m_app;
};

#endif // SIGNALMANAGER_H
