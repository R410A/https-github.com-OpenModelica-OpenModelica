#ifndef TRACEABILITYINFORMATIONURI_H
#define TRACEABILITYINFORMATIONURI_H

#include <QtGlobal>
#include <QObject>
#include <QtWidgets>
#include <QNetworkReply>


class Label;
class TraceabilityInformationURI : public QObject
{
  Q_OBJECT
public:
  TraceabilityInformationURI(QObject *pParent = 0);
  void translateURIToJsonMessageFormat(QString modelingActivity, QString toolURI, QString activityURI, QString agentURI, QString sourceModelFileNameURI, QString fmuFileNameURI, QString entityType, QString path, QString gitHash);
  void translateModelCreationURIToJsonMessageFormat(QString modelingActivity, QString toolURI, QString activityURI, QString agentURI, QString fileNameURI, QString entityType, QString path, QString gitHash);
private:
  void sendTraceabilityInformation(QString jsonMessageFormat);
private slots:
  void traceabilityInformationSent(QNetworkReply *pNetworkReply);
};

#endif // TRACEABILITYINFORMATIONURI_H
