

#ifndef _TOOLBARFIGUREWIDGET_H
#define _TOOLBARFIGUREWIDGET_H

#include <qwidget.h>
#include <QObject>
#include "ui_ToolBarFigureWidget.h"
#include "FigureMode/FigureModeType.h"
#include "Chain_Of_Responsibility/Chain.h"
#include "Observer/Observer.h"

class ToolBarFigureWidget : public QWidget , public Chain, public Observer
{

	Q_OBJECT

private:
	Ui::ToolBarFigureWidget ui;
	

public:
	ToolBarFigureWidget(QWidget *parent = nullptr, Chain *chain = nullptr);
	~ToolBarFigureWidget();
	virtual void update(NotifyEvent *notifyEvent);

private slots:
	void lineButtonClicked();
	void circleButtonClicked();
	void polygonButtonClicked();
	void rectangleButtonClicked();
	void triangleButtonClicked();
	void rhombusButtonClicked();
	void parallelogramButtonClicked();
	void cursorButtonClicked();
};

#endif //_TOOLBARFIGUREWIDGET_H