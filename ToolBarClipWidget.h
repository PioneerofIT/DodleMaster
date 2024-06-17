#pragma once

#ifndef _TOOLBARCLIPWIDGET_H
#define _TOOLBARCLIPWIDGET_H

#include <qwidget.h>
#include <QObject>
#include "ui_ToolBarClipWidget.h"
#include "Chain_Of_Responsibility/Chain.h"
#include "Observer/Observer.h"

class ToolBarClipWidget : public QWidget, public Chain, public Observer {

	Q_OBJECT

private:
	Ui::ToolBarClipWidget ui;


public:
	ToolBarClipWidget(QWidget *parent = nullptr, Chain *chain = nullptr);
	~ToolBarClipWidget();


	virtual void update(NotifyEvent *notifyEvent);


	private slots:
	void cutButtonClicked();
	void copyButtonClicked();
	void pasteButtonClicked();

};

#endif //_TOOLBARCLIPWIDGET_H