

#include "ToolBarFigureWidget.h"
#include "Chain_Of_Responsibility/ChangeFigureModeRequest.h"
#include "Observer/ChangeManager.h"
#include "FigureMode/FigureModeType.h"

ToolBarFigureWidget::ToolBarFigureWidget(QWidget *parent, Chain *chain)
	:QWidget(parent), Chain(chain) {

	ui.setupUi(this);	

	connect(ui.lineButton, &QPushButton::clicked, this, &ToolBarFigureWidget::lineButtonClicked);
	connect(ui.circleButton, &QPushButton::clicked, this, &ToolBarFigureWidget::circleButtonClicked);
	connect(ui.polygonButton, &QPushButton::clicked, this, &ToolBarFigureWidget::polygonButtonClicked);
	connect(ui.rectangleButton, &QPushButton::clicked, this, &ToolBarFigureWidget::rectangleButtonClicked);
	connect(ui.triangleButton, &QPushButton::clicked, this, &ToolBarFigureWidget::triangleButtonClicked);
	connect(ui.rhombusButton, &QPushButton::clicked, this, &ToolBarFigureWidget::rhombusButtonClicked);
	connect(ui.parallelogramButton, &QPushButton::clicked, this, &ToolBarFigureWidget::parallelogramButtonClicked);
	connect(ui.cursorButton, &QPushButton::clicked, this, &ToolBarFigureWidget::cursorButtonClicked);

	ChangeManager::getInstance()->registerObserve(this);
}

//void ToolBarFigureWidget::setCurrentFigureModeType(FigureModeType figureModeType) {
//	
//	ui.lineButton->setStyleSheet("");
//	ui.circleButton->setStyleSheet("");
//	ui.polygonButton->setStyleSheet("");
//	ui.rectangleButton->setStyleSheet("");
//	ui.triangleButton->setStyleSheet("");
//	ui.rhombusButton->setStyleSheet("");
//	ui.parallelogramButton->setStyleSheet("");
//	ui.cursorButton->setStyleSheet("");
//
//
//	if (figureModeType == LineModeType) {
//		
//		pressed(ui.lineButton);
//	}
//	else if (figureModeType == CircleModeType) {
//
//		pressed(ui.circleButton);
//	}
//	else if (figureModeType == PolygonModeType) {
//
//		pressed(ui.polygonButton);
//	}
//	else if (figureModeType == RectangleModeType) {
//
//		pressed(ui.rectangleButton);
//	}
//	else if (figureModeType == TriangleModeType) {
//
//		pressed(ui.triangleButton);
//	}
//	else if (figureModeType == RhombusModeType) {
//
//		pressed(ui.rhombusButton);
//	}
//	else if (figureModeType == ParallelogramModeType) {
//
//		pressed(ui.parallelogramButton);
//	}
//
//	else if (figureModeType == CursorModeType) {
//
//		pressed(ui.cursorButton);
//	}
//}
//void ToolBarFigureWidget::pressed(QPushButton *pushbutton) {
//	
//	pushbutton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
//
//}
ToolBarFigureWidget::~ToolBarFigureWidget() {

}

void ToolBarFigureWidget::lineButtonClicked() {

	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeLineMode);

	this->request(&request);
}


void ToolBarFigureWidget::circleButtonClicked() {
	
	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeCircleMode);

	this->request(&request);
}
void ToolBarFigureWidget::polygonButtonClicked() {
	
	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangePolygonMode);

	this->request(&request);

}
void ToolBarFigureWidget::rectangleButtonClicked() {

	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeRectangleMode);

	this->request(&request);
}


void ToolBarFigureWidget::triangleButtonClicked() {

	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeTriangleMode);

	this->request(&request);

}
void ToolBarFigureWidget::rhombusButtonClicked() {

	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeRhombusMode);

	this->request(&request);

}
void ToolBarFigureWidget::parallelogramButtonClicked() {

	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeParallelogramMode);

	this->request(&request);

}
void ToolBarFigureWidget::cursorButtonClicked() {

	ChangeFigureModeRequest request(ChangeFigureModeRequest::ChangeCursorMode);

	this->request(&request);

}

#include "Observer/FigureModeChangedEvent.h"

void ToolBarFigureWidget::update(NotifyEvent *notifyEvent) {

	if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)) {
		
		ui.lineButton->setStyleSheet("");
		ui.circleButton->setStyleSheet("");
		ui.polygonButton->setStyleSheet("");
		ui.rectangleButton->setStyleSheet("");
		ui.triangleButton->setStyleSheet("");
		ui.rhombusButton->setStyleSheet("");
		ui.parallelogramButton->setStyleSheet("");
		ui.cursorButton->setStyleSheet("");

		if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == LineModeType) {
		
			ui.lineButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}
		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == CircleModeType) {
			
			ui.circleButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}
		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == PolygonModeType) {

			ui.polygonButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}
		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == RectangleModeType) {

			ui.rectangleButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}
		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == TriangleModeType) {

			ui.triangleButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}
		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == RhombusModeType) {

			ui.rhombusButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}
		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == ParallelogramModeType) {

			ui.parallelogramButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}

		else if (dynamic_cast<FigureModeChangedEvent*>(notifyEvent)->getFigureModeType() == CursorModeType) {

			ui.cursorButton->setStyleSheet("QPushButton { border: 1px solid black; background-color: white; }");
		}		


	}

}