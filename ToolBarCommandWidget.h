#pragma once


#ifndef _TOOLBARCOMMANDWIDGET_H
#define _TOOLBARCOMMANDWIDGET_H

#include <qwidget.h>
#include <QObject>
#include "ui_ToolBarCommandWidget.h"
#include "Chain_Of_Responsibility/Chain.h"
#include "Observer/Observer.h"

class ToolBarCommandWidget : public QWidget, public Chain, public Observer {

	Q_OBJECT

private:
	Ui::ToolBarCommandWidget ui;
	

public:
	ToolBarCommandWidget(QWidget *parent = nullptr, Chain *chain = nullptr);
	~ToolBarCommandWidget();

	virtual void update(NotifyEvent *notifyEvent);

private slots:
	void undoButtonClicked();
	void redoButtonClicked();
	void alleraseButtonClicked();

};

#endif //_TOOLBARCOMMANDWIDGET_H