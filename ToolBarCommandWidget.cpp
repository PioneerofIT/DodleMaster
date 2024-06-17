
#include "ToolBarCommandWidget.h"
#include <qmessagebox.h>
#include "Chain_Of_Responsibility/ChangeFigureCommandRequest.h"
#include "Observer/ChangeManager.h"


ToolBarCommandWidget::ToolBarCommandWidget(QWidget *parent, Chain *chain)
	:QWidget(parent), Chain(chain) {

	ui.setupUi(this);

	connect(ui.undoButton, &QPushButton::clicked, this, &ToolBarCommandWidget::undoButtonClicked);
	connect(ui.redoButton, &QPushButton::clicked, this, &ToolBarCommandWidget::redoButtonClicked);
	connect(ui.alleraseButton, &QPushButton::clicked, this, &ToolBarCommandWidget::alleraseButtonClicked);

	ChangeManager::getInstance()->registerObserve(this);
}


void ToolBarCommandWidget::undoButtonClicked() {

	ChangeFigureCommandRequest request(ChangeFigureCommandRequest::ChangeUndoMode);

	this->request(&request);

}

void ToolBarCommandWidget::redoButtonClicked() {

	ChangeFigureCommandRequest request(ChangeFigureCommandRequest::ChangeRedoMode);

	this->request(&request);

}

void ToolBarCommandWidget::alleraseButtonClicked() {

	ChangeFigureCommandRequest request(ChangeFigureCommandRequest::ChangeAllEraseMode);

	this->request(&request);

}

ToolBarCommandWidget::~ToolBarCommandWidget() {


}

#include "Observer/UndoRedoStackCountChangedEvent.h"

void ToolBarCommandWidget::update(NotifyEvent *notifyEvent) {


	if (dynamic_cast<UndoRedoStackCountChangedEvent*>(notifyEvent)) {

		if (dynamic_cast<UndoRedoStackCountChangedEvent*>(notifyEvent)->getUndoStackCount() == 0) {
			ui.undoButton->setEnabled(false);
		}
		else {
			ui.undoButton->setEnabled(true);
		}
		if (dynamic_cast<UndoRedoStackCountChangedEvent*>(notifyEvent)->getRedoStackCount() == 0) {
			ui.redoButton->setEnabled(false);
		}
		else {
			ui.redoButton->setEnabled(true);
		}
	}
}

