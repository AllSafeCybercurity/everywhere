/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSCriptTools module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSCRIPTDEBUGGERCOMMANDSCHEDULERFRONTEND_P_H
#define QSCRIPTDEBUGGERCOMMANDSCHEDULERFRONTEND_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qobjectdefs.h>

#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class QScriptDebuggerCommandSchedulerInterface;
class QScriptDebuggerResponseHandlerInterface;
class QScriptDebuggerCommand;
class QScriptDebuggerValue;
class QScriptBreakpointData;

class Q_AUTOTEST_EXPORT QScriptDebuggerCommandSchedulerFrontend
{
public:
    QScriptDebuggerCommandSchedulerFrontend(
        QScriptDebuggerCommandSchedulerInterface *scheduler,
        QScriptDebuggerResponseHandlerInterface *responseHandler);
    ~QScriptDebuggerCommandSchedulerFrontend();

     // execution control
     int scheduleInterrupt();
     int scheduleContinue();
     int scheduleStepInto(int count = 1);
     int scheduleStepOver(int count = 1);
     int scheduleStepOut();
     int scheduleRunToLocation(const QString &fileName, int lineNumber);
     int scheduleRunToLocation(qint64 scriptId, int lineNumber);
     int scheduleForceReturn(int contextIndex, const QScriptDebuggerValue &value);

     // breakpoints
     int scheduleSetBreakpoint(const QString &fileName, int lineNumber);
     int scheduleSetBreakpoint(const QScriptBreakpointData &data);
     int scheduleDeleteBreakpoint(int id);
     int scheduleDeleteAllBreakpoints();
     int scheduleGetBreakpoints();
     int scheduleGetBreakpointData(int id);
     int scheduleSetBreakpointData(int id, const QScriptBreakpointData &data);

     // scripts
     int scheduleGetScripts();
     int scheduleGetScriptData(qint64 id);
     int scheduleScriptsCheckpoint();
     int scheduleGetScriptsDelta();
     int scheduleResolveScript(const QString &fileName);

     // stack
     int scheduleGetBacktrace();
     int scheduleGetContextCount();
     int scheduleGetContextState(int contextIndex);
     int scheduleGetContextInfo(int contextIndex);
     int scheduleGetContextId(int contextIndex);
     int scheduleGetThisObject(int contextIndex);
     int scheduleGetActivationObject(int contextIndex);
     int scheduleGetScopeChain(int contextIndex);
     int scheduleContextsCheckpoint();
     int scheduleGetPropertyExpressionValue(int contextIndex, int lineNumber,
                                            const QStringList &path);
     int scheduleGetCompletions(int contextIndex, const QStringList &path);

     // iteration
     int scheduleNewScriptValueIterator(const QScriptDebuggerValue &object);
     int scheduleGetPropertiesByIterator(int id, int count);
     int scheduleDeleteScriptValueIterator(int id);

     // evaluation
     int scheduleEvaluate(int contextIndex, const QString &program,
                          const QString &fileName = QString(),
                          int lineNumber = 1);

     int scheduleScriptValueToString(const QScriptDebuggerValue &value);
     int scheduleSetScriptValueProperty(const QScriptDebuggerValue &object,
                                        const QString &name,
                                        const QScriptDebuggerValue &value);

     int scheduleClearExceptions();

     int scheduleNewScriptObjectSnapshot();
     int scheduleScriptObjectSnapshotCapture(int id, const QScriptDebuggerValue &object);
     int scheduleDeleteScriptObjectSnapshot(int id);

private:
    int scheduleCommand(const QScriptDebuggerCommand &command);

    QScriptDebuggerCommandSchedulerInterface *m_scheduler;
    QScriptDebuggerResponseHandlerInterface *m_responseHandler;

    Q_DISABLE_COPY(QScriptDebuggerCommandSchedulerFrontend)
};

QT_END_NAMESPACE

#endif
