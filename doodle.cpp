
#include "doodle.h"
#include <QCoreApplication>
#include <qdebug.h>
#include <qmessagebox.h>
#include <QKeySequence>
#include <QAction>
#include <QFileDialog>
#include <qtoolbar.h>
#include <qfile.h>
#include "FigureMode/FigureModeType.h"
#include "Command\RemoveAllFigureCommand.h"
#include "Command/AddFigureCommand.h"
#include "ToolBarFigureWidget.h"
#include "ToolBarColorWidget.h"
#include "ToolBarCommandWidget.h"
#include "ToolBarClipWidget.h"
#include "Ui/DrawingWidget.h"
#include "FigureMode/FigureMode.h"

Doodle::Doodle(QWidget *parent)
	: QMainWindow(parent)
{

	this->toolBarFigureWidget = new ToolBarFigureWidget(this, this);
	this->toolBarColorWidget = new ToolBarColorWidget(this, this);
	this->toolBarCommandWidget = new ToolBarCommandWidget(this, this);
	this->toolBarClipWidget = new ToolBarClipWidget(this, this);

	ui.setupUi(this);

	this->setWindowTitle(QString::fromLocal8Bit("제목 없음"));

	//최상위 클래스 ui
	ui.toolBar->setFixedHeight(100);   
	ui.toolBar->addWidget(this->toolBarClipWidget);
	ui.toolBar->addWidget(this->toolBarFigureWidget);
	ui.toolBar->addWidget(this->toolBarColorWidget);
	ui.toolBar->addWidget(this->toolBarCommandWidget);
	
	
	connect(ui.saveMenu, &QAction::triggered, ui.drawingWidget, &DrawingWidget::write);
}



Doodle::~Doodle()
{

}


#include "Chain_Of_Responsibility\ChangeFigureModeRequest.h"
#include "Chain_Of_Responsibility\ChangeFigureColorRequest.h"
#include "Chain_Of_Responsibility\ChangeFigureCommandRequest.h"
#include "Chain_Of_Responsibility\ChangeFigureClipRequest.h"

void Doodle::request(Request *request) {

	//상위 클래스 Request의 요청을 dynamic_cast를 통한 다운캐스팅
	if (dynamic_cast<ChangeFigureModeRequest *>(request)) {


		if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeLineMode) {

			ui.drawingWidget->changeFigureMode(LineModeType);

		} else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeCircleMode) {

			ui.drawingWidget->changeFigureMode(CircleModeType);

		} else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangePolygonMode) {

			ui.drawingWidget->changeFigureMode(PolygonModeType);

		} else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeRectangleMode) {

			ui.drawingWidget->changeFigureMode(RectangleModeType);

		}
		else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeTriangleMode) {

			ui.drawingWidget->changeFigureMode(TriangleModeType);

		}
		else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeRhombusMode) {

			ui.drawingWidget->changeFigureMode(RhombusModeType);

		}
		else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeParallelogramMode) {

			ui.drawingWidget->changeFigureMode(ParallelogramModeType);

		}
		else if (dynamic_cast<ChangeFigureModeRequest*>(request)->getChangeFigureMode() == ChangeFigureModeRequest::ChangeCursorMode) {

			ui.drawingWidget->changeFigureMode(CursorModeType);

		}
		

	}
	else if (dynamic_cast<ChangeFigureColorRequest*>(request)) {

		ChangeFigureColorRequest *colorRequest = dynamic_cast<ChangeFigureColorRequest*>(request);
		
		ui.drawingWidget->changeCurrentColor(colorRequest->getColor());
	}

	else if (dynamic_cast<ChangeFigureCommandRequest*>(request)) {
		if (dynamic_cast<ChangeFigureCommandRequest*>(request)->getChangeFigureCommand() == ChangeFigureCommandRequest::ChangeUndoMode) {

			ui.drawingWidget->undo();
		}
		else if (dynamic_cast<ChangeFigureCommandRequest*>(request)->getChangeFigureCommand() == ChangeFigureCommandRequest::ChangeRedoMode) {

			ui.drawingWidget->redo();
		}
		else if (dynamic_cast<ChangeFigureCommandRequest*>(request)->getChangeFigureCommand() == ChangeFigureCommandRequest::ChangeAllEraseMode) {

			ui.drawingWidget->alldelete();
		}
	}
	else if (dynamic_cast<ChangeFigureClipRequest*>(request)) {
		if (dynamic_cast<ChangeFigureClipRequest*>(request)->getChangeFigureClip() == ChangeFigureClipRequest::ChangeCutMode) {

			ui.drawingWidget->cut();
			
		}
		else if (dynamic_cast<ChangeFigureClipRequest*>(request)->getChangeFigureClip() == ChangeFigureClipRequest::ChangeCopyMode) {

			ui.drawingWidget->copy();
		}
		else if (dynamic_cast<ChangeFigureClipRequest*>(request)->getChangeFigureClip() == ChangeFigureClipRequest::ChangePasteMode) {

			ui.drawingWidget->paste();
		}
	}

}



//void Doodle::closeEvent(QCloseEvent *event) {
	/*
	event->ignore();
	if (this->undoStackSize != this->undostack.size() || this->redoStackSize != this->redostack.size()) {

		QMessageBox *box = new QMessageBox("Doodle", QString::fromLocal8Bit("변경 내용을 %1에 저장하시겠습니까?").arg(this->windowTitle()), QMessageBox::NoIcon, QMessageBox::Save, QMessageBox::Discard, QMessageBox::Cancel);
		box->button(QMessageBox::Save)->setText(QString::fromLocal8Bit("저장(S)"));
		box->button(QMessageBox::Discard)->setText(QString::fromLocal8Bit("저장 안 함(N)"));
		box->button(QMessageBox::Cancel)->setText(QString::fromLocal8Bit("취소"));
	
		int ret = box->exec();
		switch (ret) {
		case QMessageBox::Save:
			this->write();
			event->accept();
			break;
		case QMessageBox::Discard:
			event->accept();
			break;
		case QMessageBox::Cancel:
			
			break;
		default:
			event->accept();
			break;
		}
	}
	else {
		event->accept();
	}
	*/

//}



