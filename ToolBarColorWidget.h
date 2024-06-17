#pragma once

#ifndef _TOOLBARCOLORWIDGET_H
#define _TOOLBARCOLORWIDGET_H

#include <qwidget.h>
#include <QObject>
#include "ui_ToolBarColorWidget.h"
#include "Chain_Of_Responsibility/Chain.h"
#include "Observer/Observer.h"

class ToolBarColorWidget : public QWidget, public Chain, public Observer {

	Q_OBJECT

private:
	Ui::ToolBarColorWidget ui;


public:
	ToolBarColorWidget(QWidget *parent = nullptr, Chain *chain = nullptr);
	~ToolBarColorWidget();
	

	virtual void update(NotifyEvent *notifyEvent);


	private slots:
	void redButtonClicked();
	void yellowButtonClicked();
	void blueButtonClicked();
	void dialogButtonClicked();

};

#endif //_TOOLBARCOLORWIDGET_H