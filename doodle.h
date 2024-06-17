
#ifndef DOODLE_H
#define DOODLE_H

#include <QtWidgets/QMainWindow>
#include "ui_doodle.h"
#include "Chain_Of_Responsibility/Chain.h"
#include "Ui/DrawingWidget.h"

class ToolBarFigureWidget;
class ToolBarColorWidget;
class ToolBarCommandWidget;
class ToolBarClipWidget;
class DrawingWidget;

//Main Instance
class Doodle : public QMainWindow , public Chain
{
	Q_OBJECT
			
private:
	ToolBarFigureWidget *toolBarFigureWidget;
	ToolBarColorWidget *toolBarColorWidget;
	ToolBarCommandWidget *toolBarCommandWidget;
	ToolBarClipWidget *toolBarClipWidget;

public:
	Doodle(QWidget *parent = 0);
	~Doodle();

	virtual void request(Request *request);

signals:
	void write();


protected:

private:
	Ui::Doodle ui;
};

#endif // DOODLE_H
